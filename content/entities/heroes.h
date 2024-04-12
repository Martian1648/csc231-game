#pragma once
#include <memory>
#include <entity.h>
namespace Heroes {
    std::unique_ptr<Action> behavior(Engine&, Entity&);
    void make_knight(std::shared_ptr<Entity>& hero);
}
