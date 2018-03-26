//
// Created by Darshan Kavathe on 3/1/2018.
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
         * @params name	name
         * @params hit_points	current and maximum hit points (initially)
         * @params role	role
         * @params squad	squad
         */
         Hero(const std::string& name, unsigned int hit_points, const Role& role, game::Squad *squad);
        /*
         * Used to simulate dice rolling when attacking or healing.
         * This routine uses the random number generator of the squad and guarantees a number between min and max, inclusively.
         * Parameters
         * @params min	minimum value
         * @params max	maximum value
         * Returns
         * @returns the random value
         */
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
        /*
         * A hero attacks an enemy hero.
         * How this happens depends on the type of hero and their attacking characteristics.
         * Parameter
         * @params enemy	who this hero is attacking
         * @Returns amount of damage dealt
         */
        virtual unsigned int attack	(Hero* enemy);

        /*
         * Dynamically create and return a new Hero of the desired kind.
         * The caller of this routine is responsible for managing the hero's memory.
         * Parameter
         * @params type	the role
         * @params team	associated team
         * @params squad	allies
         * Returns Hero
         */
        static Hero * create_hero(Role::Type type, Team::Name team, game::Squad* squad);

        /*
         * Get the name of the hero.
         * @returns name
         */
        const std::string& get_name()const;

        /*
         * Get the squad of allies for this hero.
         * @Returns the squad
         */
        game::Squad* get_squad();

        /*
         * Get the name of the team this hero is associated with.
         * Returns  team name
         */
        Team::Name get_team_name()const;

        /*
         * Healing increases the hero's hit points, but cannot exceed the maximum.
         * When a hero is healed, this method prints to standard output:
         * {name} heals for # points
         * Here, {name} refers to the hero's name, and # refers to the total amount that was attempted to heal.
         * Parameters
         * @params amount	amount to heal
         */
        void heal	(unsigned int amount);

        /*
         * Is the hero still in the game? When their hit points reach zero they have fallen in battle.
         * @Returns whether the hero is still alive or not
         */
        bool is_alive()const;
        /*
         * Assignment is forbidden.
         * @params other	other
         */
        Hero& operator=	(const Hero& other) = delete;
        /*
         * When a hero takes damage they lose hit points.
         * If their hit points falls to or below 0, they have fallen and their hit points should remain at 0. If they fall, this method prints to standard output:
         * {name} has fallen!
         * Here, {name} refers to the hero's name.
         * Parameters
         * @params amount
         * Reimplemented in hero::Tank.
         */
        virtual void take_damage(unsigned int amount);
        /*
         * Displays the hero to standard output in the form:
         * {name}, ROLE, #/#
         * Here, {name} is the hero's name, ROLE is their role, either FIGHTER, HEALER or TANK.
         * Parameter
         * @params os	output stream
         * @params hero	the hero
         * Returns
         * @return output stream
         */
        friend std::ostream& operator<<	(std::ostream& os, const Hero& other);

    private:
        //hero name
        const std::string name;
        //current hit_points
        unsigned int hit_points;
        //Role of hero
        Role role;
        //Squad of hero
        game::Squad *squad;
    };
    std::ostream& operator<<(std::ostream& os, const hero::Hero& other);
}
#endif //PROJECT_1_HERO_H
