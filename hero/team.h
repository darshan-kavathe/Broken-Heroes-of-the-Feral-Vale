//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_TEAM_H
#define PROJECT_1_TEAM_H
#include "iostream"
namespace hero{
    class Team{
    public:
        /*
         * Create the team.
         * @Params team	team
         */
        enum Name{DRAGON, LION, SHARK};
        explicit Team(Name team);
        Name get_name()const;
        explicit operator std::string() const;

    private:
        Name team_;
    };
}
#endif //PROJECT_1_TEAM_H
