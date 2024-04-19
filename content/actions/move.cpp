#include "move.h"
#include "tile.h"
#include "entity.h"
#include "engine.h"
#include "opendoor.h"

Move::Move(Vec direction):direction{direction}{}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    Vec new_position = position+direction;
    Tile& tile = engine.dungeon.get_tile(new_position);
    if(tile.is_wall() || tile.has_entity()) {
        return failure();
    }
    else if(tile.has_door() && !tile.door->is_open()){
      return alternative(OpenDoor{*tile.door, new_position});
   }
    else{
        entity->change_direction(direction);
        entity->move_to(new_position);
        return success();
    }

}
