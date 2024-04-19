#pragma once
#include "engine.h"
#include "action.h"
namespace Monsters {
    void make_orc_masked(std::shared_ptr<Entity> monster);
    void make_ogre(std::shared_ptr<Entity> monster);
    void make_muddy(std::shared_ptr<Entity> monster);
    std::unique_ptr<Action> behaviora(Engine& engine, Entity& entity);
    std::unique_ptr<Action> behaviorb(Engine& engine, Entity& entity);
    std::unique_ptr<Action> behaviorc(Engine& engine, Entity& entity);
}
