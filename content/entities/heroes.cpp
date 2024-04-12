#include "heroes.h"
#include "engine.h"
#include "rest.h"
#include "move.h"
namespace Heroes {
    std::unique_ptr<Action> behavior(Engine& engine, Entity&){
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
        }
        return nullptr;
    }
    void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(10);
        hero->behavior=behavior;
    }
}
