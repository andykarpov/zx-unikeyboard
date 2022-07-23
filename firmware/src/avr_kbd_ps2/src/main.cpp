/*
 * This is an AVR firmware source code for ZX Unikeyboard PS/2 controller.
 * Needs to be recompiled for any keyboard after building your own customkey.h with ZX Unikeyboard configuration tool
 * 
 * Based on AVR keyboard firmware for ps2_cpld_kbd project
 * @author Andy Karpov <andy.karpov@gmail.com>
 * Ukraine, 2019
 * 
 * Ported to ATMega32 and redesigned for custom keyboard matrix by Valeriy Matveyev
 * valerium@rambler.ru
 * Russia, 2021
 * 
 * Added PS/2 output (PB6, PB7) instead of CPLD via SPI, moved to the platformio rails by:
 * andy.karpov@gmail.com
 * Ukraine, 2021 
 */

#include <Arduino.h>
#include "config.h"
#include "customkey.h"
#include "ps2dev.h"

//MCU pins array to search by keyboard pin number
const uint8_t pins[] = {
  0xFF, IO1, IO2, IO3, IO4, IO5, IO6, IO7, IO8, IO9, IO10,
  IO11, IO12, IO13, IO14, IO15, IO16, IO17, IO18, IO19, IO20,
  IO21, IO22, IO23, IO24, IO25, IO26
};

uint8_t keyaddr_mapped[COLS_MAX][ROWS_MAX]; // mapped keyaddr array by col/row indicies
bool matrix[MATRIX_SIZE]; // matrix of pressed keys

PS2dev kbd(PIN_PB6, PIN_PB7);  // PS2dev object (PB6:data, PB7:clock)
unsigned long tl = 0; // last time led was blinked
bool is_fn = false; // is FN key pressed

// methods declaration
void clear_matrix(int clear_size);
void kbd_do(unsigned char code, bool state);
void kbd_do_special(unsigned char code, bool state);
void kbd_event(uint8_t key, bool state);
void setup_keyaddr_mapped();
void poll_matrix();
void setup();
void loop();

// clear the entire matrix of pressed keys
void clear_matrix(int clear_size)
{
    // release all keys
  for (int i=0; i<clear_size; i++) {
      matrix[i] = RELEASED;
  }
}

// press/release a normal key
void kbd_do(unsigned char code, bool state) {
  if (state) {
    kbd.keyboard_press(code); 
  } else {
    kbd.keyboard_release(code);
  }
}

// press/release a special key
void kbd_do_special(unsigned char code, bool state) {
  if (state) {
    kbd.keyboard_press_special(code);
  } else {
    kbd.keyboard_release_special(code);
  }
}

// trigger a ps/2 event for key with state
void kbd_event(uint8_t key, bool state)
{
#if DEBUG_MODE==1
  Serial.print(state ? F("Pressed key: ") : F("Released key: "));
  Serial.println(key, HEX);
#endif
  switch (key) 
  {
    // Letters & numbers
    case KEY_A: kbd_do(kbd.ScanCodes::A, state); break;
    case KEY_B: kbd_do(kbd.ScanCodes::B, state); break;
    case KEY_C: kbd_do(kbd.ScanCodes::C, state); break;
    case KEY_D: kbd_do(kbd.ScanCodes::D, state); break;
    case KEY_E: kbd_do(kbd.ScanCodes::E, state); break;
    case KEY_F: kbd_do(kbd.ScanCodes::F, state); break;
    case KEY_G: kbd_do(kbd.ScanCodes::G, state); break;
    case KEY_H: kbd_do(kbd.ScanCodes::H, state); break;
    case KEY_I: kbd_do(kbd.ScanCodes::I, state); break;
    case KEY_J: kbd_do(kbd.ScanCodes::J, state); break;
    case KEY_K: kbd_do(kbd.ScanCodes::K, state); break;
    case KEY_L: kbd_do(kbd.ScanCodes::L, state); break;
    case KEY_M: kbd_do(kbd.ScanCodes::M, state); break;
    case KEY_N: kbd_do(kbd.ScanCodes::N, state); break;
    case KEY_O: kbd_do(kbd.ScanCodes::O, state); break;
    case KEY_P: kbd_do(kbd.ScanCodes::P, state); break;
    case KEY_Q: kbd_do(kbd.ScanCodes::Q, state); break;
    case KEY_R: kbd_do(kbd.ScanCodes::R, state); break;
    case KEY_S: kbd_do(kbd.ScanCodes::S, state); break;
    case KEY_T: kbd_do(kbd.ScanCodes::T, state); break;
    case KEY_U: kbd_do(kbd.ScanCodes::U, state); break;
    case KEY_V: kbd_do(kbd.ScanCodes::V, state); break;
    case KEY_W: kbd_do(kbd.ScanCodes::W, state); break;
    case KEY_X: kbd_do(kbd.ScanCodes::X, state); break;
    case KEY_Y: kbd_do(kbd.ScanCodes::Y, state); break;
    case KEY_Z: kbd_do(kbd.ScanCodes::Z, state); break;

    // digits
    case KEY_0: kbd_do(kbd.ScanCodes::ZERO, state); break;
    case KEY_1: kbd_do(kbd.ScanCodes::ONE, state); break;
    case KEY_2: kbd_do(kbd.ScanCodes::TWO, state); break;
    case KEY_3: kbd_do(kbd.ScanCodes::THREE, state); break;
    case KEY_4: kbd_do(kbd.ScanCodes::FOUR, state); break;
    case KEY_5: kbd_do(kbd.ScanCodes::FIVE, state); break;
    case KEY_6: kbd_do(kbd.ScanCodes::SIX, state); break;
    case KEY_7: kbd_do(kbd.ScanCodes::SEVEN, state); break;
    case KEY_8: kbd_do(kbd.ScanCodes::EIGHT, state); break;
    case KEY_9: kbd_do(kbd.ScanCodes::NINE, state); break;

    // Others
    case KEY_FN: is_fn = state; break;
    case KEY_LSHIFT: kbd_do(kbd.ScanCodes::LEFT_SHIFT, state); break;
    case KEY_LCTRL: kbd_do(kbd.ScanCodes::LEFT_CONTROL, state); break;
    case KEY_RSHIFT: kbd_do(kbd.ScanCodes::RIGHT_SHIFT, state); break;
    case KEY_RCTRL: kbd_do_special(kbd.SpecialScanCodes::RIGHT_CONTROL, state); break;
    case KEY_RCTRL2: kbd_do(kbd.ScanCodes::LEFT_SHIFT, state); break;
    case KEY_LALT: kbd_do(kbd.ScanCodes::LEFT_ALT, state); break;
    case KEY_RALT: kbd_do_special(kbd.SpecialScanCodes::RIGHT_ALT, state); break;
    case KEY_INSERT: 
      if (state) {
        if (is_fn) {
          kbd.keyboard_press_printscreen();
        } else {
          kbd_do_special(kbd.SpecialScanCodes::INSERT, state); 
        }
      } else {
        kbd_do_special(kbd.SpecialScanCodes::INSERT, false); 
        kbd.keyboard_release_printscreen();
      }
      break;
    case KEY_DELETE: kbd_do_special(kbd.SpecialScanCodes::DELETE, state); break;
    case KEY_ACCENT: kbd_do(kbd.ScanCodes::ACCENT, state); break;
    case KEY_UP: kbd_do_special(kbd.SpecialScanCodes::UP_ARROW, state); break;
    case KEY_DOWN: kbd_do_special(kbd.SpecialScanCodes::DOWN_ARROW, state); break;
    case KEY_LEFT: kbd_do_special(kbd.SpecialScanCodes::LEFT_ARROW, state); break;
    case KEY_RIGHT: kbd_do_special(kbd.SpecialScanCodes::RIGHT_ARROW, state); break;
    case KEY_PGUP: 
      if (state) {
        if (is_fn) {
          kbd.keyboard_pausebreak();
        } else {
          kbd_do_special(kbd.SpecialScanCodes::PAGE_UP, state);
        }
      } else {
        kbd_do_special(kbd.SpecialScanCodes::PAGE_UP, state);
      } 
    break;
    case KEY_PGDN: kbd_do_special(kbd.SpecialScanCodes::PAGE_DOWN, state); break;
    case KEY_HOME: 
      if (state) {
        if (is_fn) {
          kbd_do(kbd.ScanCodes::SCROLL_LOCK, state); 
        } else {
          kbd_do_special(kbd.SpecialScanCodes::HOME, state);
        }
      } else {
        kbd_do(kbd.ScanCodes::SCROLL_LOCK, false); 
        kbd_do_special(kbd.SpecialScanCodes::HOME, false);
      } 
    break;
    case KEY_END: kbd_do_special(kbd.SpecialScanCodes::END, state); break;
    case KEY_ESC: kbd_do(kbd.ScanCodes::ESCAPE, state); break;
    case KEY_BACKSPACE: kbd_do(kbd.ScanCodes::BACKSPACE, state); break;
    case KEY_ENTER: kbd_do(kbd.ScanCodes::ENTER, state); break;
    case KEY_SPACE: kbd_do(kbd.ScanCodes::SPACE, state); break;
    case KEY_TAB: kbd_do(kbd.ScanCodes::TAB, state); break;    
    case KEY_CAPSLOCK: kbd_do(kbd.ScanCodes::CAPS_LOCK, state); break;
    case KEY_EQUAL: kbd_do(kbd.ScanCodes::EQUAL, state); break;
    case KEY_MINUS: kbd_do(kbd.ScanCodes::MINUS, state); break;
    case KEY_LBRACKET: kbd_do(kbd.ScanCodes::OPEN_BRACKET, state); break;
    case KEY_RBRACKET: kbd_do(kbd.ScanCodes::CLOSE_BRACKET, state); break;
    case KEY_COMMA: kbd_do(kbd.ScanCodes::COMMA, state); break;
    case KEY_PERIOD: kbd_do(kbd.ScanCodes::PERIOD, state); break;
    case KEY_SEMICOLON: kbd_do(kbd.ScanCodes::SEMI_COLON, state); break;
    case KEY_QUOTE: kbd_do(kbd.ScanCodes::TICK_MARK, state); break;
    case KEY_SLASH: kbd_do(kbd.ScanCodes::SLASH, state); break;
    case KEY_BACKSLASH: kbd_do(kbd.ScanCodes::BACKSLASH, state); break;
//    case KEY_PRTSCR: if (state) { kbd.keyboard_press_printscreen(); } else { kbd.keyboard_release_printscreen(); } break;
//    case KEY_PAUSE: kbd.keyboard_pausebreak(); break;
//    case KEY_SCROLLLOCK: kbd_do(kbd.ScanCodes::SCROLL_LOCK, state); 
    //case KEY_CONTEXTMENU: kbd_do_special(kbd.SpecialScanCodes::MENUS, state); break;
    case KEY_CONTEXTMENU: kbd_do_special(kbd.SpecialScanCodes::RIGHT_CONTROL, state); break;
    case KEY_GUI: kbd_do_special(kbd.SpecialScanCodes::LEFT_WIN, state); break;

    // F keys
    case KEY_F1: kbd_do(kbd.ScanCodes::F1, state); break;
    case KEY_F2: kbd_do(kbd.ScanCodes::F2, state); break;
    case KEY_F3: kbd_do(kbd.ScanCodes::F3, state); break;
    case KEY_F4: kbd_do(kbd.ScanCodes::F4, state); break;
    case KEY_F5: kbd_do(kbd.ScanCodes::F5, state); break;
    case KEY_F6: kbd_do(kbd.ScanCodes::F6, state); break;
    case KEY_F7: kbd_do(kbd.ScanCodes::F7, state); break;
    case KEY_F8: kbd_do(kbd.ScanCodes::F8, state); break;
    case KEY_F9: kbd_do(kbd.ScanCodes::F9, state); break;
    case KEY_F10: kbd_do(kbd.ScanCodes::F10, state); break;
    case KEY_F11: kbd_do(kbd.ScanCodes::F11, state); break;
    case KEY_F12: kbd_do(kbd.ScanCodes::F12, state); break;
  }
}

// setup indexed keyaddr_mapped array by col/row indicies
void setup_keyaddr_mapped()
{
  for(uint8_t i = 0; i < sizeof(keyaddr)/3; i++) {
    uint8_t col = 0;
    uint8_t row = 0;
    // thekey
    uint8_t thekey = keyaddr[i][0];
    // find col index
    for (uint8_t j=0; j<COLS_MAX; j++) {
      if ((keyaddr[i][1] == cols[j]) || (keyaddr[i][2] == cols[j])) {
        col = j;
      }
    }
    // find row index
    for (uint8_t j=0; j<ROWS_MAX; j++) {
      if ((keyaddr[i][1] == rows[j]) || (keyaddr[i][2] == rows[j])) {
        row = j;
      }
    }
    keyaddr_mapped[col][row] = thekey;
  }
}

// poll matrix 
void poll_matrix()
{
  uint8_t i, current_col, current_row, thekey;

  //all keys polling cycle
  for (current_col = 0; current_col < COLS_MAX; current_col++) {
    
    // set columns into Z state
    for (i = 0; i < COLS_MAX; i++) {
      pinMode(pins[cols[i]], INPUT_PULLUP);
    }

    // set current col to 0
    pinMode(pins[cols[current_col]], OUTPUT);
    digitalWrite(pins[cols[current_col]], LOW);
    
    // reading rows (pressed key = 0)
    for (current_row = 0; current_row < ROWS_MAX; current_row++) {

      thekey = keyaddr_mapped[current_col][current_row];

      uint8_t pin = pins[rows[current_row]];
      if (digitalRead(pin) == LOW) {
        // pressed key
        if ((matrix[thekey] != PRESSED)) {
            matrix[thekey] = PRESSED;
            // transmit press event
            kbd_event(thekey, PRESSED);
            tl = millis();
        }
      } else {
        // released key
        if ((matrix[thekey] != RELEASED)) {
            matrix[thekey] = RELEASED;
            // transmit release event
            kbd_event(thekey, RELEASED);
        }
      }
    }
  }
}

// initial setup
void setup()
{
#if DEBUG_MODE==1
  Serial.begin(115200);
  Serial.flush();
#endif

  for (uint8_t i=0; i<ROWS_MAX; i++) pinMode (pins[rows[i]], INPUT_PULLUP);
  for (uint8_t i=0; i<COLS_MAX; i++) pinMode (pins[cols[i]], INPUT_PULLUP); 

  // clear full matrix
  clear_matrix(MATRIX_SIZE);

  // setup keyaddr_mapped array
  setup_keyaddr_mapped();

#if DEBUG_MODE==1
  Serial.println(F("ZX unikeyboard PS/2 controller v1.0"));
#endif

  // send the keyboard start up
  kbd.keyboard_init();
}

// main loop
void loop()
{
  unsigned char leds = 0;

  // ps/2 keyboard handle every 10ms
  kbd.keyboard_handle(&leds);

  // poll matrix
  poll_matrix();  
}
