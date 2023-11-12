#include <iostream>
using namespace std;

int main() {
    bool prima = true;
    int n;
    cout << "input satu angka bilangan bulat: ";
    cin >> n;
    cout << endl;
    if(n < 2){
        prima = false;
    }else{
        for(int i = 2;i<=n; i++){
            if (n%i == 0 && i != n){
                prima = false;
            }
        }
    }if (prima == true){
        cout << n <<" angka prima";
    }else{
        cout << n <<" bukan angka prima";
    }
    return 0;
}