#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

#define MIL1     1000000
#define MIL10   10000000
#define MIL100 100000000
#define Maxnumber 1000000
const int iterations = 20;

vector<uint64_t> randGen(uint64_t max_number){

    vector<uint64_t> temp;
    temp.reserve(MIL1);
    srand(51);
    for (uint64_t i = 0; i < MIL1; i++)
    {
        temp.push_back((((float)rand()/RAND_MAX)*(max_number-1)));
    }
    
    return  temp;
    
}

void MakeHisto(vector<uint64_t> &passed,vector<uint64_t> &_histo,int no_of_elements){
    for (uint64_t i = 0; i < no_of_elements; i++)
    {
        _histo[passed[i]]++;
    }
    return;
}
void Check_Histo_Count(vector<uint64_t> histo){
    uint64_t count = 0;
    for (uint64_t i = 0; i < histo.size(); i++)
    {
        count += histo[i];
    }
    cout<<"Total Count of the elements in the histogram are :"<<count<<endl;
    
}

void printur(vector<vector<uint64_t>> _time_cout){
    for (int i = 0; i < iterations; i++)
    {
        cout<<"Done:  "<<i<<endl;
        cout<<"Time taken to generate a histogram of  1 million   :"<<_time_cout[0][i]<<"ns"<<endl;
        cout<<"Time taken to generate a histogram of  10 million  :"<<_time_cout[1][i]<<"ns"<<endl;
        cout<<"Time taken to generate a histogram of  100 million :"<<_time_cout[2][i]<<"ns"<<endl;  
        cout<<endl<<endl<<endl<<endl;
    }
    
        
}
int main(){
    vector<uint64_t> vector_1;
    vector<uint64_t> vector_2;
    vector<uint64_t> vector_3;
    vector<uint64_t> histo_1mil(MIL1,0);
    vector<uint64_t> histo_10mil(MIL10,0);
    vector<uint64_t> histo_100mil(MIL100,0);
    vector<uint64_t> avgtime(3,0);
    vector<vector<uint64_t>> time_cout;
    for (int i = 0; i < 3; i++)
    {
        time_cout.push_back(vector_1);
    }
    
    

    uint64_t StartTime = 0;
    uint64_t EndTime = 0;

    vector_1.reserve(MIL1);
    vector_2.reserve(MIL1);
    vector_3.reserve(MIL1);

    vector_1 = randGen(MIL1);
    vector_2= randGen(MIL1);
    vector_3= randGen(MIL1);

    cout<<(vector_1.size() == MIL1);
    cout<<(vector_2.size() == MIL1);
    cout<<(vector_3.size() == MIL1)<<endl<<endl<<endl;
    int counter = 0;
    



    for(int i = 0; i < iterations ; i++)
    {   
        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
       // cout<<"Time taken to cross 2 lines:"<<EndTime-StartTime<<"ns"<<endl;
        //cout<<"Done : "<<++counter<<endl;
        



        
        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        MakeHisto(vector_1,histo_1mil,MIL1);
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        //Check_Histo_Count(histo_1mil);
        time_cout[0].push_back(EndTime-StartTime);



        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        MakeHisto(vector_2,histo_10mil,MIL1);
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        //Check_Histo_Count(histo_10mil);
        time_cout[1].push_back(EndTime-StartTime);
        
        StartTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        MakeHisto(vector_3,histo_100mil,MIL1);
        EndTime = chrono::high_resolution_clock::now().time_since_epoch().count();
        //Check_Histo_Count(histo_100mil);
        time_cout[2].push_back(EndTime-StartTime);



        


    }

    for (int i = 0; i < 3; i++)
    {
        
        for (int j = 0; j < iterations; j++)
        {
            avgtime[i] += time_cout[i][j];
        }
        
        avgtime[i] = avgtime[i]/iterations;
        
        
        
    }

    cout<<"Time taken for       :      1MIL       :  :      10MIL      : :      100MIL     :"<<endl;
    for (int i = 0; i < iterations; i++)
    {
        cout<<"                         "<<time_cout[0][i]<<"ns             "<< time_cout[1][i]<<"ns             "<< time_cout[2][i]<<endl;
    }
    cout<<"avg time taken       :   "<<avgtime[0]<<"ns             "<<avgtime[1]<<"ns             "<<avgtime[2]<<"ns      "<<endl; 
       
    
}
