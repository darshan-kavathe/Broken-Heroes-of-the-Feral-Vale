//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_FIGHTER_H
#define PROJECT_1_FIGHTER_H

#include "hero.h"
#include "team.h"

namespace hero{

class Fighter: public Hero{
public:
    Fighter	(Team::Name team, game::Squad *squad);
    unsigned int attack(Hero *enemy);

    static const unsigned int 	HIT_POINTS = 40;
    static const unsigned int 	MAX_ATTACK_DAMAGE = 20;
    static const unsigned int 	MIN_ATTACK_DAMAGE = 10;
};
}
#endif //PROJECT_1_FIGHTER_H
