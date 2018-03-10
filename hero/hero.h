//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_HERO_H
#define PROJECT_1_HERO_H

#include <ostream>
#include "role.h"
#include "team.h"

namespace game{
    class Squad;
}

namespace hero{
    class Hero{
    protected:
        /*
         * Create the hero.
         * Parameters
         * name	name
         * hit_points	current and maximum hit points (initially)
         * role	role
         * squad	squad
         */
         Hero(const std::string& name, unsigned int hit_points, const Role& role, game::Squad *squad);

        unsigned int roll_dice(unsigned int min, unsigned int max);

    public:
        /*
         * Copy construction is forbidden.
         */
        Hero(const Hero& other) = delete;

        /*
         * Hero destructor is default/empty.
         */
        virtual ~Hero();

        virtual unsigned int attack	(Hero* enemy);

        static Hero * create_hero(Role::Type type, Team::Name team, game::Squad* squad);

        const std::string& get_name()const;

        game::Squad* get_squad();
        Team::Name get_team_name()const;
        void heal	(unsigned int amount);
        bool is_alive()const;
        Hero& operator=	(const Hero& other) = delete;

        virtual void take_damage(unsigned int amount);
        friend std::ostream& operator<<	(std::ostream& os, const Hero& other);

    private:
        const std::string name;
        unsigned int hit_points;
        Role role;
        game::Squad *squad;
    };
    std::ostream& operator<<(std::ostream& os, const hero::Hero& other);
}
#endif //PROJECT_1_HERO_H
