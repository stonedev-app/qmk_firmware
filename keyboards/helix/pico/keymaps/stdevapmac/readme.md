# The HelixPico Layout
## Layout

### Qwerty
```
 ,-----------------------------------------.             ,-----------------------------------------.
 | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   -  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Ctrl |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Enter|
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 | Shift| MCtl |Adjust| Alt  | GUI  |E/Lwr |Space | Bksp |J/Rais| Left | Down |  Up  |Right | Shift|
 `-------------------------------------------------------------------------------------------------'
```

### Lower
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |      |      |      |      |      |      |             |      |      |      |      |      |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |   `  |      |      |      |      |             |   +  |  =   |   [  |   ]  |  \   |      |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 `-------------------------------------------------------------------------------------------------'
```

### Raise
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |  F11 |  F12 |      |      |      |             |      |      |      |      |      |      |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 `-------------------------------------------------------------------------------------------------'
```

### Adjust
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |      | Reset|      |      |      |      |             |      |      |      |      |      |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |Aud on|Audoff|MU TOG|MU MOD|      |             |      |Qwerty|      |      |      |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      | HUE- | SAT- | VAL- |
 `-------------------------------------------------------------------------------------------------'
```

## Customize

see `qmk_firmware/keyboards/helix/pico/keymaps/default/rules.mk`

```
# Helix Spacific Build Options
# you can uncomment and edit follows 4 Variables
#  jp: 以下の4つの変数を必要に応じて編集し、コメントアウトをはずします。
# LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
# LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
# LED_ANIMATIONS = yes        # LED animations
# IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```
## Compile

go to qmk top directory.
```
$ cd qmk_firmware
```

build
```
$ make helix/pico:default
$ make helix/pico/back:default               # with backlight
$ make HELIX=no-ani helix/pico/back:default  # with backlight without animation
$ make helix/pico/under:default              # with underglow
```

build (experimental use of split_common with backlight)
```
$ make helix/pico/sc:default
```

flash to keyboard
```
$ make helix/pico:default:flash
$ make helix/pico/back:default:flash               # with backlight
$ make HELIX=no_ani helix/pico/back:default:flash  # with backlight without animation
$ make helix/pico/under:default:flash              # with underglow

```

## Link
* more detail wrote in Japanese [helix/Doc/firmware_jp.md](https://github.com/MakotoKurauchi/helix/blob/master/Doc/firmware_jp.md)
* [Helix top](https://github.com/MakotoKurauchi/helix)
