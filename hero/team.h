//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_TEAM_H
#define PROJECT_1_TEAM_H
#include "iostream"
namespace hero{
    class Team{
    public:
        //Team name enumerator
        enum Name{DRAGON, LION, SHARK};
        /*
         * Create the team.
         * @Params team	team
         */
        Team(Name team);

        /*
         * Get the name of the team.
         * @Returns name
         */
        Name get_name()const;

        /*
         *  A string conversion operator that returns the string name of the team, e.g.
         *  "DRAGON", "LION", "SHARK".
         *  @Returns string name
         */
        operator std::string() const;

    private:
        //Name of team
        Name team_;
    };
}
#endif //PROJECT_1_TEAM_H
