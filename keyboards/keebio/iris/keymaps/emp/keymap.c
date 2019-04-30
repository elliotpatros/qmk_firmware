#include QMK_KEYBOARD_H

// todo: turn process_record_user into a better function with structs.
// basically, make it faster

extern keymap_config_t keymap_config;

// Layer definitions
#define _COLEMAK 0
#define _ALTERNATE 1
#define _SYMBOL 2

// Custom keycode definitions
enum custom_keycodes {
    CTL_ESC = SAFE_RANGE,   // mod tap: left control / esc
    LST_LPR,                // mod tap: left shift / left paren
    RST_RPR,                // mod tap: right shift / right paren
    SFT_ENT,                // mod tap: right shift / enter
    RCAG,                   // mods: RCAG
    L_LAYER,                // layer tap: left function layer / space
    R_LAYER,                // layer tap: right function layer / enter
    S_LAYER,                // layer: symbols
};

// Shorthand keycode definitions
#define VUP_MAC KC__VOLUP
#define MUT_MAC KC__MUTE
#define VDN_MAC KC__VOLDOWN

// The layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // default layer
    [_COLEMAK] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    LST_LPR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    S_LAYER,  RCAG,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RST_RPR,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        KC_LGUI, L_LAYER, SFT_ENT,  KC_SPC,  R_LAYER, KC_LALT
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    // momentary on when either L_LAYER or R_LAYER is pressed
    [_ALTERNATE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,                     VUP_MAC, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BRMU,                    MUT_MAC, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, KC_BRMD, _______,  _______, VDN_MAC, KC_DEL,  KC_RGUI, KC_RALT, KC_RCTL, _______,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),

    // momentary on when both L_LAYER and R_LAYER are pressed, or when S_LAYER is pressed
    [_SYMBOL] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, _______, _______, _______, _______,                    XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_F12,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, _______, _______, _______, XXXXXXX,                    KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _______, _______, _______, _______, XXXXXXX, _______,  _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX, _______,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┘└────────┼────────┴────────┴────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    )

};

//------------------------------------------------------------------------------
// mod tap keys state
//------------------------------------------------------------------------------
#define CTL_ESC_ID 0
#define LST_LPR_ID 1
#define RST_RPR_ID 2
#define SFT_ENT_ID 3
#define L_LAYER_ID 4
#define R_LAYER_ID 5
#define NUM_TAP_ID 6

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    static bool llayer_pressed = false;
    static bool rlayer_pressed = false;
    static bool slayer_pressed = false;
    static bool shift1_pressed = false;
    static bool shift2_pressed = false;
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
    case SFT_ENT:       // mod tap: right shift
        shift1_pressed = pressed;
        if (pressed) {
            register_code(KC_RSFT);
            mt_timer[SFT_ENT_ID] = timer_read();
            mt_used = false;
        } else {
            if (! shift2_pressed) {
                unregister_code(KC_RSFT);
            }
            if (!mt_used && timer_elapsed(mt_timer[SFT_ENT_ID]) < TAPPING_TERM) {
                tap_code(KC_ENT);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled
    case L_LAYER:
        llayer_pressed = pressed;
        if (pressed) {
            layer_on(_ALTERNATE);
            if (rlayer_pressed) {
                layer_on(_SYMBOL);
            }
            mt_timer[L_LAYER_ID] = timer_read();
            mt_used = false;
        } else {
            if (! mt_used && timer_elapsed(mt_timer[L_LAYER_ID]) < TAPPING_TERM) {
                tap_code(KC_SPC);
            } else {
                mt_used = false;
            }
            if (! slayer_pressed) {
                layer_off(_SYMBOL);
                if (! rlayer_pressed) {
                    layer_off(_ALTERNATE);
                }
            } else if (! rlayer_pressed) {
                layer_off(_ALTERNATE);
            }
        }
        return false;   // this keypress was handled
    case R_LAYER:
        rlayer_pressed = pressed;
        if (pressed) {
            layer_on(_ALTERNATE);
            if (llayer_pressed) {
                layer_on(_SYMBOL);
            }
            mt_timer[R_LAYER_ID] = timer_read();
            mt_used = false;
        } else {
            if (! mt_used && timer_elapsed(mt_timer[R_LAYER_ID]) < TAPPING_TERM) {
                tap_code(KC_ENT);
            } else {
                mt_used = false;
            }
            if (! slayer_pressed) {
                layer_off(_SYMBOL);
                if (! llayer_pressed) {
                    layer_off(_ALTERNATE);
                }
            } else if (! llayer_pressed) {
                layer_off(_ALTERNATE);
            }
        }
        return false;   // this keypress was handled
    case LST_LPR: 
        if (pressed) {
            register_code(KC_LSFT);
            mt_timer[LST_LPR_ID] = timer_read();
            mt_used = false;
        } else {
            unregister_code(KC_LSFT);
            if (!mt_used && timer_elapsed(mt_timer[LST_LPR_ID]) < TAPPING_TERM) {
                tap_code(KC_LBRC);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled
    case CTL_ESC:       // mod tap: left control
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
    case RST_RPR: 
        shift2_pressed = pressed;
        if (pressed) {
            register_code(KC_RSFT);
            mt_timer[RST_RPR_ID] = timer_read();
            mt_used = false;
        } else {
            if (! shift1_pressed) {
                unregister_code(KC_RSFT);
            }
            if (!mt_used && timer_elapsed(mt_timer[RST_RPR_ID]) < TAPPING_TERM) {
                tap_code(KC_RBRC);
            } else {
                mt_used = false;
            }
        }
        return false;   // this keypress was handled
    case S_LAYER:
        slayer_pressed = pressed;
        if (pressed) {
            layer_on(_SYMBOL);
        } else {
            if (! (llayer_pressed || rlayer_pressed)) {
                layer_off(_SYMBOL);
            } else if (! (llayer_pressed && rlayer_pressed)) {
                layer_off(_SYMBOL);
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

