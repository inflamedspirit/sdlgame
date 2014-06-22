#ifndef SDLBOX_H
#define SDLBOX_H

#include <SDL.h>
#include "world.h"

#define SCREEN_TITLE "Soccer!"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//const char * SCREEN_TITLE = "Soccer!";


class SdlBox {
 public:
SdlBox(World *);

  World * world;
  SDL_Window* gMainWindow;
  SDL_Surface* gMainSurface;
  SDL_Event event;
  const Uint8 * keystate;

  void destruct();
  void Tick();
};


#endif
