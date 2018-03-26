//
// Created by Darshan Kavathe on 3/1/2018.
//
#include"battle.h"

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
//Destructor
}

/**
 * Custom comparator for heros
 * comares name of team lexicographically
 */
struct CustomCompare
{
    bool operator()(const hero::Hero* h1, const hero::Hero* h2)
    {
        return (h1)->get_name() < (h2)->get_name();
    }
};

void Battle::play() {
    // create Squads
    Squad *dragon_ptr1 = new Squad(hero::Team::Name::DRAGON, dragon_seed_);
    Squad *lion_ptr1 = new Squad(hero::Team::Name::LION, lion_seed_);
    Squad *shark_ptr1 = new Squad(hero::Team::Name::SHARK, shark_seed_);
    // print order
    std::vector<game::Squad *> print_order;
    print_order.push_back(dragon_ptr1);
    print_order.push_back(lion_ptr1);
    print_order.push_back(shark_ptr1);
    // add squads to battle order
    std::vector<game::Squad *> battle_order;
    // battle order
    battle_order.push_back(dragon_ptr1);
    battle_order.push_back(lion_ptr1);
    battle_order.push_back(shark_ptr1);

    // Declare log vectors
    std::vector<hero::Hero *> curr_players;

    // Vector to keep track of dead
    std::vector<hero::Hero *> dead_pool;

    // Declare iterators
    std::vector<game::Squad *>::iterator bteam_itr;
    std::vector<hero::Hero *>::iterator hero_itr;
    // Declare map to keep damage stats, Key:Hero_object Value:Damage score
    std::map<hero::Hero *, unsigned int, CustomCompare> damage_scores;

    // Initialize damage_score map to 0, add all keys
    for (bteam_itr = battle_order.begin(); bteam_itr != battle_order.end(); bteam_itr++) {
        std::deque<hero::Hero *> deq = (*bteam_itr)->get_heroes();
        for (deque<hero::Hero *>::iterator hero_iter = deq.begin();
             hero_iter != deq.end(); hero_iter++) {
            damage_scores[*hero_iter] = 0;
        }
    }

    //game variables
    bool game_over = false;
    int battle_num = 1;
    int battle_player;
    Squad* victor = battle_order.front();

    // Battle loop
    while (!game_over) {
        std::cout << "Battle #" << battle_num << std::endl;
        std::cout << "=========" << std::endl;
        // print health state before battle
        for (bteam_itr = print_order.begin(); bteam_itr != print_order.end(); bteam_itr++) {
            std::cout << (*(*bteam_itr)) << std::endl;
        }
        // get living front heros of each squad
        curr_players.clear();
        for (bteam_itr = battle_order.begin(); bteam_itr != battle_order.end(); bteam_itr++) {
            if ((*bteam_itr!=NULL) and ((*bteam_itr)->size()) != 0) {
                curr_players.push_back(((*bteam_itr)->get_next_hero()));
            } else {
                curr_players.push_back(NULL);
            }
        }
        // battle begins
        for (int i =0; i<3;i++) {
            int attacker = i;
            int defender = (i+1)%3;
            //Check if both alive
            if (curr_players[attacker] != NULL && curr_players[defender] != NULL && curr_players[attacker]->is_alive() &&
                curr_players[defender]->is_alive()) {
                //attack!
                damage_scores[curr_players[attacker]]+=curr_players[attacker]->attack(curr_players[defender]);
                //Add dead to dead_pool
                if (!(curr_players[defender]->is_alive())) {
                    dead_pool.push_back(curr_players[defender]);
                    curr_players[defender] = NULL;
                }
            }
        }

        bteam_itr = battle_order.begin();
        //add living heros back to squad queue
        for (hero_itr = curr_players.begin(); hero_itr != curr_players.end(); hero_itr++) {
            if ((*hero_itr) != NULL) {
                if ((*hero_itr)->is_alive()) {
                    (*bteam_itr)->add_hero(*hero_itr);
                }
            }
            bteam_itr++;
        }
        //count number of alive squads at end of battle
        battle_player = 0;
        for (bteam_itr = battle_order.begin(); bteam_itr != battle_order.end(); bteam_itr++) {
            if ((*bteam_itr!=NULL)) {
                if(((*bteam_itr)->size()) == 0) {
                    std::string s4 = (*bteam_itr)->get_team();
                    std:: cout<<std::endl<<"Team "<<s4<<" is defeated!"<<std::endl;
                    (*bteam_itr) = NULL;
                } else  {
                victor = *bteam_itr;
                battle_player++;
                }
            }
        }
        // Do we have winner?
        if (battle_player==1){
            game_over = true;
            break;
        }

        //Change battle order
        if (battle_num % 3 == 0) {
            bteam_itr = battle_order.begin();
            bteam_itr++;
            battle_order.insert(bteam_itr, battle_order.back());
            battle_order.pop_back();
        } else {
            battle_order.push_back(battle_order.front());
            battle_order.erase(battle_order.begin());
        }
        battle_num++;
        std::cout<<std::endl;
    }
    // Print Stat
    std::cout<<std::endl<<"STATISTICS"<<std::endl;
    std::cout<<"=========="<< std::endl;
    std::string v = victor->get_team();
    std::cout<<"Victor:"<< v <<std::endl;
    std::cout<<"Battles:"<< (battle_num) <<std::endl;

    std::cout << "Fallen:" << std::endl;
    for (hero_itr = dead_pool.begin(); hero_itr != dead_pool.end(); hero_itr++) {
        std::cout << "\t"<<*(*hero_itr) << std::endl;
    }
    std::cout << "Damage:" << std::endl;
    std::map<hero::Hero *, unsigned int>::iterator score_itr = damage_scores.begin();
    for (score_itr = damage_scores.begin(); score_itr != damage_scores.end(); score_itr++) {
        std::cout << "\t"<<(score_itr->first)->get_name() << ": " << (score_itr->second) << std::endl;
        delete (*score_itr).first;
    }
    for (bteam_itr = print_order.begin(); bteam_itr != print_order.end(); bteam_itr++) {
        delete (*bteam_itr);
    }
}