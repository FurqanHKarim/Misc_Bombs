#include <iostream>
#include <cstdlib>
#include <fstream>
#include <array>
#include <list>
#include<vector>
#include<chrono>
#include <algorithm>    // std::sort
using namespace std;


struct SortResult;
vector<uint64_t> RandomGenerator(SortResult sample);
vector<uint64_t> sortbyhisto(vector<uint64_t> &V1, SortResult& testCase);
void print_me(vector<uint64_t> V1);
SortResult Dafunc(uint64_t elemCount,uint64_t highestNumber);



int main() {

    vector<SortResult> resultTable;
    for (uint64_t elementCount = 1; elementCount < 100000000; elementCount*= 10)
    {
        for (uint64_t maxNumber = 1; maxNumber < 10000000; maxNumber*= 10)
        {
            resultTable.push_back(Dafunc(elementCount, maxNumber));
        }

    }

    cout << "Done :";
    

    return 0;
 }





struct SortResult {
    uint64_t myAlgoTime;
    uint64_t stdAlgoTime;
    uint64_t elemCount;
    uint64_t highestNumber;
    int randSeed = 51;
    bool outputMatch;
};
vector<uint64_t> sortbyhisto(vector<uint64_t> &V1, SortResult& testCase) {

    vector<uint64_t> histo (testCase.highestNumber,0);
    for (uint64_t i = 0; i < testCase.elemCount; i++)
    {
        histo[V1[i]]++;
    }

    vector<uint64_t> V2;
    V2.reserve(testCase.elemCount);
    for (uint64_t  i = 0; i < histo.size(); i++)
    {
        while (histo[i] != 0) {
            V2.push_back(i);
            histo[i]--;
        }
    }

    return V2;
}
void print_me(vector<uint64_t> V1) {
    int ten = 0;
    for (uint64_t i = 0; i < V1.size(); i++)
    {
        cout << V1[i]<<" ";
        ten++;
        if (ten == 10) {
            cout << "             "<< endl;
            ten = 0;
        }
    }
}



SortResult Dafunc(uint64_t elemCount,uint64_t highestNumber)
{

    SortResult hello;
    hello.elemCount = elemCount;
    hello.highestNumber = highestNumber;

    vector<uint64_t> stuff;
    stuff = RandomGenerator(hello);
    vector<uint64_t> resul;

    uint64_t startTime;
    uint64_t endTime;

    //testing using histogram approach
    startTime = chrono::high_resolution_clock::now().time_since_epoch().count();
    resul = sortbyhisto(stuff, hello);
    endTime = chrono::high_resolution_clock::now().time_since_epoch().count();
    hello.myAlgoTime = endTime - startTime;
    //cout << "   Time taken  :" << hello.myAlgoTime << "ns or " << hello.myAlgoTime / 1000 << "us or " << hello.myAlgoTime / 1000000 << "ms" << endl;

    //testing using STD sort()
    startTime = chrono::high_resolution_clock::now().time_since_epoch().count();
    sort(stuff.begin(), stuff.end());
    endTime = chrono::high_resolution_clock::now().time_since_epoch().count();
    hello.stdAlgoTime = endTime - startTime;
    //cout << "   Time taken  :" << hello.stdAlgoTime << "ns or " << hello.stdAlgoTime / 1000 << "us or " << hello.stdAlgoTime / 1000000 << "ms" << endl;
    
    if(resul==stuff){
    //    cout << "The both sorted vectors are correct" << endl;
        hello.outputMatch = true;
    }
    else
    {
    //    cout << "The both sorted vectors did not match" << endl;
        hello.outputMatch = false;
    }

    cout << " Elemcount : " << hello.elemCount << "  : Highest Value : " 
        << hello.highestNumber << " :Time Taken by Histo Algo :" 
        << hello.myAlgoTime / 1000 << ": us : "<< "by STD Algo : "
        << hello.stdAlgoTime / 1000 << ": us : Final Check : " << hello.outputMatch
        << endl;



    


    return hello;
}

vector<uint64_t> RandomGenerator(SortResult sample){
    //this function will return a random generated array of sizes given in an SortResult sample
    srand(sample.randSeed);

    vector<uint64_t> arr;

    for (uint64_t i = 0; i < sample.elemCount; i++)
    {
        arr.push_back((uint64_t)(((float)rand() / RAND_MAX) * (sample.highestNumber- 1)));
    }
    return arr;
}


















