#pragma once
#include "quantum.h"

typedef struct {
  uint16_t keycode;
  uint16_t modified_keycode;
  layer_state_t layers;
} custom_key_t;

static const int MOD_RIGHT_ALT = 64;


extern const custom_key_t custom_shift_keys[];
extern uint8_t NUM_CUSTOM_SHIFT_KEYS;
extern const custom_key_t custom_altgr_keys[];
extern uint8_t NUM_CUSTOM_ALTGR_KEYS;
extern const custom_key_t custom_altgrsh_keys[];
extern uint8_t NUM_CUSTOM_ALTGRSH_KEYS;
bool process_custom_shift_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_altgr_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_altgrsh_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_keys(uint16_t keycode, keyrecord_t *record, uint16_t mod_mask_code, const custom_key_t custom_keys[], uint8_t NUM_CUSTOM_KEYS);
uint16_t check_press(const uint8_t mods, uint16_t mod_mask_code, uint16_t return_mask);