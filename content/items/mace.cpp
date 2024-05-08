//
// Created by Marti on 4/24/2024.
//

#include "mace.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"
#include "entity.h"
Mace::Mace(int damage) : Item{"mace"}, damage{damage}{
    types.push_back( Damage_Type::Blunt);
}

void Mace::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage, types);
    engine.events.create_event<Swing>(attacker.get_current_item()->sprite, attacker.get_direction());
}