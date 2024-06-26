#include "heroes.h"
#include "engine.h"
#include "rest.h"
#include "move.h"
#include "closedoor.h"
#include "sword.h"
#include "spear.h"
#include "mace.h"
namespace Heroes {
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity){
        std::string key = engine.input.get_last_keypress();
        if(key == "W"){
            return std::make_unique<Move>(Vec{0,1});
        }else if(key=="A"){
            return std::make_unique<Move>(Vec{-1,0});
        }else if(key=="S"){
            return std::make_unique<Move>(Vec{0,-1});
        }else if(key=="D"){
            return std::make_unique<Move>(Vec{1,0});
        }else if(key=="SPACE"){
            return std::make_unique<Rest>();
        }else if(key=="C"){
            return std::make_unique<CloseDoor>();
        }
        else if (!key.empty() && std::isdigit(key.at(0))){
            int item_num = std::stoi(key) - 1; // "1" -> index 0
            entity.select_item(item_num);
        }
        return nullptr;
    }
    void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(20);
        hero->add_to_inventory(std::make_shared<Sword>(8));
        hero->add_to_inventory(std::make_shared<Spear>(8));
        hero->add_to_inventory(std::make_shared<Mace>(8));
        hero->set_weight(Weight::Medium);
        hero->behavior=behavior;

    }
}
