/* Copyright 2022 DZTECH <moyi4681@live.cn>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        // Default
		[0] = LAYOUT(
			KC_GRV, KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,  KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
			KC_ESC, KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT, KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL, KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT, MO(2),    KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),
        // Game layer
		[1] = LAYOUT(
			KC_ESC, KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,  KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
			KC_CAPS, KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT, KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL, KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT, MO(2),    KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),
        // Special layer
		[2] = LAYOUT(
			KC_ESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,
		    KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SCRL,  KC_PAUS, QK_BOOT,    KC_PGUP,
			KC_ESC,        RGB_SPI,  RGB_SPD, KC_TRNS,KC_TRNS, DF(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EE_CLR,   KC_PGDN,
		    KC_LSFT,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, DF(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_MPLY,          KC_VOLU,  KC_MUTE,
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0: // Default layer
        rgblight_sethsv(180, 255, 255); // Cyan in HSV
        break;
    case 1: // Game layer
        rgblight_sethsv(0, 255, 255);   // Red in HSV
        break;
    case 2: // Special layer
        rgblight_sethsv(240, 255, 255); // Blue in HSV
        break;
    default:
        rgblight_sethsv(120, 255, 255); // Green in HSV
        break;
    }
    return state;
}
