#pragma once
#include "./internals.h"

namespace ansi {
  struct ANSIControlInterface {
    char* Reset;
    char* Bold;
    char* Italic;
    char* Dim;
    char* Underscore;
    char* Blink;
    char* Reverse;
    char* Hidden;
    char* Strikethrough;
  };
  struct ANSIForegroundInterface {
    char* Black;
    char* Red;
    char* Green;
    char* Yellow;
    char* Blue;
    char* Magenta;
    char* Cyan;
    char* White;
    char* RGB(int r, int g, int b) {
      return _ansi_internals::concat((char*)"\x1b[38;2;", _ansi_internals::concat(_ansi_internals::intToString(r), _ansi_internals::concat((char*)";", _ansi_internals::concat(_ansi_internals::intToString(g), _ansi_internals::concat((char*)";", _ansi_internals::concat(_ansi_internals::intToString(b), (char*)"m"))))));
    };
  };
  struct ANSIBackgroundInterface {
    char* Black;
    char* Red;
    char* Green;
    char* Yellow;
    char* Blue;
    char* Magenta;
    char* Cyan;
    char* White;
    char* RGB(int r, int g, int b) {
      return _ansi_internals::concat((char*)"\x1b[48;2;", _ansi_internals::concat(_ansi_internals::intToString(r), _ansi_internals::concat((char*)";", _ansi_internals::concat(_ansi_internals::intToString(g), _ansi_internals::concat((char*)";",   _ansi_internals::concat(_ansi_internals::intToString(b), (char*)"m"))))));
    };
  };

  struct ANSIInterface {
    ANSIControlInterface control;
    ANSIForegroundInterface fg;
    ANSIBackgroundInterface bg;
  };

  ANSIInterface ANSI = ANSIInterface{
    ANSIControlInterface{
      (char*)"\x1b[0m", // Reset
      (char*)"\x1b[1m", // Bold
      (char*)"\x1b[3m", // Italic
      (char*)"\x1b[2m", // Dim
      (char*)"\x1b[4m", // Underline
      (char*)"\x1b[5m", // Blink
      (char*)"\x1b[7m", // Reverse
      (char*)"\x1b[8m", // Hidden
      (char*)"\x1b[9m"  // Strikethrough
    },
    ANSIForegroundInterface{
      (char*)"\x1b[30m", // Black
      (char*)"\x1b[31m", // Red
      (char*)"\x1b[32m", // Green
      (char*)"\x1b[33m", // Yellow
      (char*)"\x1b[34m", // Blue
      (char*)"\x1b[35m", // Magenta
      (char*)"\x1b[36m", // Cyan
      (char*)"\x1b[37m"  // White
    },
    ANSIBackgroundInterface{
      (char*)"\x1b[40m", // Black
      (char*)"\x1b[41m", // Red
      (char*)"\x1b[42m", // Green
      (char*)"\x1b[43m", // Yellow
      (char*)"\x1b[44m", // Blue
      (char*)"\x1b[45m", // Magenta
      (char*)"\x1b[46m", // Cyan
      (char*)"\x1b[47m"  // White
    }
  };
}