// FILE: company.h
// PROVIDES: A class for storing a company's products' information including
// its name, as well as pointers to a linked list that store
// products information of the company
//

#ifndef COMPANY_H
#define COMPANY_H

#include "node.h"

namespace coen79_lab7
{
    class company {
        
    public:
        
        //CONSTRUCTORS AND DESTRUCTOR
        company();
        company(const std::string& company_name);
        company(const company& src);
        ~company();
        
        // Modification member functions
        node* get_head();
        node* get_tail();
        bool insert(const std::string& product_name, const float& price);
        bool erase(const std::string& product_name);
        company& operator= (const company& src);
        
        // Constant member functions
        void set_Name(const std::string &entry){
//            std::strcpy(company_name, entry);
            company_name = entry;
        }
        const node* get_head() const;
        const node* get_tail() const;
        std::string get_name() const;
        void print_items();
        
    private:
        std::string company_name; // Name of company
        node* head_ptr; // Head of the linked list including company's products
        node* tail_ptr; // Tail of the linked list including company's products
    };
}

#endif
