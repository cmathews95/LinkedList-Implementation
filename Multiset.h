
#ifndef __CS32_P3__Multiset__
#define __CS32_P3__Multiset__
#include <string>
#include "OurType.h"

//typedef unsigned long ItemType;
//typedef std::string ItemType;
typedef OurType ItemType;
//#include "IntWrapper.h"      // TODO: remove this line after testing
//typedef IntWrapper ItemType; // TODO: replace this line after testing


class Multiset
{
public:
    Multiset();
    ~Multiset();
    Multiset(const Multiset& other);
    Multiset& operator=(const Multiset& rhs);
    bool empty() const;
    int size() const;
    int uniqueSize() const;
    bool insert(const ItemType& value);
    int erase(const ItemType& value);
    int eraseAll(const ItemType& value);
    bool contains(const ItemType& value) const;
    int count(const ItemType& value) const;
    int get(int i, ItemType& value) const;
    void swap(Multiset& other);
private:
    struct node{
        ItemType value;
        int number;
        node* prev;
        node* next;
    };
    node *head;
    int u_size;
    int t_size;
    
};

void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result);
void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result);
#endif /* defined(__CS32_P3__Multiset__) */

