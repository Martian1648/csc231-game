
#include "sword.h"
#include "engine.h"
#include "hit.h"
Sword::Sword(int damage): Item{"sword"}, damage{damage}{}

void Sword::use(Engine& engine, Entity&d, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage);
}
