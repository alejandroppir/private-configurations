#pragma once
#include "quantum.h"

// Estructura para las teclas personalizadas
typedef struct {
  uint16_t keycode;          // Código de la tecla original
  uint16_t modified_keycode; // Código de la tecla modificada
  layer_state_t layers;      // Capas en las que esta tecla es válida
} custom_key_t;

// Definición de MOD_RIGHT_ALT
#define MOD_RIGHT_ALT 64

// Declaraciones externas de las matrices de teclas personalizadas y sus tamaños
extern const custom_key_t custom_shift_keys[];
extern uint8_t NUM_CUSTOM_SHIFT_KEYS;
extern const custom_key_t custom_altgr_keys[];
extern uint8_t NUM_CUSTOM_ALTGR_KEYS;
extern const custom_key_t custom_altgrsh_keys[];
extern uint8_t NUM_CUSTOM_ALTGRSH_KEYS;

// Prototipos de funciones
bool process_custom_shift_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_altgr_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_altgrsh_keys(uint16_t keycode, keyrecord_t *record);
bool process_custom_keys(uint16_t keycode, keyrecord_t *record, uint16_t mod_mask_code,
  const custom_key_t custom_keys[], uint8_t NUM_CUSTOM_KEYS);
uint16_t check_press(const uint8_t mods, uint16_t mod_mask_code, uint16_t return_mask);
