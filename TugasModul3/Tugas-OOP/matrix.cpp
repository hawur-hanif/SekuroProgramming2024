using namespace std;
#include <iostream>
#include <vector>

class Matrix{
    private:
        int row, col;
        float** start_mtr;
    public: 
        Matrix(vector<vector<float>>& content){
            row = content.size();
            col = content[0].size();

            float** mtr =new float* [row];
            for (int i=0; i<row; i++){
                mtr[i] = new float[col];
            }

            for (int i=0; i<row; i++){
                for (int j=0; j<col; j++){
                    mtr[i][j] = content[i][j];
                }
            }

            start_mtr = mtr;            
        };

        Matrix(int i_row, int i_col){
            row = i_row;
            col = i_col;
            // deklarasi 2d array
            float** mtr =new float* [row];
            for (int i=0; i<row; i++){
                mtr[i] = new float[col];
            }
            // input 0 setelah deklarasi
            for (int i=0; i<row; i++){
                for (int j=0; j<col; j++){
                    mtr[i][j] = 0;
                }
            }
            // menyimpan pointer awal matriks ke public
            start_mtr = mtr;
        };

        Matrix copy(){
            Matrix res(row, col);
                for (int i=0; i<row; i++){
                    for (int j=0; j<col; j++){
                        res.start_mtr[i][j] = start_mtr[i][j];
                    }
                }
            return res;
        }

        Matrix operator+(Matrix const& obj){
            if (row == obj.row && col == obj.col){
                Matrix res(row, col);
                for (int i=0; i<row; i++){
                    for (int j=0; j<col; j++){
                        res.start_mtr[i][j] = start_mtr[i][j] + obj.start_mtr[i][j];
                    }
                }
                return res;
            } else{
                Matrix res(1, 1);
                cout << "The matrix dimension is not valid!" << '\n';
                return res;
            }
        }

        Matrix operator-(Matrix const& obj){
            if (row == obj.row && col == obj.col){
                Matrix res(row, col);
                for (int i=0; i<row; i++){
                    for (int j=0; j<col; j++){
                        res.start_mtr[i][j] = start_mtr[i][j] - obj.start_mtr[i][j];
                    }
                }
                return res;
            } else{
                Matrix res(1, 1);
                cout << "The matrix dimension is not valid!" << '\n';
                return res;
            }
        }

        Matrix operator*(Matrix const& obj){
            if (col == obj.row){
                Matrix res(row, obj.col);
                float sum = 0;
                for (int i=0; i<row; i++){
                    for (int j=0; j<obj.col; j++){
                        sum = 0;
                        for(int k=0; k<col; k++){
                            sum += start_mtr[i][k] * obj.start_mtr[k][j];
                        }
                        res.start_mtr[i][j] = sum;
                    }
                }
                return res;
            } else{
                Matrix res(1, 1);
                cout << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second." << '\n';
                return res;
            }
        }

        void Display(){
            for (int i=0; i<row; i++){
                for (int j=0; j<col; j++){
                    cout << start_mtr[i][j] << ' ';
                }
                cout <<'\n';
            }
            cout <<'\n';
        }
};


int main(){
    vector<vector<float>> x = {{1, 2, 3}, {2, 3, 1}};
    Matrix A = x;
    x = {{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}};
    Matrix B = x;
    Matrix C(2, 3);

    cout << "Matrix A\n";
    A.Display();
    cout << "Matrix B\n";
    B.Display();
    cout << "Matrix C\n";
    C.Display();
    cout << "\n";

    Matrix C1 = A + C;
    cout << "Matrix C1\n";
    C1.Display();
    cout << "\n";

    Matrix C2 = A - C;
    cout << "Matrix C2\n";
    C2.Display();
    cout << "\n";

    Matrix C3 = A * B;
    cout << "Matrix C3\n";
    C3.Display();
    cout << "\n";

    Matrix C4 = B * A;
    cout << "Matrix C4\n";
    C4.Display();
    cout << "\n";
return 0;
}