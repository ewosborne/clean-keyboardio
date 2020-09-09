/*
...
removed
...
*/
KEYMAPS(

  /* 
   *  things to note in this keymap:
   *  the ANY key is oneshot: click once to use a single macro layer key, click twice to stick.
   *   LED is shift to layer
   *  the key after Key_5 is the LED key.  Mac screenshot to clipboard.
   *  the any key is ShiftToLayer(ANY), which is the macro (mostly passwords) layer
   *  the num key is Backslash, and shift-numkey is Pipe
   *  the alt key is RightAlt
   *  butterfly key doesn't do anything
   *   setting primary prog to led_effectnext breaks things as the key "presses" itself on bootup when programming, so it moves forward a mode
   */

#if defined (PRIMARY_KEYMAP_QWERTY)
  [PRIMARY] = KEYMAP_STACKED
  (XXX,          Key_1, Key_2, Key_3, Key_4, Key_5, OSL(ANY),
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   OSL(ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Backslash,
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   ___,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_RightAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

#else

#error "No default keymap defined. You should make sure that you have a line like '#define PRIMARY_KEYMAP_QWERTY' in your sketch"

#endif

 /* 
  *  LED key toggles caps lock
  *  Fn+tab starts a screen clip
  *  WASD are bound to the arrows you think they are
  *  Fn+numkey is Key_F11
  *  Fn+= is Key_12.  
  *  Fn+bkspc is Delete
  *  Fn+butterly is Windows key, I think.  need to test on windows.
  *  Fn+alt is LeftAlt.  
  *  Fn+Z is Play/Pause - if sonos is running, this will pause music.  
  *  Fn+backtick is Tab
  *  Fn+[x,c] and Fn+[<,>] slide the virtual desktop off to one side or the other.
  */

  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_CapsLock,
   Key_Tab,  ___,              Key_UpArrow, ___,        ___, ___, LCTRL(LGUI(LSHIFT(Key_4))),
   Key_Home, Key_LeftArrow,       Key_DownArrow, Key_RightArrow, ___, ___,
   Key_End,  Consumer_PlaySlashPause,  LCTRL(Key_LeftArrow), LCTRL(Key_RightArrow),        ___, ___,  ___,
   ___, Key_Delete, ___, ___,
   ___,

   ___, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   XXX,    ___, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow,  ___, ___,
   Key_PcApplication, ___, ___, LCTRL(Key_LeftArrow), LCTRL(Key_RightArrow), Key_Backslash,    Key_Pipe,
   ___, Key_LeftAlt, ___, ___,
   ___),


/* 
 *  Fn+6 is ctrl-alt-delete.
 */
  [ANY] =  KEYMAP_STACKED
 (Key_LEDEffectNext, M(MACRO_ONE), M(MACRO_TWO), M(MACRO_THREE),
 M(MACRO_FOUR), XXX, XXX,
  XXX, XXX, XXX, XXX, M(MACRO_R), XXX, XXX,
  XXX, XXX, XXX, XXX, XXX, XXX,
  XXX, XXX, XXX, XXX, XXX, XXX, XXX,
  XXX, XXX, XXX, XXX,
  XXX,

  ___, LCTRL(LALT(Key_Delete)), M(MACRO_SEVEN), XXX, XXX, XXX, XXX,
  ___, XXX, XXX, XXX, XXX, XXX, XXX,
       XXX, XXX, XXX, XXX, XXX, XXX,
  XXX, XXX, XXX, XXX, XXX, XXX, XXX,
  XXX, XXX, XXX, XXX,
  XXX),
  
) // KEYMAPS(

/*
....
*/


KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
  //LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
  //LEDRainbowWaveEffect,

  // The chase effect follows the adventure of a blue pixel which chases a red pixel across
  // your keyboard. Spoiler: the blue pixel never catches the red pixel
  //LEDChaseEffect,

  // These static effects turn your keyboard's LEDs a variety of colors
  //solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet,

  // The breathe effect slowly pulses all of the LEDs on your keyboard
  //LEDBreatheEffect,

  // The AlphaSquare effect prints each character you type, using your
  // keyboard's LEDs as a display
  //AlphaSquareEffect,

  // The stalker effect lights up the keys you've pressed recently
  StalkerEffect,

  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  //ColormapEffect,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  NumPad,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks,

  // Heatmap test
  // HeatmapEffect
  
  // wavepool test
  // WavepoolEffect

  // oneshot test
  OneShot,
  
  // activemode
  ActiveModColorEffect

);

/** The 'setup' function is one of the two standard Arduino sketch functions.
   It's called when your keyboard first powers up. This is where you set up
   Kaleidoscope and any plugins.
*/
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  //NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  //AlphaSquare.color = CRGB(255, 0, 0);

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  //LEDRainbowEffect.brightness(150);
  //LEDRainbowWaveEffect.brightness(150);

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  // The LED  mode has a few effects. The one we like is called
  // 'BlazingTrail'. For details on other options, see
  // https://github.com/keyboardio/Kaleidoscope/blob/master/docs/plugins/LED-Stalker.md
  //
  // Haunt(optional color), BlazingTrail, Rainbow
  StalkerEffect.variant = STALKER(Rainbow);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(5);

  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to five layers, which is how
  // many editable layers we have (see above).
  ColormapEffect.max_layers(5);

/* heatmap test
  HeatmapEffect.heat_colors = heat_colors;
  HeatmapEffect.heat_colors_length = 4;
*/

// wavepool test
/*
  // test to set color
  WavepoolEffect.idle_timeout = 0;  // don't like.  don't need. 
  WavepoolEffect.activate();
*/
/*  don't need these colors, I never use them
static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);
*/

  //LEDControl.setCrgbAt(KeyAddr(1,8), CRGB(200, 0, 0));

  // is this necessary to survive a laptop suspend
  //LEDControl.syncLeds() 

  // Oneshot, reduce delay.  default is 2500ms
  OneShot.time_out = 1250;
  // activemod test
  ActiveModColorEffect.highlight_color = CRGB(0x00, 0xff, 0xff);


}
