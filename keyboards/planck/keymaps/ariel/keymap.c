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
  _MOD_L,
  _MOD_R,
//   _NUM,
//   _SYMBL,
//   _NAV,
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
#define MOD_L MO(_MOD_L)
#define MOD_R MO(_MOD_R)

// #define NUMS TT(_NUM)
// #define SYMBL TT(_SYMBL)
// #define NAV MO(_NAV)

#define RS RSFT_T(KC_ENT)
#define LS KC_LSFT

#define SPACE KC_SPC
// #define BR KC_CAPS
// #define BL TT(_NAV)

#define MOD_1 LGUI_T(KC_1)
#define MOD_2 LALT_T(KC_2)
#define MOD_3 LCTL_T(KC_3)
#define MOD_4 LSFT_T(KC_4)

#define MOD_7 RSFT_T(KC_7)
#define MOD_8 RCTL_T(KC_8)
#define MOD_9 RALT_T(KC_9)
#define MOD_0 RGUI_T(KC_0)

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
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_CAPS, XXXXXXX, XXXXXXX, MOD_L,   LOWER,   SPACE,   SPACE,   RAISE,   MOD_R,   XXXXXXX, XXXXXXX, XXXXXXX
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
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [_RAISE] = LAYOUT_planck_grid(
//     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_BSLS, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    KC_GRV,  MOD_1,   MOD_2,   MOD_3,   MOD_4,   KC_5,    KC_6,    MOD_7,   MOD_8,   MOD_9,   MOD_0,   KC_F11,
    _______, KC_BSLS, KC_LBRC, KC_LPRN, KC_MINS, KC_LT,   KC_GT,   KC_EQL,  KC_RPRN, KC_RBRC, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOD_L] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOD_R] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, XXXXXXX, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
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
),

// [_NAV] = LAYOUT_planck_grid(
//     _______, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//     KC_TILD, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
//     _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

// [_NUM] = LAYOUT_planck_grid(
//     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
//     XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_EQL,
//     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______
// ),

// [_SYMBL] = LAYOUT_planck_grid(
//     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,
//     _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_RPRN, KC_UNDS, KC_PLUS, _______,
//     _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX, XXXXXXX, KC_BSLS, KC_LABK, KC_RABK, KC_SLSH, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

// [_SYMBL] = LAYOUT_planck_grid(
//     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// )

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
