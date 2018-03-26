//
// Created by Darshan Kavathe on 3/1/2018.
//

#include <iostream>
#include "fighter.h"
#include "../game/squad.h"
#include "team.h"
#include "role.h"
#include "heroes.h"
#include "hero.h"

using hero::Team;
using hero::Fighter;
using game::Squad;
using hero::Role;

using std::cout;
using std::endl;

Fighter::Fighter	(Team::Name team, game::Squad *squad):
        Hero(Heroes::getName(Role::Type::FIGHTER,team),
        HIT_POINTS,
        Role(Role::Type::FIGHTER),
        squad){
}

unsigned int Fighter::attack(Hero *enemy){
    unsigned int damage = roll_dice(MIN_ATTACK_DAMAGE,MAX_ATTACK_DAMAGE);
    cout<< get_name()<<" slashes "<< enemy->get_name()<<" for "<<damage<<" points "<<endl;
    enemy->take_damage(damage);
    return damage;
}
