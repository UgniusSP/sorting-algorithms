#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

void shellsort(vector <int>& arr){
    int n = arr.size();
    for(int i = n/2; i > 0; i /= 2){
        
        for(int j = i; j < n; j++){
            
            int temp = arr[j];

                int k;
                for(k = j; k >= i && arr[k-i] > temp; k -= i){
                    arr[k] = arr[k-i];
                    
                }
            arr[k] = temp;
            
        }
    } 
}

void print(vector <int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout <<  arr[i] << " ";
    }
}

int main(){

    int size;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    for(int i = 0; i < 5; i++){
        switch(i){
            case 0:
                size = 100000;
                break;
            case 1:
                size = 250000;
                break;
            case 2:
                size = 500000;
                break;
            case 3:
                size = 750000;
                break;
            case 4:
                size = 1000000;
                break;
        }

        for(int k = 0; k < 5; k++){
            
            vector <int> arr(size);
            generate(arr.begin(), arr.end(), rand); 
            vector <int> arrCopy = arr;

            for(int j = 0; j < 6; j++){
                arr = arrCopy;
                //cout << "Before sorting ";
                //print(arr);
                auto start = chrono::high_resolution_clock::now();
                shellsort(arr);
                auto end = chrono::high_resolution_clock::now();

                auto ms_int = duration_cast<milliseconds>(end - start);
                duration<double, std::milli> ms_double = end - start;

                cout << endl << j <<" Time taken by shellsort with size " << size <<": " << ms_double.count() << " miliseconds" << endl;
                //cout << "After sorting ";
                //print(arr);
                
            }
        }

        
    }

    
    return 0;
}