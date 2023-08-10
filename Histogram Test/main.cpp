#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

#define mil1     1000000
#define mil10   10000000
#define mil100 100000000
#define Maxnumber 1000000

vector<uint8_t> randGen(uint64_t NumberOfElements){

    vector<uint8_t> temp;
    temp.reserve(NumberOfElements);
    srand(51);
    for (uint64_t i = 0; i < NumberOfElements; i++)
    {
        temp.push_back((((float)rand()/RAND_MAX)*(Maxnumber-1)));
    }
    
    return  temp;
    
}

int main(){
    vector<uint8_t> mil_1;
    vector<uint8_t> mil_10;
    vector<uint8_t> mil_100;
    uint64_t StartTime = 0;
    uint64_t EndTime = 0;

    mil_1.reserve(mil1);
    mil_10.reserve(mil10);
    mil_100.reserve(mil100);

    mil_1 = randGen(mil1);
    mil_10= randGen(mil10);
    mil_100= randGen(mil100);

    cout<<(mil_1.size() == mil1);
    cout<<(mil_10.size() == mil10);
    cout<<(mil_100.size() == mil100)<<endl<<endl<<endl;
    uint64_t i = 0;
    while(1)
    {   
        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        cout<<"Time taken to cross 2 lines:"<<EndTime-StartTime<<"ns"<<endl;
        cout<<"Done : "<<++i<<endl;
        
        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        mil_1[5000];
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        cout<<"Time taken to access 1 million vector   :"<<EndTime-StartTime<<"ns"<<endl;

        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        mil_10[5000];
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        cout<<"Time taken to access 10 million vector  :"<<EndTime-StartTime<<"ns"<<endl;
        
        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        mil_100[5000];
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        cout<<"Time taken to access 100 million vector :"<<EndTime-StartTime<<"ns"<<endl;
        cout<<endl<<endl<<endl<<endl;

    }
}
