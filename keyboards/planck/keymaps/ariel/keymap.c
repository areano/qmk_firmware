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
  _LOWER,
  _RAISE,
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

#define RS RSFT_T(KC_ENT)
#define LS KC_LSFT
#define SPACE KC_SPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | GUI  | Alt  | Ctrl |Lower |    Space    |Raise | Ctrl | Alt  | GUI  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LS,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, LOWER,   SPACE,   SPACE,   RAISE,   KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX
),  

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | Ins  |      |      |      |PrtSc |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | GUI  | Alt  | Ctrl | Shift|      |      | Left | Down |  Up  |Right | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy | Paste| Redo |      | Home |Pg Dn |Pg Up | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
    _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  \   |  [   |  (   |   -  |   <  |   >  |   =  |   )  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_BSLS, KC_LBRC, KC_LPRN, KC_MINS, KC_LT,   KC_GT,   KC_EQL,  KC_RPRN, KC_RBRC, _______, _______,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug |      |      |      |      |      |      |      |      |      |Aud on|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |MACWIN|      | Mute | Vol- | Vol+ |      |Audoff|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Play | Prev | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |EepRst|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, AU_OFF,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
    EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
