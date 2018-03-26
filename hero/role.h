//
// Created by Darshan Kavathe on 3/1/2018.
//

#ifndef PROJECT_1_ROLE_H
#define PROJECT_1_ROLE_H

#include "iostream"
//using std::string
namespace hero{
    class Role{
    public:
        //Their type.
        enum Type { FIGHTER, HEALER, TANK };
        //Create the role.
        //@param Type type
        Role (Type type);
        //Get their type.
        //Returns type
        Role::Type get_type () const;
        /*
         * A string conversion operator that returns the string name of the role, e.g.
         * "FIGHTER", "HEALER", "TANK".
         * @returns string name
         */
        operator std::string () const;

    private:
        //Their type.
        Role::Type type_;
    };
}

#endif //PROJECT_1_ROLE_H
