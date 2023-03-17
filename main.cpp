#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h> // sleep


#include "game.cpp"

Game *game = nullptr;

int main() {

  const int FPS = 4;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  
  game = new Game();

  game->init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

  while(game->running()) {

    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();
    
  return 0;
}
