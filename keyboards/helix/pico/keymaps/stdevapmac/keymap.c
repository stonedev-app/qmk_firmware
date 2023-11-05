/* Copyright 2018 MakotoKurauchi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)
#define EISU_LOWR LT(_LOWER,KC_LNG2)
#define KANA_RAIS LT(_RAISE,KC_LNG1)
#define CMD_LEFT LGUI(KC_LEFT)
#define CMD_RGHT LGUI(KC_RGHT)
#define CMD_UP LGUI(KC_UP)
#define CMD_DOWN LGUI(KC_DOWN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   -  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | MCtl |Adjust| Alt  | GUI  |E/Lwr |Space | Bksp |J/Rais| Left | Down |  Up  |Right | Enter|
   * `-------------------------------------------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT( \
      KC_ESC,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P,    KC_MINUS, \
      KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,                       KC_H,      KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,                       KC_N,      KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, \
      KC_LCTL, KC_MCTL, ADJUST,  KC_LALT, KC_LGUI,   EISU_LOWR, KC_SPC, KC_BSPC, KANA_RAIS, KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_ENT \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   {  |   }  |   +  |  =   |      |             | Left | Down |  Up  |Right |  \   |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   [  |   ]  |   ~  |   `  |      |             |Cmd+Lt|Cmd+Dn|Cmd+Up|Cmd+Rt|  |   |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, KC_LCBR, KC_RCBR, KC_PLUS, KC_EQL, _______,                    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, _______,
      _______, KC_LBRC, KC_RBRC, KC_TILD, KC_GRV, _______,                   CMD_LEFT,CMD_DOWN,  CMD_UP,CMD_RGHT, KC_PIPE, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,   KC_9,     KC_0,    _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  _______,
      _______, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Adjust
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |Aud on|Audoff|MU TOG|MU MOD|      |             |      |Qwerty|      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      _______, QK_BOOT, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, AU_ON,   AU_OFF,  MU_TOGG, MU_NEXT, _______,                   _______, QWERTY,  _______, _______, _______, _______, \
      _______, CK_TOGG, CK_RST,  CK_UP,   CK_DOWN, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD \
      )

};



#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

// LAYER LED DEF
#ifdef RGBLIGHT_ENABLE

// LOWER LED COLOR DEF
#define LOWER_HUE 170
#define LOWER_SAT 200
// RAISE LED COLOR DEF
#define RAISE_HUE 250
#define RAISE_SAT 250

// define variables for changing LED color with LAYER
bool LED_LAYER_CHANGE_STATUS = false;
uint8_t current_hue;
uint8_t current_sat;
uint8_t current_val;

#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_RAISE);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }

  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    }


#ifdef AUDIO_ENABLE

void startup_user(void)
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user(void)
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {

  // Get current layer
  uint8_t layer = get_highest_layer(state);

#ifdef RGBLIGHT_ENABLE
  // Store HSV values before changing LED color
  switch (layer) {
    case _LOWER:
    case _RAISE:
      if (!LED_LAYER_CHANGE_STATUS) {
        LED_LAYER_CHANGE_STATUS = true;
        current_hue = rgblight_config.hue;
        current_sat = rgblight_config.sat;
        current_val = rgblight_config.val;
      }
      break;
    default:
      break;
  }
  
  // If the LAYER is LOWER or RAISE, change the LED color
  switch (layer) {
    case _LOWER:
      // Change LED color
      rgblight_sethsv_noeeprom(LOWER_HUE, LOWER_SAT, current_val);
      break;
    case _RAISE:
      // Change LED color
      rgblight_sethsv_noeeprom(RAISE_HUE, RAISE_SAT, current_val);
      break;
    default:
      // If LED color was changed, revert to the original color
      if (LED_LAYER_CHANGE_STATUS) {
        rgblight_sethsv_noeeprom(current_hue, current_sat, current_val);
        LED_LAYER_CHANGE_STATUS = false;
      }
      break;
  }
#endif

  return state;
}