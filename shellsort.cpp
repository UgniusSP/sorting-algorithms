#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <numeric>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void shellsort(vector <int>& arr) {
    int n = arr.size();
    for (int i = n / 2; i > 0; i /= 2) {

        for (int j = i; j < n; j++) {

            int temp = arr[j];

            int k;
            for (k = j; k >= i && arr[k - i] > temp; k -= i) {
                arr[k] = arr[k - i];

            }
            arr[k] = temp;

        }
    }
}

void print(vector <int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int size = 100000;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;


    /*for (int i = 0; i < 5; i++) {
        switch (i) {
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
        }*/
    ofstream os;
     string base(".txt");
        vector <int> temp;
        for (int k = 0; k < 5; k++) {
            os.open(to_string(k + 1) + base);
            temp.clear();

            vector <int> arr(size);
            generate(arr.begin(), arr.end(), rand);
            for (const auto& e : arr) {
                os << e << " ";
            }
            os.close();
            vector <int> arrCopy = arr;

            for (int j = 0; j < 6; j++) {
                arr = arrCopy;
                //cout << "Before sorting ";
                //print(arr);
                auto start = chrono::high_resolution_clock::now();
                shellsort(arr);
                auto end = chrono::high_resolution_clock::now();

                auto ms_int = duration_cast<milliseconds>(end - start);
                duration<double, std::milli> ms_double = end - start;
                temp.push_back(ms_double.count());

                cout << endl << j+1 << " Time taken by shellsort with size " << size << ": " << ms_double.count() << " miliseconds" << endl;
               
                //cout << "After sorting ";
                //print(arr);

            }
            cout << "VIDURKIS: " << accumulate(temp.begin(), temp.end(), 0.0) / temp.size() << endl;
        }


    //}


    return 0;
}
