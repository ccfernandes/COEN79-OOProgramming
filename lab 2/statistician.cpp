//
//  statistician.cpp
//  lab2
//
//  Created by chelsea fernandes on 4/10/19.
//  Copyright © 2019 SCU. All rights reserved.
//

#include "statistician.hpp"

using namespace std;
namespace coen79_lab2
{

statistician::statistician()//constructor
{
    tiniest=0;
    largest=0;
    total=0;
    count=0;
}

void statistician::reset()
{
    tiniest=0;
    largest=0;
    total=0;
    count=0;
}

void statistician::next(double r)
{
    if(count==0)
    {
        tiniest = r;
        largest = r;
    }
    if(r<tiniest){
        tiniest=r;
    }
    if(r>largest){
        largest=r;
    }
    total+=r;
    count++;
}

double statistician::mean( ) const
{
    if(count==0){
        return 0;
    }
    else return total/count;
}

double statistician::minimum( ) const
{
    if(count==0){
        return 0;
    }
    else return tiniest;
}


double statistician::maximum( ) const
{
    if(count==0){
        return 0;
    }
    else return largest;
    
}

statistician operator + (const statistician &s1, const statistician &s2)
{
    if(s1.total==0){
        throw;
    }
    statistician newVal = statistician(); //i need the constructor
    newVal.count=s1.count + s2.count;
    newVal.total=s1.total+s2.total;
    if(s1.largest>s2.largest){
        newVal.largest = s1.largest;
    }
    else{
        newVal.largest=s2.largest;
    }
    
    if(newVal.tiniest<s2.tiniest){
            newVal.tiniest=s1.tiniest;
    }
    else{
        newVal.tiniest=s2.tiniest;
    }
    
    return newVal;
}

statistician operator *(double scale, const statistician& s)
{
    statistician temp = statistician();
    temp.count = s.count;
    temp.total = scale*s.total;
    temp.tiniest = scale *s.tiniest;
    temp.largest = scale*s.largest;

    return temp;
}

bool operator ==(const statistician& s1, const statistician& s2)
{
    if(s1.count==s2.count){
        return true;
    }
    if(!(s1.mean()==s2.mean()||!(s1.total==s2.total))||!(s1.largest==s2.largest)||!(s1.tiniest==s2.tiniest)){
        return false;
    }
    return true;
}
}
