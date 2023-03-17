#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include <time.h>

#include "food.h"
#include "snake.h"


void Food::Spawn(Snake *player) {
  srand(time(NULL));
  do {
  this->xpos = rand() % 19 * 40;
  this->ypos = rand() % 19 * 40;

  }
  while(player->CheckColision(this->xpos, this->ypos));

  this->food = {this->xpos, this->ypos, 40, 40};

  this->isexists = true;
}


void Food::Update(Snake *player) {
  if(player->segments[0].x == this->xpos && player->segments[0].y == this->ypos) {
    this->Spawn(player);
    player->AddSegment();
  }
  this->food = {xpos,ypos,40,40};
}


void Food::Render() {
  SDL_SetRenderDrawColor(this->renderer, 211, 44, 54, 255);
  SDL_RenderFillRect(this->renderer, &this->food);
}


Food::Food(SDL_Renderer* renderer) {
  this->renderer = renderer;
}


Food::~Food() {
}
