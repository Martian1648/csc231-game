#pragma once
#include "item.h"

class Mace : public Item{
public:
    explicit Mace(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;
private:
    int damage;

};