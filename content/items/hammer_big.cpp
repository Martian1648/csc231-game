//
// Created by Marti on 5/6/2024.
//

#include "hammer_big.h"
#include "swing.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
Hammer_Big::Hammer_Big(int damage) : Item{"hammer_big"}, damage{damage}{
    types.push_back(Damage_Type::Blunt);
}

void Hammer_Big::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto swing = engine.events.create_event<Swing>(attacker.get_current_item()->sprite, attacker.get_direction());
    swing->add_next(Hit(defender, damage, types));

}