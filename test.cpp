#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char* argv[]){
    vector < vector <int> > vec;
    vec.resize(5);
    for(int i=0; i< 5; i++)
        vec[i].resize(6);
    for(int i=0; i<5;i++)
        for(int j=0; j<=i;j++)
            vec[i][j] = j;
    for(int i=0; i<5;i++){
        for(int j=0; j<6; j++){
            cout << vec[i][j] << "\t";
        }
        cout << endl;
        
    }
}
