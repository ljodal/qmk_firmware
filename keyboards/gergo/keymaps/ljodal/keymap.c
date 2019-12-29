/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

#define KC_DQUOT LSFT(KC_2)
#define KC_FSCRN LCMD(LCTL(KC_F))

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * .-------------------------------------------.                         .-------------------------------------------.
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |  ESC   |   A  |   S  |   D  |   F  |   G  |   '  |           |   "  |   H  |   J  |   K  |   L  |   Ø  |   Æ    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | ,  ; | . :  | - _  |  @ *   |
 * '--------+------+------+------+------+------+------'           '------+------+------+------+------+------+--------'
 *                        .------.   .------.                               .------.   .------.
 *                        | Ctrl |   | CMD  |                               | TAB  |   | BKSP |
 *                        '------'   '------'                               '------'   '------'
 *                                              .-------.       .-------.
 *                                              |  ALT  |       | FScrn |
 *                                      .-------|-------|       |-------|-------.
 *                                      | SYMB  | NUMB  |       | SYMB  | NUMB  |
 *                                      | Space | Enter |       | Enter | Space |
 *                                      |       |       |       |       |       |
 *                                      '-------+-------'       '-------+-------'
 */
[BASE] = LAYOUT_gergo(
    KC_TAB,    KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    NO_AA,
    KC_ESC,    KC_A,  KC_S,   KC_D,   KC_F, KC_G, NO_PIPE,                       KC_DQUOT, KC_H,    KC_J, KC_K,    KC_L,   NO_OSLH, NO_AE,
    KC_LSFT,   KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_TRNS, KC_LALT,    KC_FSCRN, KC_TRNS,  KC_N,    KC_M, KC_COMM, KC_DOT, NO_MINS, NO_AT_MAC,
              KC_LCTL, KC_LCMD, LT(SYMB, KC_SPC), LT(NUMB, KC_ENT),    LT(SYMB, KC_ENT), LT(NUMB, KC_SPC), KC_TAB,  KC_BSPC
    ),
/* Keymap 1: Symbols layer
 *
 * .-------------------------------------------.                         .-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |      |      |      |      |      |  \ |   |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  *   |  %   |  ¨ ^   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * '--------+------+------+------+------+------+------'           '------+------+------+------+------+------+--------'
 *                        .------.   .------.                               .------.   .------.
 *                        |      |   |      |                               |      |   | DEL  |
 *                        '------'   '------'                               '------'   '------'
 *                                              .-------.       .-------.
 *                                              |       |       |       |
 *                                      ,-------|-------|       |-------|-------.
 *                                      |       |       |       |       |       |
 *                                      |   ;   |   =   |       |   =   |   ;   |
 *                                      |       |       |       |       |       |
 *                                      '-------+-------'       '-------+-------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, NO_EXLM, NO_AT_MAC,  NO_LCBR_MAC, NO_RCBR_MAC, NO_PIPE,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_BSLS_MAC,
    KC_TRNS, NO_HASH, NO_DLR_MAC, NO_LPRN,     NO_RPRN,     NO_GRV,  KC_TRNS,                          KC_TRNS, NO_PLUS, NO_MINS, NO_SLSH, NO_ASTR, NO_PERC, NO_QUOT,
    KC_TRNS, NO_PERC, NO_CIRC,    NO_LBRC,     NO_RBRC,     NO_TILD, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, NO_AMPR, NO_EQL,  KC_COMM, KC_DOT,  NO_SLSH, NO_MINS,
                                               KC_TRNS,     KC_TRNS, NO_SCLN, NO_EQL,         NO_EQL,  NO_SCLN, KC_PGUP, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 *
 * .-------------------------------------------.                         .-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |        |  F1  | F2   | F3   | F4   | F5   | F6   |           | PGDN | LEFT | DOWN |  UP  | RIGHT| PGUP |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  F7  | F8   | F9   | F10  | F11  | B12  |           | LMB  | MLFT | MDWN | MUP  | MRGHT| RMB  |        |
 * '--------+------+------+------+------+------+------'           '------+------+------+------+------+------+--------'
 *                        .------.   .------.                               .------.   .------.
 *                        |      |   |      |                               |      |   |      |
 *                        '------'   '------'                               '------'   '------'
 *                                              .-------.       .-------.
 *                                              |       |       |       |
 *                                      .-------+-------|       |-------+-------.
 *                                      |       |       |       |       |       |
 *                                      |       |       |       |       |       |
 *                                      |       |       |       |       |       |
 *                                      '-------+-------'       '-------+-------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_PGDN,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_TRNS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_BTN1,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
 *
 * .-------------------------------------------.                         .-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * '--------+------+------+------+------+------+------'           '------+------+------+------+------+------+--------'
 *                        .------.   .------.                               .------.   .------.
 *                        |      |   |      |                               |      |   |      |
 *                        '------'   '------'                               '------'   '------'
 *                                              .-------.       .-------.
 *                                              |       |       |       |
 *                                      .-------+-------|       |-------+-------.
 *                                      |       |       |       |       |       |
 *                                      |       |       |       |       |       |
 *                                      |       |       |       |       |       |
 *                                      '-------+-------'       '-------+-------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
