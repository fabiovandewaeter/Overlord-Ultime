#ifndef effect_hpp
#define effect_hpp

#include <vector>

class Entity;

class Effect
{
public:
    Effect();
    ~Effect();

    virtual void applyEffect(Entity *entity) = 0;
    void applyEffect(std::vector<Entity *> entities);

protected:
};

#endif