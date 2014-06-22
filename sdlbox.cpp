#include "sdlbox.h"
#include <iostream>

using namespace std;

SdlBox::SdlBox(World * wor){
  world=wor;
  SDL_Init( SDL_INIT_VIDEO );
  gMainWindow = SDL_CreateWindow( SCREEN_TITLE,
			      SDL_WINDOWPOS_UNDEFINED,
			      SDL_WINDOWPOS_UNDEFINED,
			      SCREEN_WIDTH,
			      SCREEN_HEIGHT,
			      SDL_WINDOW_SHOWN );

  gMainSurface = SDL_GetWindowSurface( gMainWindow );

}

void SdlBox::destruct(){
  SDL_DestroyWindow( gMainWindow );
  gMainWindow = NULL;
  SDL_Quit();
}

void SdlBox::Tick(){

  keystate = SDL_GetKeyboardState(NULL);
  while( SDL_PollEvent( &event )){
    if( event.type == SDL_QUIT ){
      world->quit = true;
    }
  }

  SDL_UpdateWindowSurface( gMainWindow );    

}
