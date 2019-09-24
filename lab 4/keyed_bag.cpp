//
//  keyed_bag.cpp
//  lab4
//
//  Created by Chelsea Fernandes on 4/22/19.
//  Copyright © 2019 SCU. All rights reserved.
//

# include "keyed_bag.hpp"
# include <cstring>
# include <string>
#include <iostream>

namespace coen79_lab4
{
    keyed_bag::keyed_bag(){
        used=0;
    }
    
    void keyed_bag::erase(){
        for(int i=0; i<used; i++){
            keys[i]="";
            data[i]=-1;
        }
        used=0;
    }
    
    bool keyed_bag::erase(const key_type& key){
        int index=0;
        if(has_key(key)){
            for(int i=0; i<used; i++){
                if(keys[i]==key){
                    index = i;
                    break;
                }
            }
            for(int j=index; j<used; j++){
                keys[j]=keys[j+1];
                data[j]=data[j+1];
            }
        used--;
        return true;
        }
        return false;
    }
    
    void keyed_bag::insert(const value_type &entry, const key_type &key){
        assert(size()<CAPACITY);
        if(!has_key(key)){
            keys[used]=key;
            data[used]=entry;
            //cout<<"I will insert key "<<key<<endl;
            //cout<<"key is "<<keys[used]<<" and data is "<<data[used]<<endl;
            used++;
        }
    }
    
    void keyed_bag::operator +=(const keyed_bag& addend){
        assert(size() + addend.size() <= CAPACITY);
        for(int i=0; i<used; i++){
            if(hasDuplicateKey(addend)){
                return;
            }
        }
        if(this->isEmpty()){
            erase();
        }
        for(int i=0; i<addend.used; i++){
            this->data[i]=addend.data[i];
            this->keys[i]=addend.keys[i];
            
        }
        this->used=addend.used;
    }

    bool keyed_bag::isEmpty() const{
        return used==0;
    }
    
    bool keyed_bag::has_key(const key_type &key) const {
        for(int i=0; i<used; i++){
            if(keys[i]==key){
                return true;
            }
        }
        return false;
    }
    
    //data value corresponding to the given key is returned.
    keyed_bag::value_type keyed_bag::get(const key_type& key) const{
        //value_type temp = 0;
        if(has_key(key)){
            for(int i=0; i<used; i++){
                if(keys[i]==key){
                    return data[i];
                }
            }
        }
        return 0;
    }
    
    keyed_bag::size_type keyed_bag::count(const value_type& target) const{
        size_type count = 0;
        for(int i=0; i<used; i++){
            if(data[i]==target){
                count++;
            }
        }
        return count;
    }
    
    bool keyed_bag::hasDuplicateKey(const keyed_bag &otherBag) const{
        //int count=0;
        for(int i=0; i<used; i++){
            //if there is a duplicate in bag, return true
            for(int j=0; j<used; j++){
                if(keys[j]==otherBag.keys[i]){
                    return true;
                }
            }
        }
        return false;
    }
    
    //nonmember function
    keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2){
        int b2count = 0;
        assert(b1.size()+b2.size()<=keyed_bag::CAPACITY);
        keyed_bag temp;
        if(b1.hasDuplicateKey(b2)==false){
            temp.used = b1.used+b2.used;
            for(int i=0; i<b1.used; i++){
                temp.keys[i]=b1.keys[i];
                temp.data[i]=b1.data[i];
            }
            for(int j=b1.used; j<temp.used; j++ ){
                temp.keys[j]=b2.keys[b2count];
                temp.data[j]=b2.data[b2count];
                b2count++;
            }
        }
        return temp;
    }
    
}
