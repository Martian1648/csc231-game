//
// Created by Marti on 4/22/2024.
//

#include "attack.h"

#include "action.h"
#include "engine.h"
#include "entity.h"
#include "item.h"


Attack::Attack(Entity& defender):defender{defender}{}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    std::shared_ptr<Item> item = attacker->get_current_item();
    item->use(engine, *attacker, defender);
    return success();
}