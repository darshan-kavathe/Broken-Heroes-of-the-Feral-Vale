//
// Created by Darshan on 3/1/2018.
//
#include"battle.h"
using game::Battle;

Battle::Battle(unsigned long long 	dragon_seed,
                       unsigned long long 	lion_seed,
                       unsigned long long 	shark_seed){
//Initialize the battle with the seeds.
}
Battle::Battle(const Battle & other){
//Copy construction is forbidden
}
Battle::~Battle(){
//Destruction.
}
Battle& Battle::operator=(const Battle & other){
//Assignment is forbidden
}

void Battle::play(){
//Play the game!
}
