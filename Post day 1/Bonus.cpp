#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "masukkan n: ";
    cin >> n;
    cout << endl;
    int tinggi = floor(n/2)+1;
    int num = 0;
    for (int i=0; i<tinggi; i++){
        for (int j=0; j<i; j++){
            cout << ' ';
        }
        for (int k=tinggi; k>i; k--){
            if (num == 10){
                num = 0;
            }
            cout << num;
            num += 1;
        }
        cout << endl;
    }
    tinggi = n-floor(n/2)-1;
    for (int i=0; i<tinggi; i++){
        for (int j=0; j<floor(n/2); j++){
            cout << ' ';
        }
        for (int k=0; k<i+2; k++){
            if (num == 10){
                num = 0;
            }
            cout << num;
            num += 1;
        }
        cout << endl;
    }
    return 0;
}