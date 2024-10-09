#ifndef structure_hpp
#define structure_hpp

#include <SDL.h>
#include <string>

class Texture;
class Camera;
class Entity;
class CollisionManager;

class Structure
{
public:
    Structure(Texture *texture, SDL_Rect hitBox, unsigned int HP, bool solid);
    ~Structure();

    void update();
    void destroy();
    void render(Camera *camera);
    void onCollision(Entity *entity);
    virtual void onClick();

    SDL_Rect getHitBox();
    bool isSolid();
    bool isActive();
    void setHitBox(SDL_Rect hitBox);

protected:
    SDL_Rect hitBox;
    Texture *texture;
    bool solid;
    unsigned int HP;
};

#endif