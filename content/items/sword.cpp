
#include "sword.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"
#include "entity.h"
#include "lightning.h"
#include "settings.h"
#include "audio.h"
Sword::Sword(int damage): Item{"sword"}, damage{damage}
{
    type=Damage_Types::Cut;
}

void Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage, type);
    engine.events.create_event<Swing>(attacker.get_current_item()->sprite, attacker.get_direction());
    engine.events.create_event<Lightning>(attacker.get_direction()+attacker.get_position());
}
