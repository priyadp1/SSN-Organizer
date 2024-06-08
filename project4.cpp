#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <string>
#include <time.h>
#include <ctime>
using namespace std;
int main(int argc, char* argv[]){
    HashTable<string>* tempT = new HashTable<string>(10007);
      string digits = "0123456789";
      string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      int iCounter = 0;
      int dCounter = 0;
      int rCounter = 0;
      string filename = argv[1];
      fstream input;
      clock_t start, end;
      start = clock();
      input.open(filename);
      string line;
      while(!input.eof()){
          getline(input , line);
          if(line.length() > 0){
              char command;
              command = line[0];
              int ssnPos = (int) line.find_first_of(digits);
              string ssn = line.substr(ssnPos , 9);
              long firstPartOfName = line.find_first_of(letters);
              long lastPartOfName = line.find_last_of(letters);
              string name = line.substr(firstPartOfName , lastPartOfName);
              if(command == 'i'){
                  if(tempT->insert(ssn , name) == true){
                      iCounter++;
                  }
                  
                  }
                  else if(command == 'r'){
                      if(tempT->find(ssn) == true){
                          rCounter++;
                      }
                 
                  }
                  else if(command == 'd'){
                      if(tempT->erase(ssn) == true){
                          dCounter++;
                      }
                  }
          }
      }
      input.close();
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
