#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_knight(hero);

        for (int i = 0; i<2;++i){
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_orc_masked(monster);
            Monsters::make_ogre(monster);
            Monsters::make_muddy(monster);
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
