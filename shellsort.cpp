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

    ifstream is;
    is.open("random.txt");

    const int size = 100000;
    vector <int> arr(size);
    generate(arr.begin(), arr.end(), rand);

    // int temp;
    // for(int i = 0; i < size; i++){
    //    is >> temp;
    //    arr.push_back(temp);
    // }

    //int n = sizeof(arr)/sizeof(arr[0]);

    auto start = chrono::high_resolution_clock::now();
    shellsort(arr);
    auto end = chrono::high_resolution_clock::now();
    print(arr);
    chrono::duration<double> duration = end - start;
    cout << endl <<"Time taken by shellsort: " << duration.count() << " seconds" << endl;
    
    is.close();
    return 0;
}