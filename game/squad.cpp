//
// Created by DArshan Kavathe on 3/1/2018.
//
#include "squad.h"
#include "../hero/team.h"
#include "../hero/hero.h"

using game::Squad;
using hero::Team;
using hero::Hero;


Squad::Squad():random_gen(1),team_(Team::Name::DRAGON){
}

Squad::Squad(hero::Team::Name name, unsigned long long seed):random_gen(seed),team_(name){
    switch(roll_dice(0,5)){
        case 0:
            add_hero(hero::Hero::create_hero(hero::Role::FIGHTER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::HEALER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::TANK, team_.get_name(),this));
            break;
        case 1:
            add_hero(hero::Hero::create_hero(hero::Role::HEALER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::TANK, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::FIGHTER, team_.get_name(),this));
            break;
        case 2:
            add_hero(hero::Hero::create_hero(hero::Role::TANK, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::FIGHTER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::HEALER, team_.get_name(),this));
            break;
        case 3:
            add_hero(hero::Hero::create_hero(hero::Role::FIGHTER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::TANK, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::HEALER, team_.get_name(),this));
            break;
        case 4:
            add_hero(hero::Hero::create_hero(hero::Role::HEALER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::FIGHTER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::TANK, team_.get_name(),this));
            break;
        case 5:
            add_hero(hero::Hero::create_hero(hero::Role::TANK, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::HEALER, team_.get_name(),this));
            add_hero(hero::Hero::create_hero(hero::Role::FIGHTER, team_.get_name(),this));
            break;
        default:
            break;
    }
}

void Squad::add_hero(hero::Hero* hero_ptr){
    hero_q.add(hero_ptr);
}
deque<hero::Hero*> Squad::get_heroes(){
    return hero_q.get_elements();
}
Hero* Squad::get_next_hero	(){
    return hero_q.remove();
}
Team Squad::get_team()const{
    return team_;
}
unsigned int Squad::roll_dice(unsigned int 	min, unsigned int 	max){
    return random_gen.roll_dice(min,max);
}
unsigned long Squad::size()	const{
    return hero_q.size();
}
std::ostream& game::operator<<(std::ostream& os, const Squad& squad){
    std::string a1 = squad.get_team();
    os<< a1 <<":\n";
    deque<hero::Hero*> dq = squad.hero_q.get_elements();
    for (deque<hero::Hero*>::iterator iter = dq.begin();
    iter!= dq.end();iter++){
        if ((*iter)->is_alive()){
            os<<*(*iter)<<std::endl;
        }
    }
    return os;
}



