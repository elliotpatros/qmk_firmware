#include QMK_KEYBOARD_H

// todo: consider making all mods one-shot
// todo: media keys

extern keymap_config_t keymap_config;

// Layer definitions
#define _COLEMAK 0
#define _SYMBOL 1
#define _FUNCTION 2

// Custom keycodes, implemented later, in function: process_record_user()
enum custom_keycodes {
    CTL_ESC = SAFE_RANGE,   // mod tap: left control / esc
    SFT_ENT,                // mod tap: left shift / enter
    SYM_ENT,                // layer tap: symbols / enter
    GUI_SPC,                // mod tap: right shift / enter
    RCAG,                   // mods: right ctrl,alt,gui
};

// Shorthand keycode definitions
#define VUP_MAC KC__VOLUP
#define VDN_MAC KC__VOLDOWN
#define MUT_MAC KC__MUTE
#define VUP_INC LALT(LSFT(KC__VOLUP))
#define VDN_INC LALT(LSFT(KC__VOLDOWN))
#define LAY_FUN TT(_FUNCTION)

// The layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default layer
    [_COLEMAK] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LAY_FUN,  KC_BSLS, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        KC_LALT, GUI_SPC, SFT_ENT,  KC_SPC,  SYM_ENT, KC_BSPC
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    // Symbols layer
    [_SYMBOL] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_MINS, _______,  _______, KC_EQL,  KC_SPC,  _______, _______, _______, _______,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    // Function (and I guess also media & navigation) layer
    [_FUNCTION] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, VDN_INC, KC_UP,   VUP_INC, KC_F11,                     KC_F12,  KC_HOME, KC_UP,   KC_END,  _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, RCAG,    KC_LEFT, KC_DOWN, KC_RGHT, KC_BRMU,                    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, MUT_MAC, VDN_MAC, VUP_MAC, KC_BRMD, _______,  _______, KC_INS,  KC_DEL,  KC_PGDN, KC_PGUP, _______, _______,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    )

};

//------------------------------------------------------------------------------
// mod tap keys state
//------------------------------------------------------------------------------
#define CTL_ESC_ID 0    // mod tap: left control / esc
#define SFT_ENT_ID 1    // mod tap: left shift / enter
#define SYM_ENT_ID 2    // layer tap: symbols / enter
#define GUI_SPC_ID 3    // mod tap: right shift / enter
#define NUM_TAP_ID 4    // mods: right ctrl,alt,gui

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    static bool mt_used = false;
    static uint16_t mt_timer[NUM_TAP_ID] = {0};

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

    // mod tap: left control & escape
    case CTL_ESC:
        if (pressed) {
            register_code(KC_LCTL);
            mt_timer[CTL_ESC_ID] = timer_read();
            mt_used = false;
        } else {
            unregister_code(KC_LCTL);
            if (!mt_used && timer_elapsed(mt_timer[CTL_ESC_ID]) < TAPPING_TERM) {
                tap_code(KC_ESC);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled

    // mod tap: left shift & enter
    case SFT_ENT:
        if (pressed) {
            register_code(KC_LSFT);
            mt_timer[SFT_ENT_ID] = timer_read();
            mt_used = false;
        } else {
            unregister_code(KC_LSFT);
            if (!mt_used && timer_elapsed(mt_timer[SFT_ENT_ID]) < TAPPING_TERM) {
                tap_code(KC_ENT);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled

    // layer tap: symbol layer & enter
    case SYM_ENT:
        if (pressed) {
            layer_on(_SYMBOL);
            mt_timer[SYM_ENT_ID] = timer_read();
            mt_used = false;
        } else {
            layer_off(_SYMBOL);
            if (!mt_used && timer_elapsed(mt_timer[SYM_ENT_ID]) < TAPPING_TERM) {
                tap_code(KC_ENT);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled

    // mod tap: left gui & space
    case GUI_SPC:
        if (pressed) {
            register_code(KC_LGUI);
            mt_timer[GUI_SPC_ID] = timer_read();
            mt_used = false;
        } else {
            unregister_code(KC_LGUI);
            if (!mt_used && timer_elapsed(mt_timer[GUI_SPC_ID]) < TAPPING_TERM) {
                tap_code(KC_SPC);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled

    // mod tap: right shift & enter
    case RCAG:
        if (pressed) {
            register_code(KC_RCTL);
            register_code(KC_RALT);
            register_code(KC_RGUI);
        } else {
            unregister_code(KC_RGUI);
            unregister_code(KC_RALT);
            unregister_code(KC_RCTL);
        }
        return false;   // this keypress was handled
    }

    return true;        // this keypress was not handled
}
