

#include QMK_KEYBOARD_H

enum layers_names {
    _BASE = 0,
    _COLEMAK,
    _QWERTY,
    _SYMBOLS,
    _SPECIAL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_Q,   KC_W,    KC_E,  KC_R,    KC_T,    KC_GRAVE,       KC_NUM,        KC_1,   KC_2,   KC_3,     KC_4,    KC_5,   KC_6,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB,      KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_RALT,      KC_DEL,       KC_WBAK, MS_BTN1, MS_BTN2, MS_BTN3,   KC_UP,  KC_ENT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LSFT_T(KC_CAPS),    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                           KC_WFWD,  MS_BTN4, MS_BTN5, KC_LEFT, KC_DOWN,  KC_RIGHT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            KC_LCTL,  TT(_SYMBOLS),   LT(_COLEMAK, KC_SPC),      LT(_COLEMAK, KC_SCRL),  TT(_QWERTY), TT(_COLEMAK)
  ),

[_COLEMAK] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,    KC_GRAVE,       KC_SCLN, KC_J,   KC_L,  KC_U,    KC_Y,  KC_QUOT,    TO(_BASE),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB, KC_A,   KC_R,   KC_S,   KC_T,   KC_G,    KC_RALT,           KC_DEL,    KC_M,   KC_N,   KC_E,     KC_I,   KC_O,  TO(_QWERTY),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LSFT_T(KC_CAPS),    KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,                  KC_K,   KC_H,   KC_COMM,  KC_DOT, KC_SLASH,  KC_ENT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            KC_LCTL,  TT(_SYMBOLS),   LT(_SYMBOLS, KC_SPC),     LT(_SYMBOLS, KC_BSPC),     TT(_SPECIAL), MS_BTN1
  ),

  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,    KC_GRAVE,            TO(_COLEMAK),        KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,    TO(_BASE),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,    KC_RALT,           KC_DEL,     KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN,  KC_QUOT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LSFT_T(KC_CAPS),      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                           KC_LCTL,  TT(_SYMBOLS),   LT(_SYMBOLS, KC_SPC),     LT(_SYMBOLS, KC_BSPC),     TT(_SPECIAL), MS_BTN1
  ),


  [_SYMBOLS] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_GRAVE,     KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_EQUAL,        KC_NUM_LOCK, KC_KP_7,   KC_KP_8,  KC_KP_9,    KC_KP_PLUS,  KC_KP_ASTERISK,    TO(_BASE),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS,           KC_DEL,     KC_KP_4,   KC_KP_5,   KC_KP_6,   KC_KP_MINUS,   KC_KP_SLASH,  TO(_COLEMAK),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_LSFT, KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,            KC_KP_1,   KC_KP_2,   KC_KP_3,  KC_KP_COMMA, KC_KP_DOT,  KC_KP_ENTER,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            KC_NO,  TT(_QWERTY), KC_SPC,     KC_BSPC,     KC_KP_0, KC_KP_DOT
  ),



  [_SPECIAL] = LAYOUT_split_3x6_3_ex2(
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_ESC,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,    KC_F6,              KC_F7,     KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,    TO(_BASE),
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        KC_TAB,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,  MEH(KC_Q),     MEH(KC_Z),    KC_NO,  KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,  KC_NO,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
        LSFT_T(KC_CAPS),      KC_UNDO,   KC_CUT,   KC_COPY,   KC_PSTE,   KC_AGIN,                      KC_UNDO,   KC_CUT,   KC_COPY,  KC_PSTE, KC_AGIN,  KC_NO,
     // -----------+-------+-------+-------+-------+--------+---------------++-------------+-------+-------+---------+-------+---------+-------- //
                                            TT(_QWERTY),  MS_BTN2, MS_BTN1,     MS_BTN1,     MS_BTN2, TT(_COLEMAK)
  )



};

// kleuren per laag

#ifdef RGB_MATRIX_ENABLE

#define CAPS_LED_INDEX_LEFT 20 //index voor capslock toets links
#define CAPS_LED_INDEX_RIGHT 43 //index rechts
#define SCROLL_LED 45  // scroll led

static const HSV layer_hsv[] = {

[_BASE]       = { .h =   0, .s = 255, .v = 120}, //rood
[_SYMBOLS]    = { .h =  85, .s = 255, .v = 120}, //groen
[_COLEMAK]     = { .h = 170, .s = 255, .v = 120}, //blauw
[_SPECIAL]    = { .h =  40, .s = 255, .v = 120}, //oranje
[_QWERTY]      = { .h = 200, .s = 255, .v = 120}, //paars
};

bool rgb_matrix_indicators_user(void) {
// hoogste actieve laag

uint8_t layer = get_highest_layer(layer_state);

if (layer > _SPECIAL) { //voor als er nog extra lagen bijkomen die geen kleur hebben
    layer = _BASE;
}

HSV hsv = layer_hsv[layer];
RGB rgb = hsv_to_rgb(hsv);

rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);

if (host_keyboard_led_state().caps_lock) {
//links wit
    rgb_matrix_set_color(CAPS_LED_INDEX_LEFT, 255, 255, 255);
// rechts laagkleur
    rgb_matrix_set_color(CAPS_LED_INDEX_RIGHT, rgb.r, rgb.g, rgb.b);

}

if (host_keyboard_led_state().scroll_lock) {
    rgb_matrix_set_color(SCROLL_LED, 255, 255, 255);

}

return false;


}

// override van default indicator functie

bool rgb_matrix_indicators_kb(void) {
    return rgb_matrix_indicators_user();

}

#endif
