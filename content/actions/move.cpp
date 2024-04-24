#include "move.h"
#include "tile.h"
#include "entity.h"
#include "engine.h"
#include "opendoor.h"
#include "attack.h"
#include "rest.h"

Move::Move(Vec direction):direction{direction}{}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    Vec new_position = position+direction;
    Tile& tile = engine.dungeon.get_tile(new_position);
    if(tile.is_wall()) {
        return failure();
    }
    else if(tile.has_door() && !tile.door->is_open()){
      return alternative(OpenDoor{*tile.door, new_position});
   }
    else if(tile.has_entity()){
       if(entity->get_team() != tile.entity->get_team()){
           return alternative(Attack{*tile.entity});
       }else{
           return alternative(Rest());
       }
   }
    else{
        entity->change_direction(direction);
        entity->move_to(new_position);
        return success();
    }

}
