#include "custom_keys.h"

// Prototipos de funciones
bool process_custom_keys(uint16_t keycode, keyrecord_t *record, uint16_t mod_mask_code,
  const custom_key_t custom_keys[], uint8_t NUM_CUSTOM_KEYS);

bool process_custom_shift_keys(uint16_t keycode, keyrecord_t *record) {
  return process_custom_keys(keycode, record, MOD_MASK_SHIFT, custom_shift_keys, NUM_CUSTOM_SHIFT_KEYS);
}

bool process_custom_altgr_keys(uint16_t keycode, keyrecord_t *record) {
  return process_custom_keys(keycode, record, MOD_MASK_CA, custom_altgr_keys, NUM_CUSTOM_ALTGR_KEYS);
}

bool process_custom_altgrsh_keys(uint16_t keycode, keyrecord_t *record) {
  return process_custom_keys(keycode, record, MOD_MASK_CSA, custom_altgrsh_keys, NUM_CUSTOM_ALTGRSH_KEYS);
}

bool process_custom_keys(uint16_t keycode, keyrecord_t *record, uint16_t mod_mask_code,
  const custom_key_t custom_keys[], uint8_t NUM_CUSTOM_KEYS) {
  static uint16_t registered_keycode = KC_NO;

  if (registered_keycode != KC_NO) {
    unregister_code16(registered_keycode);
    registered_keycode = KC_NO;
  }

  if (record->event.pressed) {
    const uint8_t mods = get_mods();
    const uint8_t mods_extra = mods | get_weak_mods();

    const uint16_t mods_pressed =
      check_press(mods_extra, (MOD_MASK_CTRL | MOD_RIGHT_ALT), MOD_MASK_CTRL) |
      check_press(mods_extra, MOD_MASK_SHIFT, MOD_MASK_SHIFT) |
      check_press(mods_extra, MOD_MASK_ALT, MOD_MASK_ALT);

    if ((mods_pressed & mod_mask_code) == mod_mask_code) {
      const uint8_t layer = read_source_layers_cache(record->event.key);

      for (int i = 0; i < NUM_CUSTOM_KEYS; ++i) {
        if (keycode == custom_keys[i].keycode && (custom_keys[i].layers & (1 << layer)) != 0) {
          // Manejo de mod tap y layer tap
          if (((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX) ||
              (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX)) &&
              record->tap.count == 0) {
            return true;
          }

          // Eliminar mods
          del_mods(mod_mask_code);
          del_weak_mods(mod_mask_code);
          send_keyboard_report();

          // Registrar la nueva tecla modificada
          registered_keycode = custom_keys[i].modified_keycode;
          register_code16(registered_keycode);
          set_mods(mods);
          return false;
        }
      }
    }
  }

  return true;
}

uint16_t check_press(const uint8_t mods, uint16_t mod_mask_code, uint16_t return_mask) {
  return (mods & mod_mask_code) ? return_mask : 0;
}
