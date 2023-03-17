#include <SDL2/SDL.h>
#include <vector>

using namespace std;
#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
public:
  int control = 0;
  int length = 3;
  vector<SDL_Rect> segments;

  Snake(SDL_Renderer *renderer);
  ~Snake();

  void Spawn(int xpos, int ypos);
  void Update();
  void Render();
  void Move();
  void AddSegment();
  bool CheckColision(int xpos, int ypos);

  bool isAlive() { return this->isalive; };


private:
  bool isalive = false;
  SDL_Renderer *renderer;

};

#endif
