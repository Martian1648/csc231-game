//
// Created by Marti on 4/19/2024.
//

#include "wander.h"
#include "vec.h"
#include "entity.h"
#include "engine.h"
#include "move.h"
#include "rest.h"

Wander::Wander() {};
Result Wander::perform(Engine& engine,std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);

    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (!tile.is_wall() && !tile.has_entity()) {
            Vec direction = neighbor - position;
            return alternative(Move{direction});
        }
    }
    return alternative(Rest{});
}