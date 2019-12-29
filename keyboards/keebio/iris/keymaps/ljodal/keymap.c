#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

#define QWERTY 0
#define SYMBOL 1

#define ENTER LT(SYMBOL, KC_ENT)
#define SPACE LT(SYMBOL, KC_SPC)

enum custom_keycodes {
    // Custom key that normally sends ', but sends " if shift is pressed.
    QUOTE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        // clang-format off
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
        //|  '  "  |   1    |   2    |   3    |   4    |   5    |                      |   6    |   7    |   8    |   9    |   0    |        |
           QUOTE,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
        //|  Tab   |   Q    |   W    |   E    |   R    |   T    |                      |   Y    |   U    |   I    |   O    |   P    |   Å    |
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AA,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
        //|  Esc   |   A    |   S    |   D    |   F    |   G    |                      |   H    |   J    |   K    |   L    |   Ø    |   Æ    |
           KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, NO_AE,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        //| LShift |   Z    |   X    |   C    |   V    |   B    |  Lalt  |    |  Del   |   N    |   M    |  ,  ;  |  .  :  |  -  _  |  @  *  |
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,      KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, NO_AT_MAC,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        //                               |  LCtrl |  LCmd  |  Enter |             |  Space |  Tab   | Bckspc |
                                          KC_LCTL, KC_LCMD, ENTER,                 SPACE,   KC_TAB,  KC_BSPC
        //                               └────────┴────────┴────────┘             └────────┴────────┴────────┘
        // clang-format on
        ),

    [SYMBOL] = LAYOUT(
        // clang-format off
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
        //|        |        |        |        |        |        |                      |        |        |        |        |        |        |
           KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
        //|        |        |        |        |        |        |                      |        |        |        |        |        |        |
           RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
        //|        |        |        |        |        |        |                      |        |        |        |        |        |        |
           KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                        KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        //|        |        |        |        |        |        |                      |        |        |        |        |        |        |
           BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,      KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_END,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        //                               |        |        |        |             |        |        |        |
                                          _______, _______, KC_DEL,                KC_DEL,  _______, KC_P0
        //                               └────────┴────────┴────────┘             └────────┴────────┴────────┘
        // clang-format on
        ),
};

// Handler for the custom QUOTE keycode.
static void process_QUOTE(keyrecord_t *record) {
    // Keep track of the keycode sent, so we send the correct one on key up
    static uint16_t quote_kc_sent = KC_NO;

    if (record->event.pressed) {
        // If the quote_kc_sent variable is not KC_NO, this means we have
        // already sent a keycode that has not been released yet, so don't send
        // anything.
        if (quote_kc_sent != KC_NO) return;

        // SEND NO_PIPE which is the ' key on Norwegian Mac keyboards, but if
        // shift is pressed send NO_2 instead, which is where " is placed.
        quote_kc_sent = keyboard_report->mods & MOD_BIT(KC_LSFT) ? KC_2 : NO_PIPE;
        register_code(quote_kc_sent);
    } else {
        // If the quote_kc_sent variable is KC_NO this means that we have not
        // sent a keycode, so do not send anything on key up.
        if (quote_kc_sent == KC_NO) return;

        // Unregister the keycode we sent and reset the gobal state
        unregister_code(quote_kc_sent);
        quote_kc_sent = KC_NO;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QUOTE:
            process_QUOTE(record);
            return false;
        default:
            return true;  // Process keycode normally
    }
}
