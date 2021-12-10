#ifndef RENDERER_H
#define RENDERER_H

#include "character.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "renderable.h"
#include "resource-manager.h"
#include "gamemap.h"
#include "enemy.h"
#include "SDL2/sdl_ttf.h"
#include <vector>


class Renderer {
  public:
    struct MenuBoxes{
      public:
        MenuBoxes();
        MenuBoxes(SDL_Rect box, bool collision):box_(box), collision_(collision){};
        SDL_Rect box_;
        bool collision_;
    };

    Renderer(const std::size_t screen_height, const std::size_t screen_width, const std::size_t grid_height, const std::size_t grid_width);
    ~Renderer();

    std::vector<std::unique_ptr<Renderable>>&& Render(Character &character, std::vector<std::unique_ptr<Renderable>> &&firedShot, std::vector<std::shared_ptr<Enemy>> &enemies, ResourceManager &resources, GameMap &gamemap);
    void UpdateWindowTitle();
    SDL_Renderer* GetRenderer();
    void EndMenu(ResourceManager &resources, int score, std::vector<MenuBoxes> &menuBoxes);
    void LoadEndMenuBoxes(std::vector<MenuBoxes> &menuBoxes);
    void LoadEndMenuResources(ResourceManager &resources);
    void LoadUI(ResourceManager &resources);
    void RenderUI(ResourceManager &resources, Character &character);


  private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    
    const std::size_t _screen_width;
    const std::size_t _screen_height;
    const std::size_t _grid_width;
    const std::size_t _grid_height;

    SDL_Rect score_rect_;
    SDL_Rect health_bar_outline_;
    SDL_Rect digit_rect_;
    SDL_Rect energy_bar_outline_;
    SDL_Rect play_again_;
    double score_num_place_x_, score_num_place_y_;


};

#endif