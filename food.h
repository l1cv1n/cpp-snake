#include <SDL2/SDL.h>

#include "snake.h"

class Food
{
public:
  int xpos,
      ypos;

  Food(SDL_Renderer *renderer);
  ~Food();

  void Spawn(Snake *player);
  void Update(Snake *player);
  void Render();

  bool isExists() { return this->isexists; };


private:
  bool isexists = false;

  SDL_Renderer *renderer;
  SDL_Rect food = {};

};

