#pragma once
#include "action.h"
#include "vec.h"

class Move : public Action{
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
    Move(Vec direction);
    Vec direction;
};