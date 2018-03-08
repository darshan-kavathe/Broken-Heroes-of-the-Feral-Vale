//
// Created by darsh on 3/1/2018.
//

#include "healer.h"
#include "team.h"
#include "role.h"
#include "hero.h"
#include "heroes.h"

using hero::Team;
using hero::Healer;
using game::Squad;
using hero::Role;
using hero::Hero;
using hero::Heroes;

Healer::Healer(Team::Name team, game::Squad *squad):
        Hero(Heroes::getName(Role::Type::HEALER,team),
             HIT_POINTS,
             Role(Role::Type::HEALER),
             squad){
};

unsigned int Healer::attack(Hero *enemy){
    unsigned int damage = roll_dice(MIN_ATTACK_DAMAGE,MAX_ATTACK_DAMAGE);
    cout<< get_name()<<" slashes "<< enemy->get_name()<<" for "<<damage<<" points "<<endl;
    enemy->take_damage(damage);
    return damage;
};