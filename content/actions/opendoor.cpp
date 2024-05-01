#include "opendoor.h"
#include "door.h"
#include "engine.h"
#include "updatefov.h"
#include "entity.h"

OpenDoor::OpenDoor(Door d, Vec pos):d{d}, pos{pos}{}
Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    //Vec position = entity->get_position();
    Tile& tile = engine.dungeon.get_tile(pos);

    if(tile.has_door()){
        tile.door->open();
        return success();
    }

    if(tile.door->is_open()){
        engine.events.create_event<UpdateFOV>();
        return success();
    }
}
