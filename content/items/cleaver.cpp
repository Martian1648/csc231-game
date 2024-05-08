//
// Created by Marti on 5/6/2024.
//

#include "cleaver.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "swing.h"

Cleaver::Cleaver(int damage) : Item("cleaver"), damage{damage}{
    types.push_back(Damage_Type::Cut);
}

void Cleaver::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto swing = engine.events.create_event<Swing>(attacker.get_current_item()->sprite, attacker.get_direction());
    swing->add_next(Hit{defender, damage, types});
}