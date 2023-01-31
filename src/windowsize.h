#pragma once
#include <sys/ioctl.h>
#include <unistd.h>

namespace _window_internals {
  struct winsize w;
  struct WinSize {
    int rows;
    int columns;
  };
}


namespace window {
  _window_internals::WinSize size = _window_internals::WinSize{0, 0};
  void getSize() {
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &_window_internals::w);
    window::size =  _window_internals::WinSize{
      _window_internals::w.ws_row, 
      _window_internals::w.ws_col 
    };
  };
}