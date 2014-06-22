#include <SDL.h>
#include <math.h>
#include <iostream>

#include "sdlbox.h"
#include "world.h"

using namespace std;



int main(int argv, char ** args){


    /* Set transparent pixel as the pixel at (0,0) */
  const char *icon = "icon.bmp";
  SDL_Surface* gIcon = NULL;//The image we will load and show on the screen
  gIcon = SDL_LoadBMP(icon);

    if (gIcon->format->palette) {
        SDL_SetColorKey(gIcon, 1, *(Uint8 *) gIcon->pixels);
    } else {
        switch (gIcon->format->BitsPerPixel) {
        case 15:
            SDL_SetColorKey(gIcon, 1, (*(Uint16 *) gIcon->pixels) & 0x00007FFF);
            break;
        case 16:
            SDL_SetColorKey(gIcon, 1, *(Uint16 *) gIcon->pixels);
            break;
        case 24:
            SDL_SetColorKey(gIcon, 1, (*(Uint32 *) gIcon->pixels) & 0x00FFFFFF);
            break;
        case 32:
            SDL_SetColorKey(gIcon, 1, *(Uint32 *) gIcon->pixels);
            break;
        }
    }


    //INITIALIZATIO


    World * world = new World();
    SdlBox * sdlbox = new SdlBox(world);
 
    int x=0;

   

    while(!(world->quit)){
      sdlbox->Tick();
      //      world->Tick();
      cout << world->quit << "\n";

      x = (x+1)%SCREEN_WIDTH;
      SDL_Rect dest;
      dest.x = x;
      dest.y = (int)(sin((float)x/(float)SCREEN_WIDTH*2.0*3.14)*(SCREEN_HEIGHT/2)+SCREEN_HEIGHT/2);
      cout << dest.x << ", " << dest.y << "\n";
      SDL_BlitSurface( gIcon, NULL, sdlbox->gMainSurface, &dest );

      SDL_Delay( 20 );
  }


    sdlbox->destruct();
    SDL_FreeSurface( gIcon );
    gIcon = NULL;
    //END PROGRAM

  return 0;


}
