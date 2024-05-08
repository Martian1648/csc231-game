
#include "sword.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"
#include "entity.h"
#include "lightning.h"
#include "settings.h"
#include "audio.h"
#include "sound.h"
Sword::Sword(int damage): Item{"sword"}, damage{damage}
{
    types.push_back(Damage_Type::Cut);
    types.push_back(Damage_Type::Electric);
}

void Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
    //engine.events.create_event<Hit>(defender, damage, type);
    //engine.events.create_event<Swing>(attacker.get_current_item()->sprite, attacker.get_direction());
    //engine.events.create_event<Lightning>(attacker.get_direction()+attacker.get_position());
    auto swing = engine.events.create_event<Swing>(attacker.get_current_item()->sprite, attacker.get_direction());
    std::shared_ptr<Event> lightning = std::make_shared<Lightning>(attacker.get_direction()+attacker.get_position());
    engine.events.create_event<Sound>("thunder");
    lightning->add_next(Hit{defender, damage, types});
    swing->add_next(lightning);
}
