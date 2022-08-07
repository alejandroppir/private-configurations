import { Directive, HostListener, Input, OnInit } from '@angular/core';
import { environment } from 'src/environments/environment';

/**
 * Directive for log component name
 * Ctrl+Shift+Alt+[key]: list all components with the directive for the given key
 * Ctrl+Shift+Alt+Click: log the component clicked
 *
 * Key default N
 *
 *
 * Example: showElementName showElementName="plateLabel" [keyBinding="J"] [showElementMode="both"]
 *
 */
@Directive({
 selector: '[showElementName]',
})
export class ShowElementNameDirective implements OnInit {
 @Input('showElementName')
 elementName!: string;
 @Input('keyBinding')
 keyBinding: string = 'N';
 @Input('nameAlert')
 nameAlert: boolean = false;
 @Input('showElementMode')
 mode: string = ElementLogType.both;

 constructor() {}

 ngOnInit(): void {
  if (environment.production) {
   this.mode = ElementLogType.none;
  }
  this.enableLogMethods();
 }

 private enableLogMethods() {
  switch (this.mode) {
   case ElementLogType.none:
    this.showNameKey = function (): void {};
    this.showNameClick = function (): void {};
    break;
   case ElementLogType.click:
    this.showNameKey = function (): void {};
    break;
   case ElementLogType.key:
    this.showNameClick = function (): void {};
    break;
   default:
    break;
  }
 }

 @HostListener('document:keyup', ['$event'])
 showNameKey(e: KeyboardEvent): void {
  if (e.ctrlKey && e.altKey && e.shiftKey && e.key.toUpperCase() == this.keyBinding.toUpperCase()) {
   this.log();
  }
 }

 @HostListener('click', ['$event'])
 showNameClick(e: MouseEvent): void {
  if (e.ctrlKey && e.altKey && e.shiftKey) {
   this.log();
  }
 }

 log(): void {
  if (this.nameAlert) {
   alert(this.elementName);
  }
  console.log(this.elementName);
 }
}

export enum ElementLogType {
 click = 'click',
 key = 'key',
 both = 'both',
 none = 'none',
}
