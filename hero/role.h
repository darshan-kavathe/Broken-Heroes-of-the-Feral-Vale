//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_ROLE_H
#define PROJECT_1_ROLE_H

#include "iostream"
//using std::string
namespace hero{
    class Role{
    public:
        enum Type { FIGHTER, HEALER, TANK };
        Role (Type type);
        Role::Type get_type () const;
        operator std::string () const;

    private:
        Role::Type type_;
    };
}

#endif //PROJECT_1_ROLE_H
