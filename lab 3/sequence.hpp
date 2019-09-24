//
//  sequence1.hpp
//  lab3
//
//  Created by Chelsea Fernandes on 4/17/19.
//  Copyright © 2019 SCU. All rights reserved.
//
// Sequence.cpp contains functions you may want to perform on a sequence.

#ifndef COEN79_SEQUENCE1_H
#define COEN79_SEQUENCE1_H

#include <iostream>

namespace coen79_lab3{
    
    class sequence{
    public:
        // TYPEDEF and MEMBER CONSTANTS
        typedef double value_type;
        typedef double Item;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        
        //constructor
        sequence( );
        sequence(const sequence* s);

        //MEMBER FUNCTIONS
        void start();
        void end();
        void last();
        value_type current() const;
        void advance();
        void retreat();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void insert_front(const value_type& entry);
        void attach_back(const value_type& entry);
        void remove_front();
        sequence operator +=(const sequence& rhs);

        //CONSTANT MEMBER FUNCTIONS
        size_type size() const;
        bool is_item( ) const;
        
        //Item current( ) const;
        Item operator[](int index) const;
        double mean() const;
        double standardDeviation() const;
        value_type summation( sequence &s);
        
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
    sequence operator+(sequence& lhs, sequence& rhs);
}
#endif
