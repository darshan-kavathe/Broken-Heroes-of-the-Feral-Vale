//
// Created by Darshan on 3/1/2018.
//
#include"battle.h"
//#include "../hero/hero.h"

using game::Battle;
using std::list;
using std::map;
Battle::Battle(unsigned long long 	dragon_seed,
                       unsigned long long 	lion_seed,
                       unsigned long long 	shark_seed):
        dragon_seed_(1),lion_seed_(1),shark_seed_(1){
//Initialize the battle with the seeds.
    dragon_seed_ = dragon_seed;
    lion_seed_ = lion_seed;
    shark_seed_ = shark_seed;

}

Battle::~Battle(){
//Destruction.

}

struct CustomCompare
{
    bool operator()(const hero::Hero* h1, const hero::Hero* h2)
    {
        return (h1)->get_name() < (h2)->get_name();
    }
};

void Battle::play(){
    Squad* dragon_ptr1 = new Squad(hero::Team::Name::DRAGON,dragon_seed_);
    Squad* lion_ptr1 = new Squad(hero::Team::Name::LION,lion_seed_);
    Squad* shark_ptr1 = new Squad(hero::Team::Name::SHARK,shark_seed_);


    bool game_over= false;
    std::list<hero::Hero*> dead_pool;
    std::list<game::Squad*> b_teams;
    b_teams.push_back(dragon_ptr1);
    b_teams.push_back(lion_ptr1);
    b_teams.push_back(shark_ptr1);
    std::map<hero::Hero*,unsigned int, CustomCompare> damage_scores;
    list<game::Squad*>::iterator bteam_itr = b_teams.begin();
    for (bteam_itr = b_teams.begin();bteam_itr!= b_teams.end(); bteam_itr++){
        std::deque<hero::Hero*> deq = (*bteam_itr)->get_heroes();
        for (deque<hero::Hero*>::iterator hero_iter = deq.begin();
             hero_iter!= deq.end();hero_iter++) {
            //std::cout << **hero_iter << std::endl;
            damage_scores[*hero_iter]= 0;
        }
    }
    int battle_num =1;
    while (!game_over){
        //list<game::Squad*>::iterator bteam_itr = b_teams.begin();
        std::cout<<"Battle #"<< battle_num<<std::endl;
        std::cout<<"========="<< std::endl;
        battle_num ++;

        bteam_itr = b_teams.begin();
        hero::Hero* hero_1 = (*bteam_itr)->get_next_hero();
        bteam_itr++;
        hero::Hero* hero_2 = (*bteam_itr)->get_next_hero();
        bteam_itr++;
        hero::Hero* hero_3 = (*bteam_itr)->get_next_hero();
        damage_scores[hero_2] += (hero_1->attack(hero_2));
        damage_scores[hero_3] += (hero_2->attack(hero_3));
        damage_scores[hero_1] += (hero_3->attack(hero_1));

        (*bteam_itr)->add_hero(hero_3);
        bteam_itr --;
        (*bteam_itr)->add_hero(hero_2);
        bteam_itr --;
        (*bteam_itr)->add_hero(hero_1);

        break;
    }
    std::map<hero::Hero*,unsigned int>::iterator score_itr = damage_scores.begin();
    for(score_itr=damage_scores.begin(); score_itr!=damage_scores.end(); score_itr++ ){
        std::cout << (score_itr->first)->get_name() <<": "<<(score_itr->second)<< std::endl;
    }

}
