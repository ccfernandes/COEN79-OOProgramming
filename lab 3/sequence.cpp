//
//  sequence.cpp
//  lab3
//
//  Created by Chelsea Fernandes on 4/17/19.
//  Copyright © 2019 SCU. All rights reserved.
//

#include "sequence1.hpp"
#include <iostream>
#include <cmath>

using namespace coen79_lab3;
namespace coen79_lab3 {

    sequence::sequence(){
        used=0;
        current_index=-1;
    }

    sequence::sequence(const sequence* s){
        sequence();
        *this=s;
    }
    
    void sequence::start(){
        current_index= 0;
    }
    void sequence::end(){
        current_index=used-1;
    }
    
    void sequence::last(){
        current_index=-1;
    }
    
    sequence::value_type sequence::current() const{
        if(is_item()){
            return data[current_index];
        }
        return -1;
    }
    
    void sequence::advance(){
        if(is_item()){
            current_index++;
        }
    }
    void sequence::retreat(){
        if(is_item()){
            current_index--;
        }
    }
    void sequence::insert(const value_type& entry){
        assert(size()<CAPACITY);
        if(used==0){
            data[used]=entry; //one item inserted
            current_index=0;
        }
        else {
            for ( int i=used;i>=current_index+1;--i){ //insert new item in front of index
                data[i]=data[i-1];
            }
            data[current_index]=entry; //new item is now current item of sequence
        }
        
        used++; //increment size
    }
    void sequence::attach(const value_type& entry){
        assert(size()<CAPACITY);
        if (!is_item()){ //if no current item, place in end
            data[used]=entry;
        }
        else {
            for ( int i=used;i>current_index +1;--i){
                data[i]=data[i-1];
                //shift everything to right, make room to attach entry behind current_index
            }
            data[current_index+1]=entry;
            current_index=current_index+1;
        }
        used++; //increment size
    }

    void sequence::remove_current(){
        if(is_item()){
            for(int i=(int)current_index; i<used; i++){
                data[i]=data[i+1];
            }
            used--;
        }
    }

    void sequence::insert_front(const value_type& entry){
        if(is_item()){
            current_index=0;
            insert(entry);
            used++; //increment size
        }
    }

    void sequence::attach_back(const value_type& entry){
        assert(size()<CAPACITY);
        data[used]=entry; //attach at end
        used++; //increment size
    }

    void sequence::remove_front(){
        if(is_item()){
            for(int i=0; i<used-1; i++){
                data[i]=data[i+1];
            }
            used--;
            current_index=0;
        }
    }

    sequence sequence::operator +=(const sequence& rhs){
        sequence n(rhs); //copy of lhs
        int start=(int) rhs.used;
        n.used=rhs.used+rhs.used;
        
        for ( int i=0;i<rhs.used;++i){ //add everything from rhs to lhs
            n.data[start]=rhs.data[i];
            start++;
        }
        return n;//return copy of lhs, executes
    }

    //CONSTANT MEMBER FUNCTIONS
    
    sequence::size_type sequence::size() const{
        return used;
    }
    
    bool sequence::is_item() const{
        if(current_index<used)
            return true;
        else
            return false;
    }

    sequence::Item sequence::operator[](int index) const{
        assert(index<used);
        return data[index];
    }

    
    double sequence::mean() const{
        double sum=0;
        for(int i=0; i<used; i++){
            sum+=data[i];
        }
        return sum/size();
    }
    double sequence::standardDeviation() const{
        double mean1 = mean();
        double stdev=0;
        for(int i=0; i<used; i++){
            stdev+=pow((data[i]-mean1), 2);
        }
        stdev/=used;
        return sqrt(stdev);
    }

    sequence operator+(sequence& lhs, sequence& rhs) {
        assert(lhs.size() + rhs.size() <= sequence::CAPACITY);
        sequence newSequence;
        newSequence.start();
        
        lhs.start();
        for (int i = 0; i < lhs.size(); i++) {
            newSequence.attach(lhs.current());
            lhs.advance();
        }
        
        rhs.start();
        for (int i = 0; i < rhs.size(); i++) {
            newSequence.attach(rhs.current());
            rhs.advance();
        }
        
        return newSequence;
    }


    sequence::value_type sequence::summation(sequence &s){
        double sum=0;
        for(int i =0 ; i<s.size();i++)
            sum = sum +s[i];
        return sum;
    }
}
