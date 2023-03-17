#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include "game.h"
#include "snake.cpp"
#include "food.cpp"

#include <iostream>

using namespace std;

Snake *player;
Food *food;


void Game::init(int xpos, int ypos, int width, int height, bool fullscreen) {
  int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

  this->window = SDL_CreateWindow("Snake", xpos, ypos, width, height, flags);

  this->renderer = SDL_CreateRenderer(this->window, -1, 0);
  // SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);

  this->isRunning = true;

  player = new Snake(this->renderer);
  player->Spawn(400,400);

  food = new Food(this->renderer);
  food->Spawn(player);

  // SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type) {
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym) {

        case SDLK_UP: 
          if(player->control != 1)
            player->control = 3;
          break;

        case SDLK_LEFT: 
          if(player->control != 0)
            player->control = 2;
          break;

        case SDLK_DOWN: 
          if(player->control !=3)
            player->control = 1;
          break;

        case SDLK_RIGHT: 
          if(player->control != 2)
            player->control = 0;
          break;

        default:
          break;
      }
      break;

    case SDL_QUIT: 
      isRunning = false;
      break;

    default:
      break;
  }
}

void Game::update() {

  player->Update();
  if(!player->isAlive()) this->isRunning = false;

  food->Update(player);

  handleEvents();
}

void Game::render() {
  SDL_SetRenderDrawColor(this->renderer, 0,0,0,255);
  SDL_RenderClear(this->renderer);

  player->Render();
  food->Render();


  SDL_RenderPresent(this->renderer);
}

void Game::clean() {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  SDL_Quit();
}

Game::Game()
{
  // this->window = SDL_CreateWindow("GAME",
                                  // SDL_WINDOWPOS_CENTERED, 
                                  // SDL_WINDOWPOS_CENTERED, 
                                  // SCREEN_WIDTH, 
                                  // SCREEN_HEIGHT, 
                                  // 0);

  // this->renderer = SDL_CreateRenderer(this->window, -1, 0);
}

Game::~Game()
{
  // SDL_DestroyWindow(this->window);
  // SDL_DestroyRenderer(this->renderer);
  // SDL_Quit();
}

