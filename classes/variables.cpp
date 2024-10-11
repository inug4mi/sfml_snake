#include "variables.hpp"

namespace GEngine{
    // Constructor
    Variables::Variables() : 
        pause(false), 
        gameLost(false), 
        score(0) {
        //std::mt19937 gen(rd());
    }

    int Variables::generateRandomInt(int from, int to) {
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(from,to);
        return distr(gen);
    }
}