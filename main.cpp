//
// Created by darsh on 3/9/2018.
//

#include "game/battle.h"

int main(int argc, char*argv[]){
    game::Battle *b1;
    if(argc < 5) {
        b1 = new game::Battle(0, 0, 0);
    }
    else{
        int a1 = atoi(argv[1]);
        int a2 = atoi(argv[3]);
        int a3 = atoi(argv[5]);
        b1 = new game::Battle(a1, a2, a3);
    }

    b1->play();

    return 0;
}