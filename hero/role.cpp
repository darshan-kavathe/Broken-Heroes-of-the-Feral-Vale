//
// Created by darsh on 3/1/2018.
//

#include "role.h"
using hero::Role;
using std::string;
Role::Role (Type type):type_(type){
};

enum Role::Type Role::get_type() const{
    return type_ ;
};
Role::operator std::string() const{
    return "write string method in role.cpp";
};