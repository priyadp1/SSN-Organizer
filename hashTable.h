#include <iostream>
#include "SLL.h"
using  namespace  std;
template <class V>
class HashTable {
    int tableSize; // table size
    
    SLL<V>* table;
    
public:
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which use size as the table size
    HashTable(int size){
        tableSize = size;
        table = new SLL<V>[tableSize];
    }
    
    // search item in the table
    // if found, return true; otherwise,return false
    bool find(V item){
        int key = stoi(item);
        int hash = key % tableSize;
        Node<V>* result = table[hash].search(item);
        if(result != nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2){
        int key = stoi(item1);
        int hash = key % tableSize;
        if(table[hash].search(item1) == nullptr){
            table[hash].insert(item1 , item2);
            return true;
        }
        else{
            return false;
        }
    }
    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false
    bool erase(V item){
        int key = stoi(item);
        int hash = key % tableSize;
        if(table[hash].search(item) != nullptr){
            table[hash].remove(item);
            return true;
        }
        else{
            return false;
        }
    }
    // return the total number of nodes in the hash table
    int getSize(){//SLL getSize()
        int size = 0;
        for(int i = 0; i < tableSize; i++){
            size += table[i].getSize();
        }
        return size;
    }

};
