// FILE: company.cpp
// CLASS implemented: company (see company.h for documentation)


#include <cassert>
#include "company.h"
#include "node.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    company::company(const std::string&name) {
        company_name=name;
        assert(company_name.length() > 0);
        head_ptr=NULL;
        tail_ptr=NULL;
    }
    
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);
        head_ptr=NULL;
        tail_ptr=NULL;
        list_copy(src.head_ptr, head_ptr, tail_ptr);
        company_name = src.company_name;
    }

    company& company::operator= (const company &src) {
        Debug("Company assignemnt operator..." << std::endl);
        if(this==&src)
            return *this;
        
        this->company_name=src.company_name;
        list_copy(src.head_ptr, this->head_ptr, this->tail_ptr);
        
        return *this;
    }
    
    company::~company() {
        list_clear(head_ptr);
    }
    
    std::string company::get_name() const {
        return company_name;
    }
    
    const node *company::get_head() const {
        return head_ptr;
    }
    
    const node *company::get_tail() const {
        return tail_ptr;
    }
    
    node* company::get_head() {
        return head_ptr;
    }
    
    node* company::get_tail() {
        return tail_ptr;
    }
    
    void company::print_items() {
        list_print(head_ptr);
    }
    
    
    bool company::insert(const std::string& product_name, const float& price) {
        assert(product_name.length() > 0);
        
        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }
        
        if (head_ptr == NULL) {
            head_ptr = new node(product_name, price, head_ptr);
            tail_ptr=head_ptr;
        }
        else {
            list_tail_insert(tail_ptr, product_name, price);
        }
        
        return true;
    }

    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);
        node* current = head_ptr;
        node *prev= current;
        while(current!=NULL){ //in order to get a previous node.
            if(product_name==current->getName()){
                break;
            }
            prev=current;
            current=current->getLink();
        }
        if(current==NULL)
            return false;
        
        if(current==head_ptr){
            list_head_remove(head_ptr);
        }
        else if(current==tail_ptr){
            tail_ptr=prev;
            delete current;
        }
        else{
            prev->setLink(current->getLink());
            delete current;
        }
            return true;
    }
    
}
