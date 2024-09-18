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
        RGB_SAI, TO(4)
    ),
    
    [4] = LAYOUT(
        RGB_SAD, TO(5)
    ),

    [5] = LAYOUT(
        RGB_VAI, TO(6)
    ),

    [6] = LAYOUT(
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