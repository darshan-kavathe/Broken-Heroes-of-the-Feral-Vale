//
// Created by Darshan on 3/1/2018.
//
#include"battle.h"
//#include "../hero/hero.h"

using game::Battle;
using std::list;
using std::map;
Battle::Battle(unsigned long long 	dragon_seed,
                       unsigned long long 	lion_seed,
                       unsigned long long 	shark_seed):
        dragon_seed_(1),lion_seed_(1),shark_seed_(1){
//Initialize the battle with the seeds.
    dragon_seed_ = dragon_seed;
    lion_seed_ = lion_seed;
    shark_seed_ = shark_seed;

}

Battle::~Battle(){
//Destruction.

}

struct CustomCompare
{
    bool operator()(const hero::Hero* h1, const hero::Hero* h2)
    {
        return (h1)->get_name() < (h2)->get_name();
    }
};

void Battle::play(){
    Squad* dragon_ptr1 = new Squad(hero::Team::Name::DRAGON,dragon_seed_);
    Squad* lion_ptr1 = new Squad(hero::Team::Name::LION,lion_seed_);
    Squad* shark_ptr1 = new Squad(hero::Team::Name::SHARK,shark_seed_);


    bool game_over= false;
    std::list<hero::Hero*> dead_pool;
    std::list<game::Squad*> b_teams;
    b_teams.push_back(dragon_ptr1);
    b_teams.push_back(lion_ptr1);
    b_teams.push_back(shark_ptr1);
    std::map<hero::Hero*,unsigned int, CustomCompare> damage_scores;
    list <hero::Hero*> curr_players;
    list <hero::Hero*>::iterator curr_pitr = curr_players.begin();
    list<game::Squad*>::iterator bteam_itr = b_teams.begin();
    for (bteam_itr = b_teams.begin();bteam_itr!= b_teams.end(); bteam_itr++){
        std::deque<hero::Hero*> deq = (*bteam_itr)->get_heroes();
        for (deque<hero::Hero*>::iterator hero_iter = deq.begin();
             hero_iter!= deq.end();hero_iter++) {
            //std::cout << **hero_iter << std::endl;
            damage_scores[*hero_iter]= 0;
        }
    }
    int battle_num =1;
    hero::Hero* attacker;
    hero::Hero* victim;
    Squad* victor = b_teams.front();
    while (!game_over) {
        //list<game::Squad*>::iterator bteam_itr = b_teams.begin();
        std::cout << "Battle #" << battle_num << std::endl;
        std::cout << "=========" << std::endl;
        battle_num++;

        //bool curr_battle_over = false;

        for (bteam_itr = b_teams.begin(); bteam_itr != b_teams.end(); bteam_itr++) {
            std::cout << **bteam_itr << std::endl;
            hero::Hero* hero_a = (*bteam_itr)->get_next_hero();
            curr_players.push_back(hero_a);
        }

        for (curr_pitr = curr_players.begin();curr_pitr != curr_players.end();curr_pitr++) {
            attacker = *curr_pitr;
            if (*(curr_pitr) == curr_players.back()){
                victim = curr_players.front();
            }
            else{
                curr_pitr++;
                victim = *curr_pitr;
                curr_pitr--;
            }
            if (attacker->is_alive()) {
                damage_scores[victim] += attacker->attack(victim);
            }
        }

        // find dead
        curr_pitr = curr_players.begin();
        for (bteam_itr = b_teams.begin(); bteam_itr != b_teams.end(); bteam_itr++){
            if ((*curr_pitr)->is_alive()) {
                (*bteam_itr)->add_hero(*curr_pitr);
            }
            else{
                dead_pool.push_back(*curr_pitr);
            }
            curr_pitr++;
            deque<hero::Hero*> h1 = (*bteam_itr)->get_heroes();
            if (h1.size()==0){
                std::string s4 = (*bteam_itr)->get_team();
                std:: cout<<"Team "<<s4<<" is defeated!"<<std::endl;
                b_teams.erase(bteam_itr);
            }   
        }

        if (b_teams.size()==1){
            victor = b_teams.front();
            game_over = true;
        }
        std::cout<<std::endl;
        if (battle_num>10) {
            break;
        }
    }

    std::cout<<"STATISTICS"<<std::endl;
    std::cout<<"=========="<< std::endl;
    std::string v = victor->get_team();
    std::cout<<"Victor:"<< v <<std::endl;
    std::cout<<"=========="<< std::endl;
    std::cout<<"Battles:"<< (battle_num-1) <<std::endl;
    std::cout<<"Fallen:" <<std::endl;
    std::cout<<"=========="<< std::endl;
    for (curr_pitr = dead_pool.begin();curr_pitr != dead_pool.end();curr_pitr++){
        std::cout<< **curr_pitr;
    }
    std::cout<<"Damage:" <<std::endl;
    std::cout<<"=========="<< std::endl;
    std::map<hero::Hero*,unsigned int>::iterator score_itr = damage_scores.begin();
    for(score_itr=damage_scores.begin(); score_itr!=damage_scores.end(); score_itr++ ){
        std::cout << (score_itr->first)->get_name() <<": "<<(score_itr->second)<< std::endl;
    }

}
