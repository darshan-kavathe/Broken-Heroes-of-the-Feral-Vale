//
// Created by darsh on 3/1/2018.
//
#include "hero.h"
#include "role.h"
#include "../game/squad.h"

using hero::Hero;
using hero::Team;

hero::Hero::Hero(const Hero& other){

}
virtual hero::Hero::~Hero(	){

}
Hero::Hero(	const std::string& name, unsigned int hit_points, const Role& role, game::Squad *squad){

}
virtual unsigned int hero::Hero::attack	(	Hero * 	enemy	){

}

hero::Hero::Hero * Hero::create_hero	(	Role::Type 	type,
                                 Team::Name 	team,
                                 game::Squad * 	squad
){

}


const string & Hero::get_name(	)	const{

}

game::Squad * Hero::get_squad(){

}

Team::Name Hero::get_team_name	()	const{

}

void Hero::heal	(unsigned int 	amount	){

}

bool Hero::is_alive	(	)	const{

}

Hero& hero::Hero::operator=	(	const Hero & 	other	){

}


unsigned int Hero::roll_dice(unsigned int 	min, unsigned int 	max){

}


void Hero::take_damage	(	unsigned int 	amount	){

}

std::ostream& operator<<	(	std::ostream & 	os,
                                 const Hero & 	hero
){

}






