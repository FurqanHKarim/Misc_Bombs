#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class meraDATA {
private:
    vector<int>  data;
    string intern;

public:
    int magic(string input) {

        stringstream ss;
        ss.str(input);
        int spaces=0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                spaces++;
            }
        }
        //https://en.cppreference.com/w/cpp/string/basic_string/getline
        for (int i = 0; i <= spaces; i++) {
            ss >> intern;
            if (intern == "pop") {
                if(!data.empty())
                this->data.erase(data.begin() + data.size()-1);
            }
            else if (intern == "push")
            {
                ss >> intern;
                if (intern == "push") {// if there is nothing in th front of pop
                    cout << -1;
                    return 0;
                }
                this->data.push_back(stoi(intern));
                i++;

            }
            else if (intern == "dup") {
                if (data.size()==0) {
                    cout << -98;
                    return 0;
                }
                this->data.push_back(data[data.size()-1]);
            }
            else {
                this->data.push_back(stoi(intern));
            }

            if (data.size()==0) {
                cout << -1;
                return 0;
            }
                

        }
        return 0;
    }

    void output() {
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i] << endl;
        }
    }
};


int main() {
    char hello[80000];
    meraDATA something;
    cin.getline(hello, 80000);
    string testing;
    testing = hello;

    something.magic(testing);

    
    something.output();

    return 0;
}