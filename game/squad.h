//
// Created by Darshan Kavathe on 3/1/2018.
//

#ifndef PROJECT_1_SQUAD_H
#define PROJECT_1_SQUAD_H

#include <ostream>
#include "../hero/team.h"
#include "../hero/hero.h"
#include "../util/queue.h"
#include "../util/random.h"

namespace game {
    class Squad {
    public:
        /*
         *Create a default squad (used for testing only).
         *The squad should be associated with Team Dragon, but should not preset any members.
         */
        Squad();

        /*
         * Heroes are added to the collection in order by a random dice roll between 0 and 5 inclusive:

            0: Fighter, Healer, Tank
            1: Healer, Tank, Fighter
            2: Tank, Fighter, Healer
            3: Fighter, Tank, Healer
            4: Healer, Fighter, Tank
            5: Tank, Healer, Fighter

            Parameters: name, seed
         */
        Squad(hero::Team::Name name, unsigned long long seed);

        /*
         * Add a hero to the back.
         * Parameters: hero	the hero
         */
        void add_hero(hero::Hero *hero);

        /*
        * Get all the heroes.
        * Returns the heroes
        */
        deque<hero::Hero *> get_heroes();

        /*
         * Removes and returns the front hero.
         * Returns the hero
         */
        hero::Hero *get_next_hero();

        /*
         * Get the team.
         * Returns the team
         */
        hero::Team get_team() const;

        /*
         *Roll the dice to generate a number between min and max, inclusive.
         * Parameters
         * @params min	the minimum value
         * @params max	the maximum value
         * Returns
         * the value
         */
        unsigned int roll_dice(unsigned int min, unsigned int max);

        /*
         * How many heroes are in the squad?
         * Returns size
         */
        unsigned long size() const;

        /*
         * Prints a message in the form:
         * TEAM:{name}, ROLE, #/#
         *...
         * Here, TEAM is the team name, e.g."DRAGON", "LION" or SHARK. And the remaining lines are the string conversions of each non-fallen hero.
         * Parameters
         * os	output stream
         * squad	the squad
         * Returns output stream
         *
         * */
        friend std::ostream& operator<<(std::ostream& os, const Squad& squad);

    private:
        util::Random random_gen;
        hero::Team team_;
        //unsigned long long seed_;
        util::Queue<hero::Hero*> hero_q;
    };
    std::ostream& operator<<(std::ostream& os, const game::Squad& squad);
}
#endif //PROJECT_1_SQUAD_H
