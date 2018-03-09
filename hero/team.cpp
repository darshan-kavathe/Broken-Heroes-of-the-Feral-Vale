//
// Created by darsh on 3/1/2018.
//

#include "team.h"
#include "string"
using hero::Team;
using std::string;
Team::Team(Team::Name team):team_(team) {

};

Team::Name Team::get_name()const{
    return team_;
};

Team::operator std::string() const{
    return "implement string method in team.cpp";
};

