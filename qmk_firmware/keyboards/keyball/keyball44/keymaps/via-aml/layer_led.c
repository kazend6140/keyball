#ifdef LAYER_LED_ENABLE

#include QMK_KEYBOARD_H

// レイヤーごとにLED色変更
// refs: https://docs.qmk.fm/features/rgblight
static uint8_t layer_no_prev = 0;
void change_layer_led_color(uint8_t layer_no) {
	uint8_t index;
	index = layer_no - layer_no_prev;
	switch(index){
		case   0:   // Layer 0
		case   1:   // Layer 0
		case   2:   // Layer 1
		case   4:   // Layer 2
		case   8:   // Layer 3	
		case  16:   // Layer 4
		rgblight_sethsv(HSV_OFF);
            break;
		case  32:   // Layer 5
		    rgblight_sethsv(HSV_MAGENTA);
            break;
		case  64:   // Layer 6
		    rgblight_sethsv(HSV_CYAN);
            break;
		default:
			rgblight_sethsv(HSV_RED);
			break;
	}
}
#endif