//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_TANK_H
#define PROJECT_1_TANK_H

#include "../game/squad.h"
#include "hero.h"
#include "team.h"

namespace hero{
    class Tank: public Hero{
    public:
        /*
         * Create the tank.
         * @params
         * team	the team
         * squad the squad
         */
        Tank (hero::Team::Name team, game::Squad *squad);
        /*
         * A hero attacks an enemy hero.
         * How this happens depends on the type of hero and their attacking characteristics.
         * @params enemy who this hero is attacking
         * @return amount of damage dealt
         */
        unsigned int attack (Hero *enemy);
        /*
         *The tank overrides Hero::take_damage, but still calls it after determining the adjusted
         * amount of damage to take.
         * @param amount
         */
        void take_damage (unsigned int amount);

        //maximum hit points
        static const unsigned int HIT_POINTS = 50;
        //maximum attack damage
        static const unsigned int MAX_ATTACK_DAMAGE = 10;
        //minimum attack damage
        static const unsigned int MIN_ATTACK_DAMAGE = 5;
        //amount damage taken is reduced by
        static const double SHIELD_DAMAGE_REDUCTION;
    };
}

#endif //PROJECT_1_TANK_H
