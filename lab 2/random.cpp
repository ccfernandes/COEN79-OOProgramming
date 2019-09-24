//
//  random.cpp
//  Lab2
//
//  Created by aiyushi kumar on 4/10/19.
//  Copyright © 2019 scu. All rights reserved.
//

#include "random.hpp"
#include <iostream>

using namespace std;
using namespace coen79_lab2;



//CONSTRUCTOR
rand_gen::rand_gen(int newSeed, int newMultiplier, int newIncrement, int newModulus)
{
    seed = newSeed;
    multiplier = newMultiplier;
    increment = newIncrement;
    modulus = newModulus;
    
}

//DESTRUCTOR
rand_gen::~rand_gen()
{
    seed = 0;
    multiplier = 0;
    increment = 0;
    modulus = 0;
}

//generate next num
int rand_gen::next()
{
    seed = (multiplier * seed + increment) % modulus;
    return seed;
}

void rand_gen::print_info()
{
    std::cout << "seed:";
    std::cout << seed << std::endl;
    
    std::cout << "multiplier:";
    std::cout << multiplier << std::endl;
    
    std::cout << "increment:";
    std::cout << increment << std::endl;
    
    std::cout << "modulus:";
    std::cout << modulus << std::endl;
}
