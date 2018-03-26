//
// Created by Darshan Kavathe on 3/9/2018.
//

#include "game/battle.h"
#include <sstream>

int main(int argc, char*argv[]){
    game::Battle *game_inst;
    // check number of arguments
    if (argc<3){
        std::cout<<"Usage: main dragon_seed_# lion_seed_# shark_seed_#"<<std::endl;
    }
    else {
        //Parse input to unsigned long long
        unsigned long long a1 = atoll(argv[1]);
        unsigned long long a2 = atoll(argv[2]);
        unsigned long long a3 = atoll(argv[3]);
        // start game instance
        game_inst = new game::Battle(a1, a2, a3);
        game_inst->play();
    }
    delete game_inst;
    return 0;
}