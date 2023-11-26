#include <iostream>
using namespace std;

class Shape
{
private:
    float area;
    float keliling;
public:

    virtual float calculateArea() { return 0; }
    virtual float calculateKeliling() { return 0; }
};

class Rectangle : public Shape{
    private:
        float p;
        float l;
    public:
        Rectangle(float p, float l){
            this->p = p;
            this->l = l;
        }
        float calculateArea(){
            float area = p*l;
            cout << "Luas = "<< area << endl;
            return area;
        }
        float calculateKeliling(){
            float keliling = 2*p + 2*l;
            cout << "Keliling = "<< keliling<<endl;
            return keliling;
        }
};

int main()
{
Rectangle rect (5.0, 4.0);
Shape* shape1 = &rect;
shape1-> calculateKeliling();
shape1-> calculateArea();
return 0;
}