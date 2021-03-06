#include "tv44.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _DV 1
#define _CM 2
#define _L1 3
#define _L2 4
#define _L3 5

// Macro name shortcuts
#define QWERTY M(_QW)
#define DVORAK M(_DV)
#define COLEMAK M(_CM)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = { /* Qwerty */
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
    {MO(_L1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MO(_L1) },
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2) },
    {KC_LCTL, MO(_L2), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_RALT, KC_ESC,  XXXXXXX, TG(_L3) }
  },
  [_DV] = { /* Dvorak */
    {KC_TAB,  KC_SLSH, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC },
    {MO(_L1), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    MO(_L1) },
    {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    MO(_L2) },
    {KC_LCTL, MO(_L2), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_RALT, KC_ESC,  XXXXXXX, TG(_L3) }
  },
  [_CM] = { /* Colemak */
    {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC },
    {MO(_L1), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MO(_L1) },
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2) },
    {KC_LCTL, MO(_L2), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_RALT, KC_ESC,  XXXXXXX, TG(_L3) }
  },
  [_L1] = { /* LAYER 1 */
    {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL  },
    {_______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, _______ },
    {_______, KC_ESC,  _______, KC_PSCR, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT },
    {_______, KC_LGUI, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______ }
  },
  [_L2] = { /* LAYER 2 */
    {_______, QWERTY,  DVORAK,  COLEMAK, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    _______ },
    {KC_ESC,  KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_4,    KC_5,    KC_6,    KC_VOLU, KC_ENT  },
    {_______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_VOLD, _______ },
    {_______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______ }
  },
  [_L3] = { /* LAYER 3 */
    {_______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______ },
    {KC_ESC,  _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______ },
    {KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______ },
    {_______, KC_LSFT, KC_B,    KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, KC_C,    _______, _______, XXXXXXX, _______ }
  }
};

const uint16_t PROGMEM fn_actions[] = {

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _DV:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_DV);
          }
          break;
        case _QW:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_QW);
          }
          break;
        case _CM:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_CM);
          }
          break;
      }
    return MACRO_NONE;
};
