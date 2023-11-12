#include <iostream>
using namespace std;

int main() {
    int tahun;
    cout << "masukkan tahun: ";
    cin >> tahun;
    cout << endl;
    if(tahun%400 != 0){
        if(tahun%100 == 0){
            cout << "bukan kabisat";
        }else{
            if(tahun%4 != 0){
            cout << "bukan kabisat";
        }else{
            cout <<"kabisat";
        }
        }
    }else{
        cout << "kabisat";
    }
    return 0;
}