#include <cassert>
#include <iostream>

#include "game/squad.h"
#include "util/queue.h"

#include "hero/hero.h"
#include "hero/heroes.h"

class Queue;
using game::Squad;
using hero::Hero;
using hero::Heroes;
using hero::Role;
using hero::Team;


using util::Queue;

using std::cout;
using std::deque;
using std::endl;
using std::string;

/**
 * This is a test program for the util/Queue templated class.  It tests
 * the queue with three types: int, string, and Hero*.
 *
 * @author Sean Strout @ RIT CS
 */

/**
 * Run the int test
 */

void test_int_Queue() {
    cout << "test Queue<int>..." << endl;
    Queue<int> intQueue;
    intQueue.add(10);
    intQueue.add(20);
    intQueue.add(30);
    assert(intQueue.front() == 10);
    assert(intQueue.size() == 3);
    assert(intQueue.remove() == 10);
    assert(intQueue.size() == 2);
    intQueue.add(40);
    deque<int> members = intQueue.get_elements();
    assert(members[0] == 20);
    assert(members[1] == 30);
    assert(members[2] == 40);
}

/**
 * Run the string test
 */
void test_string_Queue() {
    cout << "test Queue<string>..." << endl;
    Queue<string> strQueue;
    strQueue.add("a");
    strQueue.add("b");
    strQueue.add("c");
    assert(strQueue.front() == "a");
    assert(strQueue.size() == 3);
    assert(strQueue.remove() == "a");
    assert(strQueue.size() == 2);
    strQueue.add("d");
    deque<string> members = strQueue.get_elements();
    assert(members[0] == "b");
    assert(members[1] == "c");
    assert(members[2] == "d");

}

/**
 * Run the Hero* test
 */

void test_hero_Queue() {
    cout << "test Queue<Hero>..." << endl;
    Queue<Hero*> heroQueue;
    game::Squad squad;
    heroQueue.add(Hero::create_hero(Role::FIGHTER, Team::Name::DRAGON, &squad));
    heroQueue.add(Hero::create_hero(Role::HEALER, Team::Name::DRAGON, &squad));
    heroQueue.add(Hero::create_hero(Role::TANK, Team::Name::DRAGON, &squad));
    assert(heroQueue.front()->get_name() == "Trogdor");
    assert(heroQueue.front()->get_team_name() == Team::Name::DRAGON);
    assert(heroQueue.size() == 3);
    Hero* hero = heroQueue.remove();
    assert(hero->get_name() == "Trogdor");
    delete hero;
    assert(heroQueue.size() == 2);
    heroQueue.add(Hero::create_hero(Role::FIGHTER, Team::Name::DRAGON, &squad));
    deque<Hero*> members = heroQueue.get_elements();
    assert(members[0]->get_name() == "Spyro");
    delete heroQueue.remove();
    assert(members[1]->get_name() == "Smaug");
    delete heroQueue.remove();
    assert(members[2]->get_name() == "Trogdor");
    delete heroQueue.remove();
}

/**
 * The main program runs all three tests.
 *
 * @return 0
 */
int main() {
    test_int_Queue();
    test_string_Queue();
    test_hero_Queue();
    return 0;
}