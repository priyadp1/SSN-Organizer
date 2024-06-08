#include <iostream>
#include "node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
    public:
    // default constructor
    SLL(){
        headPtr = nullptr;
        size = 0;
    }

    // destructor
    ~SLL(){
        while(headPtr != nullptr){
            Node<U>* temp = headPtr;
            headPtr = headPtr->next;
            delete temp;
            temp = nullptr;
        }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
        Node<U>* n1 = new Node<U>;
        n1->SSN = item1;
        n1->name = item2;
        n1->next = nullptr;
        if(headPtr == nullptr){//Checks if the list is empty
            headPtr = n1;
        }
        else {
            n1->next = headPtr;
            headPtr = n1;
             }
            size++;
            
        }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
    Node<U>* n1 = headPtr;
        while(n1 != nullptr){
            if(n1->SSN == item1){
                return n1;
            }
                n1 = n1->next;
        }
        return nullptr;
    }
    
    // remove the node with key value: item1
    bool remove(U item1){
        Node<U>* n1 = headPtr;
            if (n1 == nullptr) { // Checks if list is empty
                return false;
            }
            else {
                if (n1->SSN == item1) { // Removing first element
                    headPtr = n1->next;
                    delete n1;
                    n1 = nullptr;
                    return true;
                }
                while (n1->next != nullptr) {
                    if (n1->next->SSN == item1) { // Removing middle or last element
                        Node<U>* temp = n1->next;
                        n1->next = n1->next->next;
                        delete temp;
                        temp = nullptr;
                        return true;
                        break;
                    }
                    n1 = n1->next;
                }
            }
            size--;
        return false;
    }
    
    int getSize(){
        
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};
