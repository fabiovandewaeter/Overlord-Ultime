#include "Structure.hpp"

Structure::Structure() {}
/*Structure::Structure(Texture *texture, unsigned int HP, bool solid)
{
    init(texture, HP, solid);
}
Structure::Structure(Texture *texture, SDL_Rect hitBox, unsigned int HP, bool solid)
{
    init(texture, hitBox, HP, solid);
}*/
Structure::~Structure() {}

void Structure::init(Texture *texture, unsigned int HP, bool solid)
{
    this->texture = texture;
    this->HP = HP;
    this->solid = solid;
}
void Structure::init(Texture *texture, SDL_Rect hitBox, unsigned int HP, bool solid)
{
    init(texture, HP, solid);
    this->hitBox = hitBox;
}

void Structure::render(Camera *camera)
{
    SDL_Rect renderBox = this->hitBox;
    camera->convertInGameToCameraCoordinates(renderBox);
    if (camera->isVisible(renderBox))
    {
        this->texture->render(renderBox);
    }
}

void Structure::destroy()
{
    delete this;
}

SDL_Rect Structure::getHitBox()
{
    return this->hitBox;
}
bool Structure::isSolid()
{
    return this->solid;
}
void Structure::setHitBox(SDL_Rect hitBox)
{
    this->hitBox = hitBox;
}