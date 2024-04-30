//
// Created by Marti on 4/24/2024.
//

#include "spear.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
Spear::Spear(int damage) : Item{"spear"}, damage{damage}{
    type = Damage_Types::Pierce;
}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage, type);
    engine.events.create_event<Thrust>(attacker.get_current_item()->sprite, attacker.get_direction());
}