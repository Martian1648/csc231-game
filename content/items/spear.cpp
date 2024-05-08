//
// Created by Marti on 4/24/2024.
//

#include "spear.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
Spear::Spear(int damage) : Item{"spear"}, damage{damage}{
    types.push_back(Damage_Type::Pierce);
}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage, types);
    engine.events.create_event<Thrust>(attacker.get_current_item()->sprite, attacker.get_direction());
}