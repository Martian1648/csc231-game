#include "move.h"
#include "tile.h"
#include "entity.h"
#include "engine.h"

Move::Move(Vec direction):direction{direction}{}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    Vec new_position = position+direction;
    Tile& tile = engine.dungeon.get_tile(new_position);
    if(tile.is_wall() || tile.has_door() || tile.has_entity()){
        return failure();
    } else{
        entity->change_direction(direction);
        entity->move_to(new_position);
        return success();
    }

}
