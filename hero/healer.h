//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_HEALER_H
#define PROJECT_1_HEALER_H

#include "../game/squad.h"
#include "hero.h"
#include "team.h"

namespace hero{
    class Healer: public Hero{
    public:
        /*
         * Create the healer
         * @param team their team
         * @param squad their squad
         */
        Healer(	Team::Name team, game::Squad *squad);

        /*
         * When a healer attacks, they roll the dice to determine the amount of healing to be done to all allies.
         * First, the healer heals themselves, then each non-fallen hero in the queue (in order).
         * Afterwards, they roll the dice again to determine how much damage they will deal to their enemy.
         * Their attack message is:(name} smites {enemy} for # points
         * Here {name} is the hero's name, {enemy} is the enemies name, and # is the amount of damage they dealt.
         *
         *@params enemy
         * @returns amount of damage dealt
         * Implements hero::Hero.
         */
        virtual unsigned int attack (Hero *enemy);

        //maximum hitpoints
        static const unsigned int HIT_POINTS = 30;
        //minimum attack damage
        static const unsigned int MAX_ATTACK_DAMAGE = 10;
        //maximum amount to heal
        static const unsigned int MAX_HEAL_AMOUNT = 5;
        //maximum attack damage
        static const unsigned int MIN_ATTACK_DAMAGE = 5;
        //minimum amount to heal
        static const unsigned int MIN_HEAL_AMOUNT = 1;
    };
}
#endif //PROJECT_1_HEALER_H
