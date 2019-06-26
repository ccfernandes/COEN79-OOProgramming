//
//  mystring.cpp
//  lab5
//
//  Copyright © 2019 SCU. All rights reserved.
//
//  

#include "mystring.hpp"
#include <cstring>
#include <string.h>
#include <cassert>

using namespace coen79_lab5;

namespace coen79_lab5{
	using  std::cout;
	using  std::ostream;
	using  std::istream;
	
	string::string(const char str[ ]){
		current_length=(int)strlen(str);
		allocated=current_length+1;
		characters=new char[allocated];
		strcpy(characters, str);
	}
	
	string::string(char c){
		current_length=1; //string has only one character
		allocated=current_length+1;
		characters=new char[allocated];
		characters[0]=c;
		characters[1]='\0';
	}
	
	string::string(const string& source){ //copy constructor
        characters = NULL;
        allocated = 0;
        current_length = source.length();
        reserve(current_length+1);
        
        strncpy(characters, source.characters, allocated);
	}
	
	string::~string()	{
		current_length = 0;
		allocated = 0;
		delete[] characters;
	}
	
	void string::operator +=(const string& addend){
		size_t newLength = this->current_length + addend.current_length;
		char *temp = new char[newLength];
		
		//store LHS/this data into a temp array
		for(int i = 0; i < this->current_length; i++)	{
			temp[i] = this->characters[i];
		}
		//add the addend data to the end of temp array
		int k = 0;
		for(int j = this->current_length; j < newLength; j++)	{
			temp[j] = addend.characters[k];
			k++;
		}
		
		//replace data in LHS/this with data in temp
		this->current_length = newLength;
		this->allocated = current_length+1;
		for(int n = 0; n < newLength; n++)	{
			this->characters[n] = temp[n];
		}
	}
	
	void string::operator +=(const char addend[ ])	{
		string temp(addend);
		*this += temp;
	}
	
	void string::operator +=(char addend)	{
		this->characters[current_length] = addend;
		this->current_length++;
		this->allocated++;
	}
	
    void string::reserve(size_t n)
    {
        //This version of reserve will never reduce the size of the array.
        char *new_characters;
        
        if (n == allocated)
        return;
        
        if (n < current_length + 1)
        n = current_length + 1;
        
        new_characters = new char[n];
        
        if (characters != NULL) {
            strncpy(new_characters, characters, n);
            delete [] characters;
        }
        
        characters = new_characters;
        allocated = n + 1;
    }
    
    
	string& string::operator =(const string& source)	{
		if(this == &source) return *this;
		
		this->current_length =  source.current_length;
		this->allocated = source.allocated;
		this->characters= new char[allocated];
		
		for(int i = 0; i < current_length; i++)	{
			this->characters[i] = source.characters[i];
		}
		return *this;		
	}
	
	void string::insert(const string& s, unsigned int position){
		assert(position<=length());

        string oldThis = *this;
        // Copy everything up to the desired insertion location.
        strncpy(characters, oldThis.characters, position);
        characters[position] = '\0';
        std::cout << "char::" << characters << std::endl;
        // Insert the source string.
        strncat(characters, s.characters, allocated - position);

        // Copy the rest of the original string.
        strncat(characters, (oldThis.characters) + position, allocated - (position+s.current_length));

        // Extra precaution.
        current_length = current_length + s.length();
        allocated = allocated + s.length();
	}
	
	void string::dlt(unsigned int position, unsigned int num)	{
		assert((position + num) <= length());
		int newlen = (int)current_length-num;
		int counter=0;
		char *newstring = new char[newlen];
		for(int i=0;i<current_length; i++){
			if(i>=position && i<=(position+num)){
				//continue looping
			}
			else {
				newstring[counter]=characters[i];
				counter++;
			}
		}
		newstring[counter]='\0';
		strcpy(this->characters, newstring);
	}

	void string::replace(char c, unsigned int position){
		assert(position<length());
		for(int i=0; i<length(); i++){
			if(i==position){
				characters[i]=c;
				break;
			}
		}
		return;
	}
    
         Precondition: position < length()
         Postcondtion: the character at the given position in the string is
         replaced with c.
	
	void string::replace(const string& source, unsigned int position){
        assert((position + source.current_length) <= length());
        std::copy(source.characters, source.characters + source.current_length, characters + position);
	}
	
	// CONSTANT MEMBER FUNCTIONS for the string class:
	char string::operator [ ](size_t position) const{
		assert(position < current_length);
		return characters[position];
	}

	int string::search(char c) const{
		for(int i=0; i<length();i++){
			if(characters[i]==c){
				return i;
			}
		}
		return -1;
	}

	int string::search(const string& substring) const{
        int found = 1;
        int scount = 0;
        for(int i=0; i<current_length; i++){
            if(characters[i]==substring.characters[scount]){
                found=i;
                scount++;
                for(int j=i; j<substring.length(); j++){
                    if(characters[j]!=substring.characters[scount]){
                        break;
                    }
                    else{
                        scount++;
                    }
                }
            }
        }
        return found-(substring.length()-1);
	}

	unsigned int string::count(char c) const{
		int count=0;
		for(int i=0; i<length(); i++){
			if(characters[i]==c){
				count++;
			}
		}
		return count;
	}

	// NON-MEMBER FUNCTIONS for the string class:
    string operator +(const string& s1, const string& s2){
        string temp(s1);
        temp+=s2;
        return temp;
    }
    
    string operator +(const string& s1, const char addend[ ]){
        string temp(s1);
        temp+=addend;
        return temp;
    }
    
    istream& operator >>(istream& ins, string& target){
        char inputArr;
        while (!ins.eof( ) && isspace(ins.peek( )))
        ins.ignore( );

        target = "";
        while (!ins.eof( ) && !isspace(ins.peek( )))
        {
            ins >> inputArr;
            target += inputArr;
        }
        
        return ins;
    }
    
	ostream& operator <<(ostream& outs, const string& source){
        outs<<source.characters;
		return outs;
	}

    bool operator ==(const string& s1, const string& s2){
        size_t temp;
        if(s1.length()!=s2.length())
            return false;
        if(s1.length()>s2.length())
            temp=s1.length();
        else
            temp=s2.length();
    
        for(int i=0; i<temp; i++){
            if(s1[i]==s2[i]){
                //continue looping
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool operator !=(const string& s1, const string& s2){
        return !(s1==s2);
    }

    bool operator >(const string& s1, const string& s2){
        size_t temp;
        if(s1.length()>s2.length())
            temp=s1.length();
        else
            temp=s2.length();
        for(int i=0; i<temp; i++){
            if(s1[i]>s2[i]){
                return true;
            }
        }
        return false;
    }

    bool operator <(const string& s1, const string& s2){
        return s2>s1;
    }

    bool operator >=(const string& s1, const string& s2){
        if(s1==s2)
            return true;
        else
            return s1>s2;
    }

    bool operator <=(const string& s1, const string& s2){
        if(s1==s2)
            return true;
        else
            return s1<s2;
    }
}
