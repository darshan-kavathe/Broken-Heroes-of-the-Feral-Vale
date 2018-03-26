//
// Created by Darshan Kavathe on 3/1/2018.
//

#include "role.h"
using hero::Role;
using std::string;
Role::Role (Type type):type_(type){
}

enum Role::Type Role::get_type() const{
    return type_ ;
}
Role::operator std::string() const{
    switch(type_){
        case Type::FIGHTER:
            return "FIGHTER";
        case Type::HEALER:
            return "HEALER";
        case Type::TANK:
            return "TANK";
        default:
            return "INVALID";
    }
}