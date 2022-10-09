// Copyright 2021 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_spanish.h"
#include "quantum/keymap_extras/keymap_us_international.h"
#include "features/custom_keys.h"

enum layers {
    _CST, // Custom layout
    _LAB, // Labeled layout
    _ESB, // ES layout
    _USB, // US Layout
    _UTL  // Utils layout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CST] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     ES_SLSH,  ES_PLUS, KC_BSPC,    KC_DEL,  KC_PGUP, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,             KC_INS,  KC_PGDN, KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL,  ES_QUOT,  ES_SCLN, KC_ENT,
        KC_LSFT,TG(_UTL), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   ES_MINS,           KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT,  MO(_UTL), KC_APP , KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAB ] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
        ES_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     ES_MINS,  ES_EQL,  KC_BSPC,    KC_DEL,  KC_PGUP, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     ES_LBRC,  ES_RBRC,             KC_INS,  KC_PGDN, KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    ES_BSLS,  ES_QUOT,  ES_SCLN, KC_ENT,
        KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   ES_SLSH,           KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT,  MO(_UTL), KC_APP , KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_ESB ] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
        ES_MORD, ES_1,    ES_2,    ES_3,    ES_4,    ES_5,    ES_6,    ES_7,    ES_8,    ES_9,    ES_0,     ES_QUOT,  ES_IEXL, KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,    ES_Y,    ES_U,    ES_I,    ES_O,    ES_P,     ES_GRV,   ES_PLUS,             KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, ES_A,    ES_S,    ES_D,    ES_F,    ES_G,    ES_H,    ES_J,    ES_K,    ES_L,    ES_NTIL,  ES_ACUT,  ES_CCED, KC_ENT,
        KC_LSFT, ES_LABK, ES_Z,    ES_X,    ES_C,    ES_V,    ES_B,    ES_N,    ES_M,    ES_COMM, ES_DOT,   ES_MINS,           KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT,  MO(_UTL), KC_APP , KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_USB ] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
        ES_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     ES_MINS,  ES_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     ES_LBRC,  ES_RBRC,             KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    ES_SCLN,  ES_QUOT,  ES_BSLS, KC_ENT,
        KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   ES_SLSH,           KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT,  MO(_UTL), KC_APP , KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_UTL ] = LAYOUT_tkl_iso(
        QK_BOOT,          TO(_CST),TO(_LAB),TO(_ESB),TO(_USB),_______, _______, _______, _______,TO(_UTL),  _______,  _______, _______,    KC_KP_7, KC_KP_8, KC_KP_9,
        _______, RGB_TOG, RGB_MOD,RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,  _______,  _______, _______,    KC_KP_4, KC_KP_5, KC_KP_6,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,             KC_KP_1, KC_KP_2, KC_KP_3,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, KC_0,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,           _______,             _______,
        _______, _______, _______,                   _______,                                     _______,  MO(_UTL), _______, _______,    _______, _______, _______
    )

};

const custom_key_t custom_shift_keys[] = {
    // CST keyboard
     // row1
    {ES_GRV, ES_TILD, 1<<_USB},
    {KC_2, ES_AT, 1<<_CST},
    {KC_3, ES_HASH, 1<<_CST},
    {KC_6, ES_CIRC, 1<<_CST},
    {KC_7, ES_AMPR, 1<<_CST},
    {KC_8, ES_ASTR, 1<<_CST},
    {KC_9, ES_LPRN, 1<<_CST},
    {KC_0, ES_RPRN, 1<<_CST},
    {ES_SLSH, ES_QUES, 1<<_CST},
    {ES_PLUS, ES_EQL, 1<<_CST},
    // row2
    {ES_LBRC, ES_LCBR, 1<<_CST},
    {ES_RBRC, ES_RCBR, 1<<_CST},
    // row3
    {ES_QUOT, ES_DQUO, 1<<_CST},
    {ES_SCLN, ES_COLN, 1<<_CST},
    // row4
    {KC_COMM, ES_LABK, 1<<_CST},
    {KC_DOT, ES_RABK, 1<<_CST},

    // LAB keyboard
    // row1
    {ES_GRV, ES_TILD, 1<<_LAB},
    {KC_2, ES_AT, 1<<_LAB},
    {KC_3, ES_HASH, 1<<_LAB},
    {KC_6, ES_CIRC, 1<<_LAB},
    {KC_7, ES_AMPR, 1<<_LAB},
    {KC_8, ES_ASTR, 1<<_LAB},
    {KC_9, ES_LPRN, 1<<_LAB},
    {KC_0, ES_RPRN, 1<<_LAB},
    {ES_EQL, ES_PLUS, 1<<_LAB},
    // row2
    {ES_LBRC, ES_LCBR, 1<<_LAB},
    {ES_RBRC, ES_RCBR, 1<<_LAB},
    // row3
    {ES_SCLN, ES_COLN, 1<<_LAB},
    {ES_QUOT, ES_DQUO, 1<<_LAB},
    {ES_BSLS, ES_PIPE, 1<<_LAB},
    // row4
    {KC_COMM, ES_LABK, 1<<_LAB},
    {KC_DOT, ES_RABK, 1<<_LAB},
    {ES_SLSH, ES_QUES, 1<<_LAB},

    // USB keyboard
    // row1
    {ES_GRV, ES_TILD, 1<<_USB},
    {KC_2, ES_AT, 1<<_USB},
    {KC_3, ES_HASH, 1<<_USB},
    {KC_6, ES_CIRC, 1<<_USB},
    {KC_7, ES_AMPR, 1<<_USB},
    {KC_8, ES_ASTR, 1<<_USB},
    {KC_9, ES_LPRN, 1<<_USB},
    {KC_0, ES_RPRN, 1<<_USB},
    {ES_EQL, ES_PLUS, 1<<_USB},
    // row2
    {ES_LBRC, ES_LCBR, 1<<_USB},
    {ES_RBRC, ES_RCBR, 1<<_USB},
    // row3
    {ES_SCLN, ES_COLN, 1<<_USB},
    {ES_QUOT, ES_DQUO, 1<<_USB},
    {ES_BSLS, ES_PIPE, 1<<_USB},
    // row4
    {KC_COMM, ES_LABK, 1<<_USB},
    {KC_DOT, ES_RABK, 1<<_USB},
    {ES_SLSH, ES_QUES, 1<<_USB},
};

const custom_key_t custom_altgr_keys[] = {
    // LAB keyboard
    // row1
    {ES_GRV, ES_TILD, 1<<_CST},
    {KC_1, ES_IEXL, 1<<_CST},
    {KC_2, ES_AT, 1<<_CST},
    {KC_7, ES_PIPE, 1<<_CST},
    {ES_SLSH, ES_BSLS, 1<<_CST},
    {ES_PLUS, ES_EQL, 1<<_CST},
    // row3
    {ES_QUOT, ES_ACUT, 1<<_CST},
    // row4

    // LAB keyboard
    // row1
    {ES_GRV, ES_TILD, 1<<_LAB},
    {KC_1, ES_IEXL, 1<<_LAB},
    {KC_2, ES_FORD, 1<<_LAB},
    {KC_3, ES_MORD, 1<<_LAB},
    {KC_5, ES_EURO, 1<<_LAB},
    {KC_6, ES_CIRC, 1<<_LAB},
    {KC_7, ES_ASTR, 1<<_LAB},
    {KC_9, ES_QUOT, 1<<_LAB},
    {KC_0, ES_QUOT, 1<<_LAB},
    {ES_EQL, ES_PLUS, 1<<_LAB},
    // row3
    {ES_BSLS, ES_NOT, 1<<_LAB},
    // row4
    {KC_N, ES_NTIL, 1<<_LAB},
    {KC_C, ES_CCED, 1<<_LAB},
    {ES_SLSH, ES_IQUE, 1<<_LAB},

    // USB keyboard
    // row1
    {ES_GRV, ES_TILD, 1<<_USB},
    {KC_1, ES_IEXL, 1<<_USB},
    {KC_2, ES_FORD, 1<<_USB},
    {KC_3, ES_MORD, 1<<_USB},
    {KC_5, ES_EURO, 1<<_USB},
    {KC_6, ES_CIRC, 1<<_USB},
    {KC_7, ES_ASTR, 1<<_USB},
    {KC_9, ES_QUOT, 1<<_USB},
    {KC_0, ES_QUOT, 1<<_USB},
    {ES_EQL, ES_PLUS, 1<<_USB},
    // row3
    {ES_BSLS, ES_NOT, 1<<_USB},
    // row4
    {KC_N, ES_NTIL, 1<<_USB},
    {KC_C, ES_CCED, 1<<_USB},
    {ES_SLSH, ES_IQUE, 1<<_USB},
};

const custom_key_t custom_altgrsh_keys[] = {
    // CST keyboard
    {ES_SLSH, ES_IQUE, 1<<_CST},

};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(*custom_shift_keys);
uint8_t NUM_CUSTOM_ALTGR_KEYS = sizeof(custom_altgr_keys) / sizeof(*custom_altgr_keys);
uint8_t NUM_CUSTOM_ALTGRSH_KEYS = sizeof(custom_altgrsh_keys) / sizeof(*custom_altgrsh_keys);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_altgrsh_keys(keycode, record)) { return false; }
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  if (!process_custom_altgr_keys(keycode, record)) { return false; }
  // Your macros ...
  return true;
}

/* const key_override_t one_key_override =
    ko_make_with_layers(MOD_MASK_CSA, KC_1, KC_4, 1<<_USB);  // Shift 1 is 2

const key_override_t** key_overrides = (const key_override_t*[]){
    &one_key_override,
    NULL
}; */