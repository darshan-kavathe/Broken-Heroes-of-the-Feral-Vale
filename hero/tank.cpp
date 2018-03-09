//
// Created by darsh on 3/1/2018.
//

#include "tank.h"
#include "../game/squad.h"
#include "team.h"
#include "heroes.h"
#include "cmath"

using hero::Team;
using hero::Tank;
using game::Squad;

const double Tank::SHIELD_DAMAGE_REDUCTION =0.10;

Tank::Tank	(Team::Name team, game::Squad *squad):
        Hero(Heroes::getName(Role::Type::TANK,team),
             HIT_POINTS,
             Role(Role::Type::TANK),
             squad){
};

unsigned int Tank::attack(Hero *enemy){
    unsigned int damage = roll_dice(MIN_ATTACK_DAMAGE,MAX_ATTACK_DAMAGE);
    std::cout<< get_name()<<" bonks "<< enemy->get_name()<<" for "<<damage<<" points "<<std::endl;
    enemy->take_damage(damage);
    return damage;
};

void Tank::take_damage(unsigned int amount) {
    /*// make variables in hero protected instead of private
    hit_points = (unsigned int)(hit_points- 0.9*amount);
    if (hit_points < 0){
        hit_points =0;
    }
    std::cout<< name << " has fallen!";
     */
    Hero::take_damage((unsigned int)(amount-SHIELD_DAMAGE_REDUCTION*amount));
};
