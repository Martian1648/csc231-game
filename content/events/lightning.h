#pragma once
#include "event.h"
#include "vec.h"
#include "animatedsprite.h"
class Lightning: public Event{
public:
    Lightning(Vec position);
    void execute(Engine& engine) override;

private:
    Vec position;
    AnimatedSprite sprite;
};