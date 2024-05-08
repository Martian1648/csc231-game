#pragma once
#include "event.h"
#include "item.h"
#include <vector>
#include "entity.h"

class Entity;

class Hit : public Event{
public:
    Hit(Entity& entity, int damage, std::vector<Damage_Type>& types);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
    double get_multiplier(Damage_Type type, Weight weight);
private:
    Entity& entity;
    int damage;
    std::vector<Damage_Type>& types;
};