import { BreakpointObserver, Breakpoints, BreakpointState } from '@angular/cdk/layout';
import { Directive, ElementRef, Input, OnInit, Renderer2 } from '@angular/core';

export enum CustomBreakpointStates {
 WebPortrait = 'web-p',
 WebLandscape = 'web-l',
 HandsetPortrait = 'phone-p',
 HandsetLandscape = 'phone-l',
 TabletPortrait = 'tablet-p',
 TabletLandscape = 'tablet-l',
}

/**
 * @usageNotes
 * ```
 *     <element bpFormatter bpElementClass="elementMainClass"> ... </element>
 *
 *     <element bpFormatter bpShow="['web-p', 'phone-p']"> ... </element>
 *
 *     <div bpFormatter [bpIf]="['tablet-l']" #bpElement>
 *       <element *ngIf="bpElement.getAttribute('bpIf')"> ... </element>
 *     </div>
 * ```
 *
 * @description
 *
 * The component with this directive could have multiple css classes with different options for each screen type.
 * This classes must be called with the name provided in "bpElementClass" and the desired CustomBreakpointStates element.
 *
 * If bpElementClass is present, add classes to the element according to the breakpoint and the bpElementClass name given
 * Ex. in web and portrait mode <element bpFormatter bpElementClass="element-class-name">...</element>
 *   the classes added are element-class-name.web-p
 *
 * If bpShow is present, show or hide component bassed on the array of breakpoints. If some element of the array is the actual breakpoint it shows
 *
 * If bpIf is present, bassed on the array of breakpoints, sets "bpIf" attribute to true or empty in the container element to be used as *ngIf variable in child.
 * The container element should be a rendereable element (ng-container is not allowed)
 *
 */

@Directive({
 selector: '[bpFormatter]',
})
export class BreakpointFormatterDirective implements OnInit {
 @Input('bpElementClass')
 bpElementClass!: string;

 private _bpShow!: CustomBreakpointStates[];
 @Input('bpShow')
 public get bpShow(): string[] {
  return this._bpShow;
 }

 public set bpShow(values: string[]) {
  if (
   values.every((value) =>
    Array.from(Object.values(CustomBreakpointStates))
     .map((element) => element.toString())
     .includes(value),
   )
  ) {
   this._bpShow = values as CustomBreakpointStates[];
  }
 }

 _bpIf!: CustomBreakpointStates[];
 @Input('bpIf')
 public get bpIf(): string[] {
  return this._bpIf;
 }

 public set bpIf(values: string[]) {
  if (
   values.every((value) =>
    Array.from(Object.values(CustomBreakpointStates))
     .map((element) => element.toString())
     .includes(value),
   )
  ) {
   this._bpIf = values as CustomBreakpointStates[];
  }
 }

 constructor(private hostElement: ElementRef, private renderer: Renderer2, private responsive: BreakpointObserver) {}

 ngOnInit(): void {
  this.checkInputParams();
  this.responsive.observe(detectableBreakpoints).subscribe((breakpointsList) => {
   const currentBreakpoins = this.filterCurrentBreakpoints(breakpointsList).map((breakpoint) => breakpoint[0]);
   if (this.bpElementClass && this.bpElementClass != '') {
    this.addCssClasses(currentBreakpoins);
   }
   if (this.bpShow) {
    this.showHideElement(currentBreakpoins);
   }
   if (this.bpIf) {
    this.ifOutput(currentBreakpoins);
   }
  });
 }

 private addCssClasses(breakpointsList: string[]): void {
  const actualCustomBreakpoints = this.breakpointsToCustom(breakpointsList);

  Array.from(breakpointClassMap.values()).forEach((key) => {
   this.renderer.removeClass(this.hostElement.nativeElement, `${this.bpElementClass}.${key}`);
  });
  actualCustomBreakpoints.forEach((cssClass) => {
   if (cssClass !== undefined) {
    this.renderer.addClass(this.hostElement.nativeElement, `${this.bpElementClass}.${cssClass}`);
   }
  });
 }

 private showHideElement(breakpointsList: string[]): void {
  const showElement = this.checkVisibility(breakpointsList, this.bpShow) ? '' : 'none';
  this.renderer.setStyle(this.hostElement.nativeElement, 'display', showElement);
 }

 private ifOutput(breakpointsList: string[]): void {
  const showElement = this.checkVisibility(breakpointsList, this.bpIf) ? 'true' : '';
  this.renderer.setAttribute(this.hostElement.nativeElement, 'bpIf', showElement);
 }

 private checkVisibility(actualBreakpointsList: string[], inputBp: string[]): boolean {
  const actualCustomBreakpoints = this.breakpointsToCustom(actualBreakpointsList);

  const inputBreakpoints = inputBp.map((bp) => bp.toString());
  return actualCustomBreakpoints.some((breakpoint) => inputBreakpoints.includes(breakpoint));
 }

 private filterCurrentBreakpoints(breakpointsList: BreakpointState): [string, boolean][] {
  return Object.entries(breakpointsList.breakpoints).filter((breakpoint) => breakpoint[1]);
 }

 private breakpointsToCustom(breakpointsList: string[]): string[] {
  return breakpointsList.map((breakpoint) => breakpointClassMap.get(breakpoint)).filter((item) => item) as string[];
 }

 private checkInputParams() {
  if (this.bpIf && !this.hostElement.nativeElement.tagName) {
   throw new Error('bpFormatter ERROR: HTMLElement not renderable. elements like ng-container doesn\'t admit "bpIf" mode');
  }
 }
}

const breakpointClassMap = new Map<string, string>([
 [Breakpoints.WebPortrait, CustomBreakpointStates.WebPortrait],
 [Breakpoints.WebLandscape, CustomBreakpointStates.WebLandscape],
 [Breakpoints.HandsetPortrait, CustomBreakpointStates.HandsetPortrait],
 [Breakpoints.HandsetLandscape, CustomBreakpointStates.HandsetLandscape],
 [Breakpoints.TabletPortrait, CustomBreakpointStates.TabletPortrait],
 [Breakpoints.TabletLandscape, CustomBreakpointStates.TabletLandscape],
]);

const detectableBreakpoints = [
 Breakpoints.HandsetPortrait,
 Breakpoints.TabletPortrait,
 Breakpoints.WebPortrait,
 Breakpoints.HandsetLandscape,
 Breakpoints.TabletLandscape,
 Breakpoints.WebLandscape,
];
