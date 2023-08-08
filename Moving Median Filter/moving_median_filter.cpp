#include <iostream>
#include <concepts>
#include <ranges>
#include <random>
using namespace std;

template<typename T>
concept _isFloatingT = requires(T a)
{
    requires std::is_floating_point<T>::value;
};

template<typename T>
void pretty_print(T &a,std::string && verbose);



template<typename T>
vector<T> Sort(std::vector<T>  arr)
{
    int n = arr.size();
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        swap(arr[min_idx], arr[i]);
    }
    return arr;
}



template<typename T,size_t size=100, size_t filterSize =15>
requires _isFloatingT<T>
void _moving_median_filter(std::vector<T> & vec, std::array<T,size> & arr)
{
    if(!filterSize%2){
        std:: cout<<"Filter size is not odd";
        return ;
    }    

    for(int i = filterSize/2-1; i < arr.size()-(filterSize/2);i++){
        std:: vector<float> window;
        // cout<<endl;

        for(int j = 0 ;j<filterSize;j++){//making my window/ storing the element in my window
            int filter_index = i-filterSize/2+1+j;
            // cout<<filter_index<<" ";
            window.push_back(arr[filter_index]);
        }
        for(int j = 0; j < filterSize ; j++){
            float temp_array[filterSize];

        }
        // cout<<endl;
        for(int i = 0;i<filterSize;i++){
            // cout<<" "<<window[i];
        }
        // cout<<endl;

        window = Sort<float>(window);//sorting the stuff window vector

        for(int i = 0;i<filterSize;i++){
            // cout<<" "<<window[i];
        }
        // cout<<endl;
    
        vec.push_back(window[filterSize/2]);
        // cout<<window[filterSize/2];
        // cout<<endl;


    }
    cout<<endl<<endl;
}



int main()
{
    std::random_device rd;
    std::mt19937 twister(rd());
    std::uniform_real_distribution<float> dis(-0.5,0.5);
    std::array<float,100> samples;
    for(auto& _a : samples)
        _a = dis(twister);
    pretty_print(samples,"Input Samples");

    std::vector<float> _vec;
    _vec.reserve(100);

    _moving_median_filter(_vec,samples);
    pretty_print(_vec,"Output Samples");
}

template<typename T>
void pretty_print(T &a,std::string && b)
{
    std::cout<<b<<std::endl;
    int i=0;
    for(auto & elem : a)
    {
        // if(i%10==0)
        //     std::cout<<std::endl;

        std::cout<<elem<<" "<<std::endl;
        i++;
    }
    std::cout<<std::endl;
}