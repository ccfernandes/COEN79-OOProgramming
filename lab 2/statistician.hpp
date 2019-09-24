//
//  statistician.hpp
//  lab2
//
//  Created by chelsea fernandes on 4/10/19.
//  Copyright © 2019 SCU. All rights reserved.
//

#ifndef STATS_H
#define STATS_H
#include <iostream>

namespace coen79_lab2
{
    class statistician
    {
    public:
        // CONSTRUCTOR
        statistician( );
        
        // MODIFICATION MEMBER FUNCTIONS
        void next(double r);
        void reset( );
        
        // CONSTANT MEMBER FUNCTIONS
        int length( ) const { return count; }
        double sum( ) const { return total; }
        double mean( ) const;
        double minimum( ) const;
        double maximum( ) const;
        
        // FRIEND FUNCTIONS
        friend statistician operator + (const statistician& s1, const statistician& s2);
        friend statistician operator * (double scale, const statistician& s);
        friend bool operator ==(const statistician& s1, const statistician& s2);
        
    private:
        int count;       // How many numbers in the sequence
        double total;    // The sum of all the numbers in the sequence
        double tiniest;  // The smallest number in the sequence
        double largest;  // The largest number in the sequence
    };
    
    // NON-MEMBER functions for the statistician class
//    bool operator ==(const statistician& s1, const statistician& s2);
    //friend statistician operator + (const statistician& s1, const statistician& s2);
    //friend statistician operator * (double scale, const statistician& s);

}

#endif