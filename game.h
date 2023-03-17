#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "utils.h"


class Game
{
  public:
    Game();
    ~Game();

    void init(int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; };

  private:
    bool isRunning;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
};
