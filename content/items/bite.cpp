#include "bite.h"
#include "engine.h"
#include "hit.h"
#include "item.h"
Bite::Bite(int damage)
    :Item{"none"}, damage{damage} {
    types.push_back(Damage_Type::Pierce);
}

void Bite::use(Engine& engine, Entity&, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage, types);
}
