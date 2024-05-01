#pragma once
#include "door.h"
#include "action.h"
#include "engine.h"
#include "vec.h"
class OpenDoor : public Action {
public:
    OpenDoor(Door d, Vec pos);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
private:
    Door d;
    Vec pos;
};