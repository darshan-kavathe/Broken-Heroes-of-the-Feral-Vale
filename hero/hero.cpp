//
// Created by Darshan on 3/1/2018.
//
#include <iostream>
#include "hero.h"
#include "role.h"
#include "../game/squad.h"
#include "fighter.h"
#include "healer.h"
#include "tank.h"

using hero::Hero;
using hero::Team;
using std::string;

Hero::Hero(	const std::string& name, unsigned int hit_points, const Role& role, game::Squad *squad):
        name(name),hit_points (hit_points), role(role),squad (squad)
{
}

Hero::~Hero(){
}

unsigned int hero::Hero::attack	(Hero*){
}

Hero* Hero::create_hero(Role::Type type, Team::Name team, game::Squad* squad){
    switch (type) {
        // check type//
        case Role::Type::FIGHTER:
            return new Fighter(team,squad);
        case Role::Type::HEALER:
            return new Healer(team,squad);
        case Role::Type::TANK:
             return new Tank(team,squad);
        default:
            return new Fighter(team,squad);
    }
}

const string & Hero::get_name()const{
    return name;
}

game::Squad * Hero::get_squad(){
    return squad;
}

Team::Name Hero::get_team_name()const{
    return squad->get_team().get_name();
}

void Hero::heal	(unsigned int amount){
    unsigned int max_allowed = 0;
    switch (role.get_type()) {
        case Role::Type::FIGHTER:
            max_allowed = hero::Fighter::HIT_POINTS;
            break;
        case Role::Type::HEALER:
            max_allowed = hero::Healer::HIT_POINTS;
            break;
        case Role::Type::TANK:
            max_allowed = hero::Tank::HIT_POINTS;
            break;
    }
    hit_points= hit_points+ amount;
    if (hit_points > max_allowed){
        hit_points = max_allowed;
    };
    std::cout<< name << " heals for "<<amount << " points" <<std::endl;
}

bool Hero::is_alive	(	)	const{
    return (bool)hit_points;
}


unsigned int Hero::roll_dice(unsigned int min, unsigned int max){
    //number between min and max, inclusively.
    return squad->roll_dice(min,max);
}

void Hero::take_damage(	unsigned int amount){
    if (hit_points <= amount){
        hit_points =0;
        std::cout<< name << " has fallen!"<<std::endl;
    }
    else {
        hit_points = hit_points - amount;
    }
}

std::ostream& hero::operator<<(std::ostream& os, const hero::Hero& other){

    unsigned int max_allowed = 0;
    switch (other.role.get_type()) {
        case Role::Type::FIGHTER:
            max_allowed = hero::Fighter::HIT_POINTS;
            break;
        case Role::Type::HEALER:
            max_allowed = hero::Healer::HIT_POINTS;
            break;
        case Role::Type::TANK:
            max_allowed = hero::Tank::HIT_POINTS;
            break;
    }
    std::string s1 = other.role ;
    os<<other.name<<", "<< s1 <<", "<< other.hit_points<<"/"<< max_allowed;
    return os;
}






