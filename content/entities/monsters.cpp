#include "monsters.h"
#include "sprite.h"
#include "entity.h"
#include "rest.h"
#include "move.h"
#include "wander.h"
#include "engine.h"
#include "randomness.h"
namespace Monsters {
    void make_orc_masked(std::shared_ptr<Entity> monster){
        monster->set_sprite("orc_masked");
        monster->set_max_health(12);
        monster->behavior=behaviora;
    }

    void make_ogre(std::shared_ptr<Entity> monster){
        monster->set_sprite("ogre");
        monster->set_max_health(20);
        monster->behavior=behaviora;
    }


    void make_muddy(std::shared_ptr<Entity> monster){
        monster->set_sprite("muddy");
        monster->set_max_health(2);
        monster->behavior=behaviora;
    }

    std::unique_ptr<Action> behaviora(Engine& engine, Entity& entity){
        if (entity.is_visible() && engine.hero) {
            auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                      engine.hero->get_position());
            if (path.size() > 1) {
                auto direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }
        // Monster doesn't see Hero
        if (probability(66)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
        return std::make_unique<Rest>();
    }
    std::unique_ptr<Action> behaviorb(Engine& engine, Entity& entity){
        if (entity.is_visible() && engine.hero) {
            if(probability(50)) {
                auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                          engine.hero->get_position());
                if (path.size() > 1) {
                    auto direction = path.at(1) - path.at(0);
                    return std::make_unique<Move>(direction);
                }
            }else{
                //the ogre is big and lazy
                return std::make_unique<Rest>();
            }
        }

        return std::make_unique<Rest>();
    }
    std::unique_ptr<Action> behaviorc(Engine& engine, Entity& entity){
        if (entity.is_visible() && engine.hero) {
            auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                      engine.hero->get_position());
            if (path.size() > 1) {
                auto direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }
        // muddy is made of coffee grounds and is very caffinated and active

        return std::make_unique<Wander>();
    }
}
