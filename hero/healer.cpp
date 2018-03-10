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
    unsigned int heal = roll_dice(MIN_HEAL_AMOUNT,MAX_HEAL_AMOUNT);
    deque<hero::Hero*> dq = get_squad()->get_heroes();
    for (deque<hero::Hero*>::const_iterator iter = dq.begin();
    iter!= dq.end();iter++){
        if ((*iter)->is_alive()){
            (*iter)->heal(heal);
        }
    }

    //get_squad()->get_heroes()->
    unsigned int damage = roll_dice(MIN_ATTACK_DAMAGE,MAX_ATTACK_DAMAGE);
    std::cout<< get_name()<<" smites "<< enemy->get_name()<<" for "<<damage<<" points "<<std::endl;
    enemy->take_damage(damage);
    return damage;
};