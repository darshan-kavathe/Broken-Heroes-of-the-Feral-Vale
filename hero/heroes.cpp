#include "heroes.h"

using std::string;
using hero::Heroes;
using hero::Role;
using hero::Team;

const string Heroes::DRAGON_FIGHTER = "Trogdor";
const string Heroes::LION_FIGHTER = "Simba";
const string Heroes::SHARK_FIGHTER = "Jaws";

const string Heroes::DRAGON_HEALER = "Spyro";
const string Heroes::LION_HEALER = "Elsa";
const string Heroes::SHARK_HEALER = "Jabberjaw";

const string Heroes::DRAGON_TANK = "Smaug";
const string Heroes::LION_TANK = "Aslan";
const string Heroes::SHARK_TANK = "Don Lino";

const string Heroes::UNDEFINED = "";

const std::string& Heroes::getName(Role::Type type, Team::Name team) {
    switch (team) {
        case Team::Name::DRAGON:
            switch (type) {
                case Role::Type::FIGHTER:
                    return DRAGON_FIGHTER;
                case hero::Role::Type::HEALER:
                    return DRAGON_HEALER;
                case hero::Role::Type::TANK:
                    return DRAGON_TANK;
            }
            break;
        case Team::Name::LION:
            switch (type) {
                case hero::Role::Type::FIGHTER:
                    return LION_FIGHTER;
                case hero::Role::Type::HEALER:
                    return LION_HEALER;
                case hero::Role::Type::TANK:
                    return LION_TANK;
            }
        case Team::Name::SHARK:
            switch (type) {
                case hero::Role::Type::FIGHTER:
                    return SHARK_FIGHTER;
                case hero::Role::Type::HEALER:
                    return SHARK_HEALER;
                case hero::Role::Type::TANK:
                    return SHARK_TANK;
            };
    }

    return UNDEFINED;  // unreachable
}
