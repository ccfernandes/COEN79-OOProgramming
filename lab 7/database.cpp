// FILE: database.cpp
// CLASS implemented: database (see database.h for documentation)

// INVARIANT for the database ADT:
//   1. The items in the database are stored in a dynamic array, where each entry of the array includes
//      a company name, a pointer to the head of the linked list of products, and a
//      a pointer to the tail of the linked list of products
//   2. The number of slots in the array of companies is stored in member varibale aloc_slots
//   3. The number of used slots of the array of companies is stored in member varibale used_slots


#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "database.h"
#include <cstring>

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif


namespace coen79_lab7
{
    
    database::database(const size_type& initial_capacity) {
        used_slots = 0;
        aloc_slots = initial_capacity;
        company_array = new company[aloc_slots];
    }
    
    database::database(const database &src) {
        Debug("Copy constructor..." << std::endl);
        Debug("Copy constructor..." << std::endl);
        this->used_slots=src.used_slots;
        this->aloc_slots=src.aloc_slots;
        this->company_array = new company[aloc_slots];
        for(int i=0;i<this->aloc_slots;i++){
            this->company_array[i]=src.company_array[i];
        }
    }
    
    database& database::operator= (const database &rhs) {
        Debug("Assignment operator..." << std::endl);
        if(this==&rhs)
            return *this;
        this->aloc_slots = rhs.aloc_slots;
        this->used_slots = rhs.used_slots;
        
        for(int i=0; i<used_slots; i++){
            this->company_array[i]=rhs.company_array[i];
            
        }

        return *this;
    }
    
    database::~database() {
        used_slots = 0;
        aloc_slots = 0;
        
        delete[] company_array;
    }
    
    void database::reserve(size_type new_capacity) {
        std::cout << "Reserve..." << std::endl;
        company *new_database;
        
        if (new_capacity < used_slots)
            new_capacity = used_slots; // Can't allocate less than we are using.
        
        new_database = new company[new_capacity];
        
        if(company_array!=NULL){
            for(int i=0; i<used_slots; i++){ //iterate through company array
                new_database[i]=company_array[i];
            }
            company_array = new_database;
            aloc_slots = new_capacity;
            
        }

    }
    
    //    Precondition: company_name is a non-empty string
    //    Postcondition: A new Company is added to the list
    // COMPLETE THE IMPLEMENTATION...
    bool database::insert_company(const std::string &entry) {
        
        Debug("Insert company..." << std::endl);

        assert(entry.length() > 0);
        
        size_type pos = search_company(entry); //the index that the company is located at
        
        // If you find a company that is false, because there are duplicates
        if (pos != COMPANY_NOT_FOUND) {
            return false;
        }
        if(used_slots>=aloc_slots){
            reserve(aloc_slots*2);
        }
        company_array[used_slots].set_Name(entry);
        used_slots++;
        return true;
    }
    
    bool database::insert_item(const std::string &company, const std::string &product_name, const float &price) {
        Debug("Insert item..." << std::endl);

        assert(company.length() > 0 && product_name.length() > 0);
        database::size_type validCompany = search_company(company);
        std::cout<<validCompany;
        if(validCompany==COMPANY_NOT_FOUND){
            return true;
        }
        company_array[validCompany].insert(product_name, price);
        return false;
    }

    bool database::erase_company(const std::string &company) {
        size_type company_index = search_company(company);
        std::cout<<company_index<<std::endl;
        if (company_index ==COMPANY_NOT_FOUND){
            return true;
        }
        for(size_type i=company_index;i<used_slots+1;i++){
            company_array[i] =company_array[i+1];
        }
        used_slots--;
        return false;
    }
    
    
    bool database::erase_item(const std::string& cName, const std::string& pName) {
        assert(cName.length() > 0 && pName.length() > 0);
        size_type pos = search_company(cName);
        if (pos !=COMPANY_NOT_FOUND)
            return(company_array[pos].erase(pName));
        return false;
    }
    
    database::size_type database::search_company(const std::string& company) {
        assert(company.length() > 0);
        
        for(int i=0; i<used_slots; i++){
            if(company_array[i].get_name()==company){
                return i;
            }
        }
        return COMPANY_NOT_FOUND;
    }
    
    
    bool database::print_items_by_company(const std::string& cName) {
        assert(cName.length() > 0);

        size_type c_index = search_company(cName);
        
        if (c_index == COMPANY_NOT_FOUND) {
            return false;
        }
        
        std::cout << "Printing the products of " << cName << ":"<< std::endl;
        company_array[c_index].print_items();
        std::cout << std::endl;
        
        return true;
    }
    
    void database::print_companies() {
        
        std::cout << "Company List" << std::endl;
        for (int i = 0; i < used_slots; i++) {
            std::cout << "- " << company_array[i].get_name() << std::endl;
        }
    }
}

#endif
