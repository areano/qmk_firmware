/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _NUM,
  _SYMBL,
  _NAV,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  UNDO,
  COPY,
  CUT,
  PASTE,
  REDO
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define NUMS TT(_NUM)
#define SYMBL TT(_SYMBL)

#define NAV LT(_NAV, KC_SPC)
#define RS RSFT_T(KC_QUOT)
#define LS LSFT_T(KC_GRAVE)
#define RA LALT_T(KC_ENT)
#define LC LCTL_T(KC_ESC)

#define CKC_A LGUI_T(KC_A)
#define CKC_S LALT_T(KC_S)
#define CKC_D LSFT_T(KC_D)
#define CKC_F LCTL_T(KC_F)

#define CKC_J LCTL_T(KC_J)
#define CKC_K LSFT_T(KC_K)
#define CKC_L LALT_T(KC_L)
#define CKC_SCLN LGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GUI  | Alt  | Ctrl |Lower |    Space    |Raise | Ctrl | Alt  |  GUI |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LS,       CKC_A,   CKC_S,   CKC_D,   CKC_F,   KC_G,    KC_H,    CKC_J,   CKC_K,   CKC_L,   CKC_SCLN,RS,
    LC,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RA,
    KC_CAPS,  KC_LGUI, XXXXXXX, KC_LCTL, NUMS,    NAV,     NAV,     SYMBL,   KC_LCTL, XXXXXXX, KC_LGUI, XXXXXXX
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |MACWIN|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLU, KC_VOLD, XXXXXXX, AU_OFF,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MNXT, KC_MPRV, XXXXXXX, XXXXXXX,
    EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_NAV] = LAYOUT_planck_grid(
    _______, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, REDO,    KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, _______,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_DEL,
    _______, UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_EQL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______
),

[_SYMBL] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,
    _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_RPRN, KC_UNDS, KC_PLUS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX, XXXXXXX, KC_BSLS, KC_LABK, KC_RABK, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUM, _SYMBL, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COPY:
        if (record->event.pressed) {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_C);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_C);
        }
        return false;
    case PASTE:
        if (record->event.pressed) {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_V);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_V);
        }
        return false;
    case CUT:
        if (record->event.pressed) {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_X);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_X);
        }
        return false;
        break;
    case UNDO:
        if (record->event.pressed) {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_Z);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_Z);
        }
        return false;
    case REDO:
        if (record->event.pressed) {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_Y);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_Y);
        }
        return false;
  }
  return true;
}

void encoder_update(bool clockwise) {
}

void dip_switch_update_user(uint8_t index, bool active) {
}
