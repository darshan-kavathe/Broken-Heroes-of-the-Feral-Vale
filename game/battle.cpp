//
// Created by Darshan on 3/1/2018.
//
#include"battle.h"
using game::Battle;

game::Battle::Battle(unsigned long long 	dragon_seed,
                       unsigned long long 	lion_seed,
                       unsigned long long 	shark_seed){
//Initialize the battle with the seeds.
}
game::Battle::Battle(const game::Battle & other){
//Copy construction is forbidden
}
game::Battle::~Battle(){
//Destruction.
}

game::Battle& game::Battle::operator=(const game::Battle & other){
//Assignment is forbidden
}

void game::Battle::play(){
//Play the game!
}
