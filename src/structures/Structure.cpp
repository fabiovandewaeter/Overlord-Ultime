#include "Structure.hpp"
#include "../systems/Camera.hpp"
#include "../Texture.hpp"

Structure::Structure(Texture *texture, SDL_Rect hitBox, unsigned int HP, bool solid)
{
    this->texture = texture;
    this->hitBox = hitBox;
    this->HP = HP;
    this->solid = solid;
}
Structure::~Structure() {}

void Structure::render(Camera *camera)
{
    SDL_Rect renderBox = this->hitBox;
    camera->convertInGameToCameraCoordinates(renderBox);
    if (camera->isVisible(renderBox))
    {
        this->texture->render(renderBox);
    }
}

void Structure::update() {}
void Structure::destroy() { delete this; }
void Structure::onCollision(Entity *entity) { std::cout << "Structure#onCollision()" << std::endl; }
void Structure::onClick() { std::cout << "pas bon" << std::endl; }

SDL_Rect Structure::getHitBox() { return this->hitBox; }
bool Structure::isSolid() { return this->solid; }
void Structure::setHitBox(SDL_Rect hitBox) { this->hitBox = hitBox; }