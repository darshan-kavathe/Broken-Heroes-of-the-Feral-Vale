//
// Created by Darshan on 3/1/2018.
//
#include"battle.h"
#include "../hero/hero.h"

using game::Battle;
using std::list;

Battle::Battle(unsigned long long 	dragon_seed,
                       unsigned long long 	lion_seed,
                       unsigned long long 	shark_seed):
        dragon_seed(dragon_seed),lion_seed(lion_seed),shark_seed(shark_seed){
//Initialize the battle with the seeds.
}

Battle::~Battle(){
//Destruction.
}

void Battle::play(){
    //squad()
    list<hero::Hero*> dead_pool;
    
}
