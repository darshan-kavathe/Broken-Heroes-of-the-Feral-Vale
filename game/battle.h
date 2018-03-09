//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_BATTLE_H
#define PROJECT_1_BATTLE_H
namespace game{
class Battle{
public:
    //Initialize the battle with the seeds.
    Battle(unsigned long long 	dragon_seed,
           unsigned long long 	lion_seed,
           unsigned long long 	shark_seed);
    //Copy construction is forbidden
    Battle(const game::Battle & other) = delete;
    //Destruction.
    ~Battle();
    //Assignment is forbidden
    Battle& operator =(const Battle & other)= delete;
    //Play the game
    void play();

private:
    unsigned long long 	dragon_seed;
    unsigned long long 	lion_seed;
    unsigned long long 	shark_seed;
};}
#endif //PROJECT_1_BATTLE_H
