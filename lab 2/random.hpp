//
//  random.hpp
//  Lab2
//
//  Created by aiyushi kumar on 4/10/19.
//  Copyright © 2019 scu. All rights reserved.
//

#ifndef random_hpp
#define random_hpp

#include <stdio.h>
#include <iostream>
#include <cassert>

using namespace std;

namespace coen79_lab2
{
class rand_gen
{
public:
    //CONSTRUCTOR
    rand_gen(int newSeed = 1, int newMultiplier = 1, int newIncrement = 1, int newModulus = 1);
    
    //DESTRUCTOR
    ~rand_gen();
    
    //change the value of seed
    void set_seed(int newSeed) { seed = newSeed; }
    //generate next num
    int next();
    
    //print private information
    void print_info();

private:
    int seed;
    int multiplier;
    int increment;
    int modulus;
    
};
}


#endif /* random_hpp */
