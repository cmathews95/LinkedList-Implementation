
#include "Multiset.h"

#include <iostream>


//Basic Constructor-set values to 0 and create a dummy node that points to itself
Multiset::Multiset()
:u_size(0), t_size(0), head(nullptr)
{
    this->head = new node;
    this->head->next = this->head;
    this->head->prev = this->head;
}

//Basic Deconstructor-using two pointers to nodes, tranverse the nodes from the end to the beginning.
//point x to a node and then copy prev vale of x to y.
//delete x and then set x = y.
Multiset::~Multiset(){
    node* x;
    node* y;
    for(x = head->prev; x!= head;){
        y = x->prev;
        delete x;
        x = y;
    }
    delete x;
}

//Copy Constructor: First a dummy node is created that points to itself.
//I use a for loop to iterate through the list of the other object
//I then set the value of each head in the new object to tha values of the
//other object. Finally, I set the prev and next values to the appropriate nodes
Multiset::Multiset(const Multiset& other)
:head(nullptr), u_size(other.u_size), t_size(other.t_size)
{
    head = new node;
    head->next = head;
    head->prev = head;

    node* x;
    for(x = other.head->next; x!= other.head; x = x->next){
        node* p = new node;
        p->value = x->value;
        p->number = x->number;
        
        p->prev = head->prev;
        head->prev->next = p;
        head->prev = p;
        p->next = head;
    }

}

//The copy assignment operator. I first checked for
//aliasing. Then I created a temp object using the
//copy constructor. I then swapped ithe original object
//with the temp object. Finally I returned the object
Multiset& Multiset::operator=(const Multiset& rhs){
    if (this != &rhs){
        Multiset temp(rhs);
        swap(temp);
    }
    return (*this);
}

//return true if the list is empty & false otherwise.
//I base whether or not it's empty based on the size
bool Multiset::empty() const{
    if(t_size == 0)
        return true;
    return false;
}

//return the number of total items in the multiset.
//this isn't the number of unique items
int Multiset::size() const{
    return t_size;
}

//return the unique number of items in the multiset.
//in other words, this is the number of nodes in the
//object.
int Multiset::uniqueSize() const{
    return u_size;
}

//Function to insert a new value. First I check to see if
//it already exists in the function. If so, I increment the
//number of the node. Otherwise I create a new node linking
//it to the previous node and looping it back to the dummy
//node. I added new items at the end of the list. Since I used
//a circularly linked list I connected the last nodes in the list
//back to the head nodes
bool Multiset::insert(const ItemType &value){
    node* x;
    for(x = head->next; x!= head; x = x->next){
        if(x->value == value){
            x->number++;
            t_size++;
            return true;
        }
    }
    
    node* p = new node;
    p->value = value;
    p->number = 1;
        
    p->prev = head->prev;
    head->prev->next = p;
    head->prev = p;
    p->next = head;
    
    u_size++;
    t_size++;
    return true;
}

//Function to remove one instance of a value.
//I use a for loop to find the value if it is in the
//multiset and then decrement its number by 1 and the
//total size by one. Then, if the number is 0 I link
//the previous node to the next node and delete the
//current node-i then decremenet unique size by one if
//i remove an item completely. I return 1 if I deleted
//an instance and else 0.
int Multiset::erase(const ItemType &value){
    node* x;
    for(x = head->next; x!= head; x = x->next)
        if(x->value == value){
            x->number--;
            if(x->number == 0){
                x->prev->next = x->next;
                x->next->prev = x->prev;
                delete x;
                u_size--;
            }
            t_size--;
            return 1;
        }
    return 0;
}

//Function to remove all instances of a value in the
//multiset. I use a for loop to find the value if it exists
//and count its number of instances. I decrement this number
//from the total size and decrement the unique size by one.
//Then I link the previous node to the next node and delete
//the current node. Finally I return the number of instances
//removed
int Multiset::eraseAll(const ItemType &value){
    node* x;
    for(x = head->next; x!= head; x = x->next)
        if(x->value == value){
            int numDeleted = x->number;
            x->prev->next = x->next;
            x->next->prev = x->prev;
            delete x;
            u_size--;
            t_size -= numDeleted;
            return numDeleted;
        }
    return 0;
}

//Function to check if a value exists in a function. I use a
//for loop to transverse the multiset and compare values.
//I return true if the value is in the multiset
bool Multiset::contains(const ItemType &value) const{
    node* x;
    for(x = head->next; x!= head; x = x->next)
        if(x->value == value)
            return true;
    return false;
}

//Function to count the number of instances of a value in a
//multiset. I use a for loop to transverse the multiset and
//find a value. I return the number of instances of that value
int Multiset::count(const ItemType &value) const{
    node* x;
    for(x = head->next; x!= head; x = x->next)
        if(x->value == value)
            return x->number;
    return 0;
}

//For every int entered between 0 and 1 less than the unique
//size (inclusive), this function will return a different value
//into the variable value, and return the number of instances of
//that value.
int Multiset::get(int i, ItemType &value) const{
    if(head->next==head)
        return 0;
    node*p = head->next;
    if(i >= 0 && i < u_size){
        for(int x = 0; x < i; x++){
            p = p->next;
        }
        while(p==head)
            p=p->next;
        value = p->value;
        return p->number;
    }
    return 0;
}

//This function swaps the values of two functions. It creates a temp
//node to hold the value of the head of one object. I then set the head
//of another object to that object, and the other object's head to the temp
//node. I then swap the unique and total sizes of the two objects.
//To swap two objects you just need to change their heads and size
//member values
void Multiset::swap(Multiset &other){
    node* temp = head;
    head = other.head;
    other.head = temp;
    
    int t_size2 = t_size;
    int u_size2 = u_size;
    t_size = other.t_size;
    u_size = other.u_size;
    other.u_size = u_size2;
    other.t_size = t_size2;
}

//I copy construct a temp object with ms1. I then use a for loop of
//ms2.uniqueSize() to get all the different values of ms2 with
//the get function. I then use a for loop of the number of instances of the value
//and the insert function to add the value the correct number of times.
void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result){
    Multiset temp(ms1);
    for(int i = 0; i < ms2.uniqueSize(); i++){
        ItemType value;
        int r = ms2.get(i, value);
        for(int k = 0; k < r; k++)
            temp.insert(value);
    }
    result = temp;
}

//I copy construct a temp object with ms1. I then use a for loop of
//ms2.uniqueSize() to get all the different values of ms2 with
//the get function. I then use a for loop of the number of instances of the value
//and the delet function to remove each applicable value the correct number of times.
void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result){
    Multiset temp(ms1);
    for(int i = 0; i < ms2.uniqueSize(); i++){
        ItemType value;
        int r = ms2.get(i, value);
        for(int k = 0;k < r; k++)
            temp.erase(value);
    }
    result = temp;
}


