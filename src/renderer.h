#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "obstcals.h"


class Renderer : public obstcals
{
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  //void Render(Snake const snake, SDL_Point const &food);
  void Render(Snake const snake, SDL_Point const &food,SDL_Point const &badfood, bool wall );
  void Render(bool& wall);
  void UpdateWindowTitle(int score, int fps);
  //void termnaite();

 private:
 //protected:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

 //friend class obstcals;
 obstcals o;
};

#endif