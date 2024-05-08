#pragma once
#include "item.h"

class Cleaver : public Item{
public:
    explicit Cleaver(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;
private:
    int damage;
};