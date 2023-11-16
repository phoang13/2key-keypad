/* Copyright 2021 John Mueller
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_Z,    KC_X
    ),

    [1] = LAYOUT(
        RGB_MOD, TO(2)
    ),

    [2] = LAYOUT(
        RGB_HUI, TO(3)
    ),
    
    [3] = LAYOUT(
        RGB_HUD, TO(4)
    ),

    [4] = LAYOUT(
        RGB_SAI, TO(5)
    ),
    
    [5] = LAYOUT(
        RGB_SAD, TO(6)
    ),

    [6] = LAYOUT(
        RGB_VAI, TO(7)
    ),

    [7] = LAYOUT(
        RGB_VAD, TO(0)
    ),
};

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
      // Go to FN layer when bootmagic key is held
      //bootloader_jump();
      layer_on(1);
    }
}