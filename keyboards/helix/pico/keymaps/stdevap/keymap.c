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

// a2jlib
#include "a2j/translate_ansi_to_jis.h"

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
    _QWERTY_W,
    _LOWER,
    _LOWER_W,
    _RAISE,
    _RAISE_W,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_W,
  LOWER,
  LOWER_W,
  RAISE,
  RAISE_W,
  ADJUST,
  HANZEN,
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
#define TAB_LOWR LT(_LOWER,KC_TAB)
#define TAB_LOWR_W LT(_LOWER_W,KC_TAB)
#define ENT_RAIS LT(_RAISE,KC_ENT)
#define ENT_RAIS_W LT(_RAISE_W,KC_ENT)
#define CMD_KANA RGUI_T(KC_LNG1)
#define GUI_TAB LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty(Mac)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctl  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Eisu | MCtl |Adjust|  Opt |  Cmd |Space |TabLwr|EnRais|  BS  |CmKana| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT( \
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_MINUS, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                       KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      KC_LNG2, KC_MCTL, ADJUST,  KC_LALT, KC_LGUI,  KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  CMD_KANA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Qwerty(Win)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctl  |WinTab|Adjust|  Win |  Alt |Space |TabLwr|EnRais|  BS  |  Hnk | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
[_QWERTY_W] = LAYOUT( \
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                           KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_MINUS, \
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                           KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                           KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      KC_LCTL, GUI_TAB, ADJUST,  KC_LGUI, KC_LALT,  KC_SPC, TAB_LOWR_W, ENT_RAIS_W, KC_BSPC,  HANZEN,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Lower(Mac)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |   +  |   =  |      |             | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |   {  |             |   }  |      |      |   [  |   ]  |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Mute | Next | Prev | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
      _______, _______, _______, KC_PLUS, KC_EQL,  _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
      _______, _______, _______, _______, _______, KC_LCBR,                   KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MNXT, KC_MPRV, KC_MPLY \
      ),

  /* Lower(Win)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |PageUp|   +  |   =  |      |             | Left | Down |  Up  |Right | Home | End  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |PageDn|      |      |   {  |             |   }  |      |      |   [  |   ]  |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |  Del |      | Mute | Next | Prev | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER_W] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
      _______, _______, KC_PGUP, KC_PLUS, KC_EQL , _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END , \
      _______, _______, KC_PGDN, _______, _______, KC_LCBR,                   KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_MUTE, KC_MNXT, KC_MPRV, KC_MPLY \
      ),

  /* Raise(Mac)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Mute | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
      _______, KC_F11,  KC_F12, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Raise(Win)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |      |      |             | PrSc |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Mute | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE_W] = LAYOUT( \
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
      _______, KC_F11,  KC_F12,  _______, _______, _______,                     KC_PSCR, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Adjust
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |Qwe_W |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |Aud on|Audoff|MU TOG|MU MOD|      |             |      |Qwe_M |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      _______, QK_BOOT, _______, _______, _______, _______,                   _______, QWERTY_W, _______, _______, _______, _______, \
      _______, AU_ON,   AU_OFF,  MU_TOGG, MU_NEXT, _______,                   _______, QWERTY,   _______, _______, _______, _______, \
      _______, CK_TOGG, CK_RST,  CK_UP,   CK_DOWN, _______,                   _______, _______,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
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

bool AJUST_LAYER_ON = false;

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
    case QWERTY_W:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY_W);
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
    case LOWER_W:
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
        layer_on(_LOWER_W);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER_W);
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
    case RAISE_W:
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
        layer_on(_RAISE_W);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE_W);
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
    case HANZEN:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("`"));
        }
        return false;
        break;
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
  
  // In Windows mode, convert ANSI to JIS
  switch (get_highest_layer(default_layer_state)) {
    case _QWERTY_W:
      // No conversion is performed while in ADJUST LAYER
      // To avoid interference with LED brightness adjustment buttons...
      if (AJUST_LAYER_ON == false) {
        return process_record_user_a2j(keycode, record);
      }
      break;
    default:
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

  // Get AJUST LAYER ON or OFF
  switch (layer) {
    case _ADJUST:
      AJUST_LAYER_ON = true;
      break;
    default:
      AJUST_LAYER_ON = false;
      break;
  }

#ifdef RGBLIGHT_ENABLE
  // Store HSV values before changing LED color
  switch (layer) {
    case _LOWER:
    case _LOWER_W:
    case _RAISE:
    case _RAISE_W:
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
    case _LOWER_W:
      // Change LED color
      rgblight_sethsv_noeeprom(LOWER_HUE, LOWER_SAT, current_val);
      break;
    case _RAISE:
    case _RAISE_W:
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