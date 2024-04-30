//
// Created by Marti on 4/22/2024.
//


#include "hit.h"
#include "die.h"
#include "entity.h"
#include "item.h"
#include <cmath>
#include "multipliers.h"
Hit::Hit(Entity& entity, int damage, Damage_Types type)
    :entity{entity}, damage{damage}, type{type} {}
void Hit::execute(Engine&) {
    entity.take_damage(damage* (int)get_multiplier(type, entity.get_weight())); // reduce health
}
void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die{entity}); // remove from game
    }
}
double Hit::get_multiplier(Damage_Types type, Weight weight){
    int index = (3*static_cast<int>(type))+static_cast<int>(weight);
    return round( multipliers.at(index));

}
