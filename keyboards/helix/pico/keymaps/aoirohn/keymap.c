#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    // _EUCALYN,
    _ASTARTE,
    _QWERTY_W,
    _COLEMAK_W,
    _DVORAK_W,
    // _EUCALYN_W,
    _ASTARTE_W,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  // EUCALYN,
  ASTARTE,
  QWERTY_W,
  COLEMAK_W,
  DVORAK_W,
  // EUCALYN_W,
  ASTARTE_W,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  EISU,
  KANA,
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
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_CMD LCTL(KC_LCMD)
#define TAB_LOWR LT(_LOWER,KC_TAB)
#define ENT_RAIS LT(_RAISE,KC_ENT)
#define CMD_EISU LGUI_T(KC_LNG2)
#define CMD_KANA RGUI_T(KC_LNG1)
#define ALT_MHEN LALT_T(JP_MHEN)
#define ALT_HENK RALT_T(JP_HENK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|CtlCMd| Caps |  Opt |CmEisu|Space |TabLwr|EnRais|  BS  |CmKana| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
      CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                       KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      ADJUST,  CTL_CMD, KC_CAPS, KC_LALT, CMD_EISU, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  CMD_KANA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|CtlCMd| Caps |  Opt |CmEisu|Space |TabLwr|EnRais|  BS  |CmKana| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,     KC_G,                       KC_J,    KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
      CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,     KC_D,                       KC_H,    KC_N,     KC_E,    KC_I,    KC_O,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                       KC_K,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      ADJUST,  CTL_CMD, KC_CAPS, KC_LALT, CMD_EISU, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC, CMD_KANA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|CtlCMd| Caps |  Opt |CmEisu|Space |TabLwr|EnRais|  BS  |CmKana| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_DVORAK] = LAYOUT( \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,     KC_Y,                       KC_F,    KC_G,     KC_C,    KC_R,    KC_L,    KC_BSLS, \
      CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,     KC_I,                       KC_D,    KC_H,     KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,     KC_X,                       KC_B,    KC_M,     KC_W,    KC_V,    KC_Z,    KC_RSFT, \
      ADJUST,  CTL_CMD, KC_CAPS, KC_LALT, CMD_EISU, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC, CMD_KANA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Eucalyn
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   ,  |   .  |   ;  |             |   M  |   R  |   D  |   Y  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   O  |   E  |   I  |   U  |             |   G  |   T  |   K  |   S  |   N  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   F  |   `  |   '  |   B  |   H  |   J  |   L  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|CtlCMd| Caps |  Opt |CmEisu|Space |TabLwr|EnRais|  BS  |CmKana| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  /*[_EUCALYN] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT,   KC_SCLN,                    KC_M,    KC_R,     KC_D,    KC_Y,    KC_P,    KC_BSLS, \
      CTL_ESC, KC_A,    KC_O,    KC_E,    KC_I,     KC_U,                       KC_G,    KC_T,     KC_K,    KC_S,    KC_N,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_F,                       KC_B,    KC_H,     KC_J,    KC_L,    KC_SLSH, KC_RSFT, \
      ADJUST,  CTL_CMD, KC_CAPS, KC_LALT, CMD_EISU, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC, CMD_KANA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),*/

  /* Astarte
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   U  |   Y  |   ,  |             |   J  |   D  |   H  |   G  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   I  |   O  |   E  |   A  |   .  |             |   K  |   T  |   N  |   S  |   R  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   ;  |   `  |   '  |   M  |   L  |   F  |   B  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|CtlCMd| Caps |  Opt |CmEisu|Space |TabLwr|EnRais|  BS  |CmKana| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ASTARTE] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_U,    KC_Y,     KC_COMM,                    KC_J,    KC_D,     KC_H,    KC_G,    KC_P,    KC_BSLS, \
      CTL_ESC, KC_I,    KC_O,    KC_E,    KC_A,     KC_DOT,                     KC_K,    KC_T,     KC_N,    KC_S,    KC_R,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_SCLN,                    KC_M,    KC_L,     KC_F,    KC_B,    KC_SLSH, KC_RSFT, \
      ADJUST,  CTL_CMD, KC_CAPS, KC_LALT, CMD_EISU, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC, CMD_KANA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| App  | Caps |  Win |AltMhn|Space |TabLwr|EnRais|  BS  |AltHnk| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */

[_QWERTY_W] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
      CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                       KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      ADJUST,  KC_APP,  KC_CAPS, KC_LGUI, ALT_MHEN, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  ALT_HENK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| App  | Caps |  Win |AltMhn|Space |TabLwr|EnRais|  BS  |AltHnk| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_COLEMAK_W] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,     KC_G,                       KC_J,    KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
      CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,     KC_D,                       KC_H,    KC_N,     KC_E,    KC_I,    KC_O,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                       KC_K,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      ADJUST,  KC_APP,  KC_CAPS, KC_LGUI, ALT_MHEN, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  ALT_HENK, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT \
      ),

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| App  | Caps |  Win |AltMhn|Space |TabLwr|EnRais|  BS  |AltHnk| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_DVORAK_W] = LAYOUT( \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,     KC_Y,                       KC_F,    KC_G,     KC_C,    KC_R,    KC_L,    KC_BSLS, \
      CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,     KC_I,                       KC_D,    KC_H,     KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,     KC_X,                       KC_B,    KC_M,     KC_W,    KC_V,    KC_Z,    KC_RSFT, \
      ADJUST,  KC_APP,  KC_CAPS, KC_LGUI, ALT_MHEN, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  ALT_HENK, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT \
      ),

  /* Eucalyn
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   ,  |   .  |   ;  |             |   M  |   R  |   D  |   Y  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   A  |   O  |   E  |   I  |   U  |             |   G  |   T  |   K  |   S  |   N  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   F  |   `  |   '  |   B  |   H  |   J  |   L  |   /  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| App  | Caps |  Win |AltMhn|Space |TabLwr|EnRais|  BS  |AltHnk| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  /*[_EUCALYN_W] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT,   KC_SCLN,                    KC_M,    KC_R,     KC_D,    KC_Y,    KC_P,    KC_BSLS, \
      CTL_ESC, KC_A,    KC_O,    KC_E,    KC_I,     KC_U,                       KC_G,    KC_T,     KC_K,    KC_S,    KC_N,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_F,                       KC_B,    KC_H,     KC_J,    KC_L,    KC_SLSH, KC_RSFT, \
      ADJUST,  KC_APP,  KC_CAPS, KC_LGUI, ALT_MHEN, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  ALT_HENK, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT \
      ),*/

  /* Astarte
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   U  |   Y  |   ,  |             |   J  |   D  |   H  |   G  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CtlEsc|   I  |   O  |   E  |   A  |   .  |             |   K  |   T  |   N  |   S  |   R  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   ;  |   `  |   '  |   M  |   L  |   F  |   B  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| App  | Caps |  Win |AltMhn|Space |TabLwr|EnRais|  BS  |AltHnk| Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ASTARTE_W] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_U,    KC_Y,     KC_COMM,                    KC_J,    KC_D,     KC_H,    KC_G,    KC_P,    KC_BSLS, \
      CTL_ESC, KC_I,    KC_O,    KC_E,    KC_A,     KC_DOT,                     KC_K,    KC_T,     KC_N,    KC_S,    KC_R,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_SCLN,                    KC_M,    KC_L,     KC_F,    KC_B,    KC_SLSH, KC_RSFT, \
      ADJUST,  KC_APP,  KC_CAPS, KC_LGUI, ALT_MHEN, KC_SPC, TAB_LOWR, ENT_RAIS, KC_BSPC,  ALT_HENK, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  �   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |   {  |   }  |   [  |   ]  |             | Left | Down |  Up  |Right |      | Break|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |             |  F9  |  F10 |  End |  PDn |  PUp | Home |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      | F11  | F12  |      |      |ShfSpc|      |      |  Del |      | Mute | Next | Prev | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, JP_YEN, \
      KC_F1  , KC_F2,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BRK,  \
      KC_F3  , KC_F4,   KC_F5,   KC_F6,   KC_F7 ,  KC_F8,                       KC_F9,   KC_F10,  KC_END,  KC_PGDN, KC_PGUP, KC_HOME, \
      _______, KC_F11,  KC_F12,  _______, _______, S(KC_SPC), _______, _______, KC_DEL,  _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |   {  |   }  |   [  |   ]  |             |  -   |  =   |  +   |  _   |      | PrScr|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |             |  F9  |  F10 |  End |  PDn |  PUp | Home |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      | F11  | F12  |      |      |ShfSpc|      |      |  Del |      | Mute | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE, \
      KC_F1  , KC_F2,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,                     KC_MINS, KC_EQL , KC_PLUS, KC_UNDS, _______, KC_PSCR, \
      KC_F3  , KC_F4,   KC_F5,   KC_F6,   KC_F7 ,  KC_F8,                       KC_F9,   KC_F10,  KC_END,  KC_PGDN, KC_PGUP, KC_HOME, \
      _______, KC_F11,  KC_F12,  _______, _______, S(KC_SPC), _______, _______, KC_DEL,  _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |Qwerty|Astart|Eucaln|Colemk|Dvorak|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |Aud on|Audoff|MU TOG|MU MOD|      |             |      |Qwerty|Astart|Eucaln|Colemk|Dvorak|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      _______, QK_BOOT, _______, _______, _______, _______,                   _______, QWERTY_W, ASTARTE_W, COLEMAK_W, DVORAK_W, _______, \
      _______, AU_ON,   AU_OFF,  MU_TOGG, MU_NEXT,  _______,                   _______, QWERTY,   ASTARTE,   COLEMAK,   DVORAK,   _______, \
      _______, CK_TOGG, CK_RST,  CK_UP,   CK_DOWN, _______,                   _______, _______,  RGB_TOG,   RGB_HUI,   RGB_SAI,  RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RGB_MOD,   RGB_HUD,   RGB_SAD,  RGB_VAD \
      )

};



#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
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
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    // case EUCALYN:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_SONG(tone_plover_gb);
    //     #endif
    //     persistent_default_layer_set(1UL<<_EUCALYN);
    //   }
    //   return false;
    //   break;
    case ASTARTE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_plover_gb);
        #endif
        persistent_default_layer_set(1UL<<_ASTARTE);
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
    case COLEMAK_W:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK_W);
      }
      return false;
      break;
    case DVORAK_W:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK_W);
      }
      return false;
      break;
    // case EUCALYN_W:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_SONG(tone_plover_gb);
    //     #endif
    //     persistent_default_layer_set(1UL<<_EUCALYN_W);
    //   }
    //   return false;
    //   break;
    case ASTARTE_W:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_plover_gb);
        #endif
        persistent_default_layer_set(1UL<<_ASTARTE_W);
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
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LNG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LNG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG1);
      }
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
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user()
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


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

static void render_logo(struct CharacterMatrix *matrix) {

  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}



void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLayer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case L_RAISE:
           matrix_write_P(matrix, PSTR("Raise"));
           break;
        case L_LOWER:
           matrix_write_P(matrix, PSTR("Lower"));
           break;
        case L_ADJUST:
        case L_ADJUST_TRI:
           matrix_write_P(matrix, PSTR("Adjust"));
           break;
        default:
           matrix_write(matrix, buf);
    }

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(matrix, led);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
