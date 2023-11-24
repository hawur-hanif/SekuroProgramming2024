#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

// Global variabel
int gerak_ke = 0;
int mtr = 1;
float posisi[1][2] = {{0,0}};

// print lokasi saat ini
void lokasi(){
    float x = (floor(posisi[gerak_ke][0]*100 + 0.5))/100;
    float y = (floor(posisi[gerak_ke][1]*100 + 0.5))/100;
    posisi[gerak_ke][0] = x;
    posisi[gerak_ke][1] = y;
    cout << "lokasi => (" << x << " , " << y <<")" << endl;
}

// bergerak sesuai horizontal dan vertikal
void gerak(float x,float y){
    if (gerak_ke < mtr-1){
        mtr = gerak_ke + 1;
    }
    gerak_ke += 1;
    mtr += 1;
    posisi[gerak_ke][0] = posisi[gerak_ke-1][0] + x;
    posisi[gerak_ke][1] = posisi[gerak_ke-1][1] + y;
    lokasi();
}

// bergerak sesuai dengan kecepatan, waktu, dan sudut(derajat)
void gerak_2(float v, float t, float theta){
    if (gerak_ke < mtr-1){
        mtr = gerak_ke + 1;
    }
    gerak_ke += 1;
    mtr += 1;
    posisi[gerak_ke][0] = posisi[gerak_ke-1][0] + v*t*cos(theta*M_PI/180);
    posisi[gerak_ke][1] = posisi[gerak_ke-1][1] + v*t*sin(theta*M_PI/180);
    lokasi();
}

// undo satu perintah kebelakang
void undo(){
    if (gerak_ke > 0){
        gerak_ke -= 1;
        cout << "Undo berhasil" << endl;
        lokasi();
    } else {
        cout << "Tidak dapat undo" << endl;
    }
}

//redo satu perintah kedepan
void redo(){
    if (gerak_ke < mtr-1){
        gerak_ke += 1;
        cout << "Redo berhasil" << endl;
        lokasi();
    } else {
        cout << "Tidak dapat redo" << endl;
    }
}

//save posisi sekarang pada txt
void save(){
    ofstream myfile("save.txt");
    myfile << posisi[gerak_ke][0] << " :Komponen-X" <<endl;
    myfile << posisi[gerak_ke][1] << " :Komponen-Y" <<endl;
    cout << "Save berhasil"<< endl;
    myfile.close();
}

//load posisi menjadi posisi awal dengan txt
void load(){
    string teks;
    int ind = 0;
    gerak_ke = 0;
    mtr = 1;
    ifstream myfile("save.txt");
    while (getline (myfile, teks)){
        posisi[gerak_ke][ind] = stof(teks);
        ind += 1;
    }
    myfile.close();
    cout << "Load berhasil" << endl;
    lokasi();
}

//print kode perintah yang disediakan
void bantuan(){
    cout << "ketik -0- untuk menghentikan program"<< endl;
    cout << "ketik -1- untuk bergerak dengan jarak"<< endl;
    cout << "ketik -2- untuk bergerak dengan kecepatan"<< endl;
    cout << "ketik -3- untuk undo"<< endl;
    cout << "ketik -4- untuk redo"<< endl;
    cout << "ketik -5- untuk save"<< endl;
    cout << "ketik -6- untuk load"<< endl;
    cout << "ketik -7- untuk bantuan"<< endl;
}

//kode utama
int main(){
    bool jalan = true;
    int input_user;
    float x; float y;float z;

    cout << "Selamat datang pada program simulasi drone" << endl;
    bantuan();
    lokasi();

    while (jalan){
        cout << "Masukkan input kode:" <<endl;
        cin >> input_user;
        switch (input_user){
        case 0:
            jalan = false;
            cout << "Program diberhentikan";
            exit(0);
            break;
        case 1:
            cout << "gerak 1" << endl;
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            gerak(x,y);
            break;
        case 2:
            cout << "gerak 2" << endl;
            cout << "v: ";
            cin >> x;
            cout << "t: ";
            cin >> y;
            cout << "theta: ";
            cin >> z;
            gerak_2(x, y, z);
            break;
        case 3:
            undo();
            break;
        case 4:
            redo();
            break;
        case 5:
            save();
            break;
        case 6:
            load();
            break;
        case 7:
            bantuan();
            break;
        default:
            cout << "Input anda salah!, silakan coba lagi" << endl;
            cout << "ketik -7- untuk bantuan"<< endl;
            break;
        }
    }
}
