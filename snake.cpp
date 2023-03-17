#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "snake.h"

void Snake::Spawn(int xpos, int ypos) {
  this->segments.push_back( {xpos, ypos, 40, 40} );
  this->segments.push_back( {xpos-40, ypos, 40, 40} );
  this->segments.push_back( {xpos-80, ypos, 40, 40} );

  this->isalive = true;

}


void Snake::Update() { 
  this->Move();
  if(this->segments[0].x == 800 || this->segments[0].x == -40 || this->segments[0].y == 800 || this->segments[0].y == -40) this->isalive = false;
  for(int i = length - 1; i > 0; --i)
    if(this->segments[0].x == this->segments[i].x && this->segments[0].y == this->segments[i].y) this->isalive = false;
}

void Snake::Move() {
  for(int i = this->length-1; i > 0; --i) {
    this->segments[i].x = segments[i-1].x;
    this->segments[i].y = segments[i-1].y;
  }

  switch(this->control) {
    case 1: 
      this->segments[0].y += 40;
      break;
      
    case 2: 
      this->segments[0].x -= 40;
      break;

    case 3: 
      this->segments[0].y -= 40;
      break;

    case 0: 
      this->segments[0].x += 40;
      break;
  }
}


void Snake::Render() {
  SDL_SetRenderDrawColor(this->renderer, 11, 120, 27, 255);

  for(int i = length - 1; i > -1; --i) {
    SDL_RenderFillRect(this->renderer, &this->segments[i]);
  }
}

bool Snake::CheckColision(int xpos, int ypos) {
  for(int i = length - 1; i >= 0; --i )
    if(this->segments[i].x == xpos || this->segments[i].y == ypos) return true;

  return false;
}

void Snake::AddSegment() {
  this->segments.push_back( {segments[length-1].x, segments[length-1].y, 40, 40} );
  ++this->length;
}

Snake::Snake(SDL_Renderer* renderer) {
  this->renderer = renderer;
}


Snake::~Snake() {
}
