#include <iostream>
using namespace std;

int main() {
    int n;
    float x;
    float total = 0;
    cout << "jumlah bilangan: ";
    cin >> n;
    for (int i=0; i<n; i++){
        cout << "bilangan " << i <<": ";
        cin >> x;
        cout << endl;
        total += x;
    }
    total /= n;
    cout <<"RATA-RATA: "<< total;
    return 0;
}