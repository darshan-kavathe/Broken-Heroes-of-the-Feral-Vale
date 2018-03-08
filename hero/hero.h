//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_HERO_H
#define PROJECT_1_HERO_H

#include <ostream>
#include "role.h"

namespace game{
    class Squad;
}

namespace hero{
    class Hero{
    public:
        Hero(const Hero& other);
        virtual ~Hero(	);
        Hero(	const std::string& name, unsigned int hit_points, const Role& role, game::Squad *squad);
        virtual unsigned int attack	(	Hero * 	enemy	);

        Hero * Hero::create_hero(Role::Type type, Team::Name team, game::Squad* squad);
        const string& get_name(	)	const;
        game::Squad* get_squad();
        Team::Name get_team_name()	const;
        void heal	(unsigned int 	amount	);
        bool is_alive()	const;
        Hero& operator=	(const Hero& other);

        unsigned int roll_dice(unsigned int 	min, unsigned int 	max);
        void take_damage	(	unsigned int 	amount	);
        friend std::ostream& operator<<	(std::ostream& os, const Hero& hero);
    };
}
#endif //PROJECT_1_HERO_H
