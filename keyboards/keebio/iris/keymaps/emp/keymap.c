#include QMK_KEYBOARD_H

// todo: consider making all mods one-shot
// todo: media keys

extern keymap_config_t keymap_config;

// Layer definitions
#define _COLEMAK 0
#define _SYMBOL 1
#define _NAVIGATION 2
#define _FUNCTION 3

// Custom keycode definitions
enum custom_keycodes {
    CTL_ESC = SAFE_RANGE,   // mod tap: left control / esc
    RCAG,                   // mods: RCtl, RAlt, RGui
};

// Shorthand keycode definitions
#define VUP_MAC KC__VOLUP
#define VDN_MAC KC__VOLDOWN
#define MUT_MAC KC__MUTE
#define LAY_SYM MO(_SYMBOL)
#define LAY_NAV MO(_NAVIGATION)
#define LAY_FUN MO(_FUNCTION)

// The layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default layer
    [_COLEMAK] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    LAY_SYM, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LAY_FUN,  RCAG,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LAY_NAV,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        KC_LALT, KC_LGUI, KC_LSFT,  KC_SPC,  KC_ENT,  KC_DEL
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    [_SYMBOL] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, _______, _______, _______, _______,                    _______, _______, KC_LPRN, KC_RPRN, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, KC_UP,   _______, _______, _______,                    _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    [_NAVIGATION] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, MUT_MAC, VDN_MAC, VUP_MAC, _______,                    _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______,                    _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    [_FUNCTION] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_BRMD, KC_BRMU, _______, _______, KC_PWR,  _______,  _______, KC_MRWD, KC_MPLY, KC_MFFD, MUT_MAC, VDN_MAC, VUP_MAC,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    static bool mt_used = false;
    static uint16_t mt_timer = 0;

    // was this function called to handle a pressed key?
    const bool pressed = record->event.pressed;

    // any keydown spends a pending mod/tap key
    if (pressed) {
        mt_used = true;
    }

    // keycodes >= SAFE_RANGE are not handled
    if (keycode < SAFE_RANGE) {
        return true;    // this keypress was not handled
    }

    switch (keycode) {
    case CTL_ESC:       // mod tap: left control
        if (pressed) {
            register_code(KC_LCTL);
            mt_timer = timer_read();
            mt_used = false;
        } else {
            unregister_code(KC_LCTL);
            if (!mt_used && timer_elapsed(mt_timer) < TAPPING_TERM) {
                tap_code(KC_ESC);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled
    case RCAG:
        if (pressed) {
            register_code(KC_RGUI);
            register_code(KC_RALT);
            register_code(KC_RCTL);
        } else {
            unregister_code(KC_RGUI);
            unregister_code(KC_RALT);
            unregister_code(KC_RCTL);
        }
        return false;   // this keypress was handled
    }

    return true;        // this keypress was not handled
}

