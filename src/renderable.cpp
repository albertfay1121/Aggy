#include "renderable.h"
#include <iostream>

bool Renderable::Exists(){
    return true;
};

void Renderable::RenderRenderable(SDL_Renderer* renderer){
    std::cout << "This needs to be implemented" << std::endl;
}

void Renderable::Update() {
    std::cout << "this needs to be implemented" << std:: endl;
}