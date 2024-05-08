#pragma once
#include "item.h"

class Hammer_Big : public Item{
public:
    explicit Hammer_Big(int damage);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};