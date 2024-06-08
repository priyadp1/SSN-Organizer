#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <ctime>
using  namespace  std;

template <class T>
struct  Node{
  T SSN;
  T name;
  Node<T>*  next;
};
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
        }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    void insert(U item1, U item2){
        Node<U>* n1 = new Node<U>;
        Node<U>* result = search(item1);
        n1->SSN = item1;
        n1->name = item2;
        if(result == nullptr){
            if(headPtr == nullptr){//Checks if the list is empty
                headPtr = n1;
                n1->next = nullptr;
            }
            else {
                if (item1 < headPtr->SSN) {//Checks if the ssn's in the list is greater or equal to the ss in question//
                    n1->next = headPtr;
                    headPtr = n1;
                }
                else {//Checks if the ssn's in the list is less than the ss in question//
                    Node<U>* curr = headPtr;
                    while (curr->next != nullptr && curr->next->SSN < item1) {
                        curr = curr->next;
                    }
                    n1->next = curr->next;
                    curr->next = n1;
                    
                }
            }
        }
        else{
            cout << " " << endl;
        }
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
        Node<U>* result = search(item1);
        if (result != nullptr) {
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
        }
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

int main(int argc, char* argv[]) {
    SLL<string>* tempSLL = new SLL<string>;
      int numbOfElements = iCounter - dCounter;
      double duration;
      end = clock();
      duration = ( end - start ) / (double) CLOCKS_PER_SEC;
      cout << "The Number of Valid Insertion : " << iCounter << endl;
      cout << "The Number of Valid Deletion : " << dCounter << endl;
      cout << "The Number of Valid Retrieval : " << rCounter << endl;
      cout << "Item numbers in the List : " << numbOfElements << endl;
      cout << "Time elapsed : " << duration << endl;
      
  }
