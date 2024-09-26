#ifndef entity_hpp
#define entity_hpp

#define VELOCITY_MULTIPLIER 1

#include <SDL_render.h>

class Texture;
class State;
class CollisionManager;
class Camera;

class Entity
{
public:
    Entity();
    Entity(Texture *texture, SDL_Rect hitBox);
    Entity(Texture *texture, SDL_Rect hitBox, State *state);
    ~Entity();

    void init(Texture *texture, SDL_Rect hitbox, State *state);
    void update(CollisionManager *collisionManager);
    bool canMove();
    bool isMoving();
    void move(CollisionManager *collisionManager);
    void render(Camera *camera);
    void onCollision(Entity *);

    void setVelocity(int velX, int velY);
    void setVelocityX(int velocityX);
    void setVelocityY(int velocityY);

    int getPositionX();
    int getPositionY();
    int getCenterX();
    int getCenterY();
    SDL_Rect getHitBox();
    bool isSolid();

protected:
    Texture *texture;
    int velX, velY;
    SDL_Rect hitBox;
    bool solid;
    
    State *state;
};

#endif