#pragma once
#include "event.h"
#include "item.h"
#include <vector>
#include "entity.h"

class Entity;

class Hit : public Event{
public:
    Hit(Entity& entity, int damage, Damage_Types type);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
    double get_multiplier(Damage_Types type, Weight weight);
private:
    Entity& entity;
    int damage;
    Damage_Types type;
};