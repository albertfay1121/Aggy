#ifndef RENDERER_H
#define RENDERER_H

#include "character.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "renderable.h"

class Renderer {
  public:

    Renderer(const std::size_t screen_height, const std::size_t screen_width, const std::size_t grid_height, const std::size_t grid_width);
    ~Renderer();

    void Render(Character &character, std::vector<Renderable*> renderables);
    void UpdateWindowTitle();
    SDL_Renderer* GetRenderer();


  private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    
    const std::size_t _screen_width;
    const std::size_t _screen_height;
    const std::size_t _grid_width;
    const std::size_t _grid_height;


};

#endif