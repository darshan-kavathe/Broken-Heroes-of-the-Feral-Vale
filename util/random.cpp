#include "random.h"

using util::Random;

using std::random_device;

Random::Random() :
        Random{random_device{}()} {
}

Random::Random(unsigned long long seed) :
        gen_{seed},
        dis_{} {
}

void Random::set_seed(unsigned long long seed) {
    gen_.seed(seed);
}

unsigned int Random::roll_dice(unsigned int min, unsigned int max) {
    return min + static_cast<unsigned int>(rand() % (max - min + 1));
}

unsigned long long Random::rand() {
    return dis_(gen_);
}
