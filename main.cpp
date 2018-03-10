//
// Created by darsh on 3/9/2018.
//

#include "game/battle.h"

int main(){
    game::Battle* b1 = new game::Battle(5,5,5);
    b1->play();
    return 0;
}