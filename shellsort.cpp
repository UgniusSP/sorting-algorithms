#include <iostream>
#include <array>
#include <fstream>
#include <ctime>
using namespace std;

void shellsort(int arr[], int n){
    for(int i = n/2; i > 0; i /= 2){
        //cout << endl;
        //cout << arr[i] << endl;
        for(int j = i; j < n; j++){
            //cout << "j " << j << endl;
            int temp = arr[j];

                int k;
                for(k = j; k >= i && arr[k-i] > temp; k -= i){
                    arr[k] = arr[k-i];
                    //cout << "k " << k << endl;
                }
            arr[k] = temp;
            
        }
    }
    
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout <<  arr[i] << " ";
    }
}

int main(){
    int temp;
    
    ifstream is;
    is.open("random.txt");
    
    int arr[10000];

    int i;
    for(int i=0;i<10000;i++){
        is >> arr[i];
    }

    int n = sizeof(arr)/sizeof(arr[0]);

    clock_t start = (int)clock();
    shellsort(arr, n);
    print(arr, n);
    printf("%0.5fs", (float)(clock() - start) / CLOCKS_PER_SEC);
    
    is.close();
    return 0;
}