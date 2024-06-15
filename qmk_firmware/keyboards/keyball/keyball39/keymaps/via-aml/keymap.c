/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 9, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 9, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 9, HSV_WHITE}
);
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer4_layer,    // Overrides caps lock layer
    my_layer5_layer,    // Overrides caps lock layer
    my_layer6_layer     // Overrides other layers
);

// clang-format off
// refs: https://docs.qmk.fm/keycodes
// refs: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , LT(3,KC_D),KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , LT(3,KC_ENT) ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , CTL_T(KC_COMM)  , KC_DOT   , KC_SLSH  ,
    KC_LALT  , KC_PSCR  , TG(4)    , KC_LGUI  , LSFT_T(KC_TAB), KC_BSPC,   LT(2,KC_ESC),LT(1,KC_SPC), _______ , _______ , _______  , TG(5)
  ),

  [1] = LAYOUT_universal(
    KC_1    , KC_2     , KC_3    , KC_4     , KC_5     ,                              KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    KC_EQL  , KC_LBRC  , KC_SLSH , KC_MINS  , KC_INT1  ,                              KC_SCLN  , KC_QUOT  , KC_RBRC  , KC_NUHS  , KC_INT3  ,
    _______ , _______  , _______ , _______  , _______  ,                              _______  , _______  , _______  , _______  , _______  ,
    _______ , _______  , _______ , _______  , KC_GRV  , KC_DEL  ,        _______  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    S(KC_1)  , S(KC_2)   , S(KC_3)   , S(KC_4)    , S(KC_5)   ,                       S(KC_6)   , S(KC_7)   , S(KC_8)   , S(KC_9)   , S(KC_0)   ,
    S(KC_EQL), S(KC_LBRC), S(KC_SLSH), S(KC_MINS) , S(KC_INT1),                       S(KC_SCLN), S(KC_QUOT), S(KC_RBRC), S(KC_NUHS), S(KC_INT3),
    KC_F1    , KC_F2     , KC_F3     , KC_F4      , KC_F5     ,                       KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    ,
    _______  , _______   , _______   , _______    , _______  , _______  ,  _______  , _______   , _______   , _______   , _______   , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______ ,                             _______  , _______  , KC_PGUP, KC_HOME , _______ ,
    _______  , _______  , _______  , _______  , _______ ,                             KC_LEFT  , KC_DOWN  , KC_UP  , KC_RGHT , _______ ,
    _______  , _______  , _______  , _______  , _______ ,                             _______  , _______  , KC_PGDN, KC_END  , _______ ,
    _______  , _______  , _______  , _______  , _______ , _______  ,       _______  , _______  , _______  , _______, _______ , _______

  ),
  
  [4] = LAYOUT_universal(
    KBC_SAVE , CPI_I100 , CPI_D100 , CPI_I1K  , CPI_D1K ,                             SCRL_TO  , SCRL_MO  , SCRL_DVI , SCRL_DVD , AML_TO ,
    AML_I50  , AML_D50  , _______  , _______  , _______  ,                            RGB_VAI  , RGB_TOG  , _______  , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                            RGB_VAD  , _______  , _______  , _______ , _______ ,
    QK_BOOT  , QK_RBT   , TG(4)    , _______  , _______  , _______ ,       TO(0)    , _______  , _______  , _______  , _______ , _______
  ),
  
  [5] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______ ,                             _______  , _______  , KC_BTN3  , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______ ,                             _______  , KC_BTN1  , SCRL_MO  , KC_BTN2 , KC_ENT  ,
    _______  , _______  , _______  , _______  , _______ ,                             _______  , KC_BTN4  , _______  , KC_BTN5 , KC_BSPC ,
    _______  , _______  , _______  , _______  , _______ , _______  ,       TO(0)    , _______  , _______  , _______  , _______ , TG(5)
  ),
  
  [6] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______ ,                             _______  , _______  , KC_BTN3  , _______ , _______ ,
    _______  , _______  , _______  , _______  , _______ ,                             _______  , KC_BTN1  , SCRL_MO  , KC_BTN2 , KC_ENT  ,
    _______  , _______  , _______  , _______  , _______ ,                             _______  , KC_BTN4  , _______  , KC_BTN5 , KC_BSPC ,
    _______  , _______  , _______  , _______  , _______ , _______  ,       TO(0)    , _______  , _______  , _______  , _______ , _______
  ),
};
// clang-format on

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_sethsv(HSV_OFF);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, 4));
	rgblight_set_layer_state(1, layer_state_cmp(state, 5));
    rgblight_set_layer_state(2, layer_state_cmp(state, 6));
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
	set_auto_mouse_layer(AUTO_MOUSE_DEFAULT_LAYER);
    set_auto_mouse_enable(true);
	rgblight_sethsv(HSV_OFF);
	
	// Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
#endif

