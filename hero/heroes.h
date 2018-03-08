#ifndef HERO_HEROES_H
#define HERO_HEROES_H

#include "role.h"
#include "team.h"
#include "fighter.h"

#include <string>

namespace hero {

    /**
     * These are the hero names that are used when constructing the hero's.
     *
     * @author Sean Strout
     */
    struct Heroes {
        /** "Trogdor" */
        const static std::string DRAGON_FIGHTER;
        /** "Simba" */
        const static std::string LION_FIGHTER;
        /** "Jaws" */
        const static std::string SHARK_FIGHTER;
        /** "Spyro" */
        const static std::string DRAGON_HEALER;
        /** "Elsa" */
        const static std::string LION_HEALER;
        /** "Jabberjaw */
        const static std::string SHARK_HEALER;
        /** "Smaug" */
        const static std::string DRAGON_TANK;
        /** "Aslan" */
        const static std::string LION_TANK;
        /** "Don Lino" */
        const static std::string SHARK_TANK;
        /** an empty string used in getName to satisfy warning about unreachable code */
        const static std::string UNDEFINED;

        /**
         * Get the name of the hero.
         *
         * @param type their role
         * @param team their team
         * @return their name
         */
        static const std::string &getName(hero::Role::Type type, hero::Team::Name team);
    }; // Heroes

} // hero

#endif // HERO_HEROES_H
