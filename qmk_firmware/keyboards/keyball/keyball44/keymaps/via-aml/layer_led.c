#ifdef LAYER_LED_ENABLE

#include QMK_KEYBOARD_H

// レイヤーごとにLED色変更
// refs: https://docs.qmk.fm/features/rgblight
void change_layer_led_color(uint8_t layer_no) {
	switch(layer_no){
		case 0:
		case 1:
		case 2:	
		case 3:	
		case 4:	
		case 5:
		case 6:
		case 7:
		    rgblight_sethsv(HSV_OFF);
            break;
		case 8:	
		    rgblight_sethsv(HSV_SPRINGGREEN);
			break;
		default:
			rgblight_sethsv(HSV_SPRINGGREEN);
			break;
	}
}
#endif