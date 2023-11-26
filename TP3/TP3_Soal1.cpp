#include <iostream>
#include <cmath>

class LinearLine
{
private:
    float x1;
    float x2;
    float y1;
    float y2;

public:
    LinearLine(float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    float gradient() {
        float m = (y2-y1)/(x2-x1);
        return m;
    }
    float y_intercept() {
        float y0 = gradient()*-x1+y1;
        return y0;
    }
    void operator +(float a){//mohon maaf, perlu mengerjakan tugas prd 
        a ++;   
    }
    void printEquation(){
        if (y_intercept()<0){
            float n = y_intercept()*-1;
            char f = '-';
            cout<< "y = " << gradient() << "x" << f << y_intercept() <<endl;
        } else{
            char f = '+';
            cout<< "y = " << gradient() << "x " << f << " "<< y_intercept() <<endl;
        }
    }
    void printPoints(){
        cout << "(x1, y1) = (" << x1<< ", " << y1<< ")" << endl;
        cout << "(x2, y2) = (" << x2<< ", " << y2<< ")" << endl;
    }
};

int main(){
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f); 
    int a = 3; 

    line.printPoints();
    cout << "Sehingga didapatkan" <<endl;
    cout<< "gradien = " <<line.gradient() << endl;
    cout<< "y_intercept = "<<line.y_intercept() << endl;
    line.printEquation();  
    cout<< "setelah digeser sejauh " << a<< ", didapatkan persamaan baru"<< endl;
    a = line.gradient()*-a;
    if (line.y_intercept()<0){
            float n = line.y_intercept()*-1;
            char f = '-';
            cout<< "y = " << line.gradient() << "x" << f << " q" << line.y_intercept()+a <<endl;
        } else{
            char f = '+';
            cout<< "y = " << line.gradient() << "x " << f << " "<< line.y_intercept()+a <<endl;
        }

}

