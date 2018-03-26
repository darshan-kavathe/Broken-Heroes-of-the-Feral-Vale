//
// Created by Darshan Kavathe on 3/1/2018.
//

#ifndef PROJECT_1_FIGHTER_H
#define PROJECT_1_FIGHTER_H

#include "hero.h"
#include "team.h"

namespace hero{

class Fighter: public Hero{
public:
    /*
     * Create the fighter.
     * Parameters
     * @params team	their team
     * @params squad	(ignored)
     */
    Fighter	(Team::Name team, game::Squad *squad);
    /*
     * When a fighter attacks their enemy, they roll the dice to get a random value between their min and max damage.
     * An attack message is displayed to standard output:
     * {name} slashes {enemy} for # points
     * Here {name} is the hero's name, {enemy} is the enemies name, and # is the amount of damage they dealt.
     * Parameters
     * @params enemy	the enemy being attacked
     * Returns
     * @returns amount of damage dealt
     * Implements hero::Hero.
     */

    virtual unsigned int attack(Hero *enemy);

    //maximum hit points
    static const unsigned int 	HIT_POINTS = 40;
    //max attack damage
    static const unsigned int 	MAX_ATTACK_DAMAGE = 20;
    //min attack damage
    static const unsigned int 	MIN_ATTACK_DAMAGE = 10;
};
}
#endif //PROJECT_1_FIGHTER_H
