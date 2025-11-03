

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYMBOLS = 1,
    _QWERTY = 2,
    _SPECIAL = 3,
    _EXTRA = 4
};

#define CAPS_LED_IDX 10

static void set_layer_hsv(uint8_t layer) {
    switch (layer) {
        case _BASE:         rgb_matrix_sethsv_noeeprom(HSV_RED);    break;
        case _SYMBOLS:      rgb_matrix_sethsv_noeeprom(HSV_BLUE);   break;
        case _QWERTY:       rgb_matrix_sethsv_noeeprom(HSV_GREEN);  break;
        case _SPECIAL:      rgb_matrix_sethsv_noeeprom(HSV_YELLOW); break;
        case _EXTRA:        rgb_matrix_sethsv_noeeprom(HSV_PURPLE); break;
        default: break;
    }
}


layer_state_t Layer_state_set_user(layer_state_t state) {
    set_layer_hsv(get_highest_layer(state));
    return state;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicator_user(void) {
    const uint8_t active = get_highest_layer(layer_state);

    if (host_keyboard_led_state().caps_lock) {

        rgb_matrix_set_color(CAPS_LED_IDX, 255, 255, 255);
    }

   return false;
}

void keyboard_post_init_user(void) {
    set_layer_hsv(get_highest_layer(layer_state));
}
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_Q,  KC_W,  KC_F,  CKC_P,  KC_B,    _______,       KC_SCOLON, KC_J,   KC_L,  KC_U,    KC_Y,  KC_QUOTE,    TO(0),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB, KC_A,   KC_R,   KC_S,   KC_T,   KC_G,    KC_RALT,           KC_DEL,    KC_M,   KC_N,   KC_E,     KC_I,   KC_O,  KC_LGUI,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LSFT_T(KC_CAPSLOCK),    KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,                  KC_K,   KC_H,   KC_COMMA,  KC_DOT, KC_SLASH,  KC_ENTER,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            KC_LCTRL,  TT(1), LT1(KC_SPACE),     LT1(KC_BSPACE),     TT(2), TT(3)
  ),


  [_SYMBOLS] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_GRAVE,     KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_EQUAL,        KC_NUMLOCK, KC_KP_7,   KC_KP_8,  KC_KP_9,    KC_KP_PLUS,  KC_KP_ASTERISK,    TO(0),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINUS,           KC_DEL,    KC_KP_4,   KC_KP_5,   KC_KP_6,     KC_KP_,MINUS   KC_KP_SLASH,  _______,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_LSHIFT,      KC_MINUS,   KC_EQUAL,   KC_LBRACKET,   KC_RBRACKET,   KC_BSLASH,        KC_KP_1,   KC_KP_2,   KC_KP_3,  KC_KP_COMMA, _______,  KC_KP_ENTER,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            _______,  TT(2), _______,     KC_BSPACE,     KC_KP_0, KC_KP_DOT
  ),

  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,    _______,            _______,        KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,    TT(0),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,    KC_RALT,           KC_DEL,     KC_H,   KC_J,   KC_K,     KC_L,   KC_SCOLON,  KC_QUOTE,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LSFT_T(KC_CAPSLOCK),      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,   KC_COMMA,  KC_DOT, KC_SLASH,  KC_ENTER,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            KC_LCTRL,  TT(1), LT1(KC_SPACE),     LT1(KC_BSPACE),     _______, _______
  ),

  [_SPECIAL] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_UNDO,  KC_CUT,  KC_COPY,  KC_PSTE,  KC_AGIN,    _______,        _______, KC_AGIN,   KC_PASTE,  KC_COPY,    KC_CUT,  KC_UNDO,    TO(0),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        _______,      KC_LGUI, KC_LALT, KC_LCTRL,   KC_SHFT,   _______,    _______,           _______,    _______,   KC_LSHFT,   KC_LCTRL,     KC_LALT,   KC_LGUI,  _______,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        _______,      KC_UNDO,   KC_CUT,   KC_COPY,   KC_PSTE,   KC_AGIN,                      KC_AGIN,   KC_PSTE,   KC_COPY,  KC_CUT, KC_UNDO,  _______,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            _______,  KC_BTN2, KC_BTN1,     KC_BTN1,     KC_BTN2, _______
  ),

  [_EXTRA] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     _______, KC_MS_U ,  _______,  _______,  _______,    _______,        _______, _______,   KC_WH_U,  _______,    _______,  KC_VOLU,    KC_VOLD,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_MYCM, KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,   _______,    _______,           KC_WH_L,    KC_WH_D,   KC_WH_R,   _______,     KC_MNXT,   KC_MPRV,  KC_QUOT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        _______,      _______,   _______,   _______,   _______,   _______,                                   _______,   _______,   _______,  _______, KC_MPLY,  KC_MUTE,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            _______,  KC_BTN2,     KC_BTN1,     KC_BTN1, KC_BTN2, _______
  )
};


