//
// Created by Marti on 4/22/2024.
//


#include "hit.h"
#include "die.h"
#include "entity.h"
#include "item.h"
#include <cmath>
#include "multipliers.h"
#include "randomness.h"
Hit::Hit(Entity& entity, int damage, std::vector<Damage_Type>& types)
    :entity{entity}, damage{damage}, types{types} {}
void Hit::execute(Engine&) {
    double total_dam{0};
    for(Damage_Type type:types){
        total_dam += static_cast<double>(damage) * get_multiplier(type, entity.get_weight());
    }
    entity.take_damage(round(total_dam)); // reduce health
}
void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die{entity}); // remove from game
    }
}
double Hit::get_multiplier(Damage_Type type, Weight weight){
    if(weight == Weight::Light){
        if(probability(50)){
            return 0.0;
        }

    }
    int index = (3*static_cast<int>(type)+static_cast<int>(weight));
    return ( multipliers.at(index));

}
