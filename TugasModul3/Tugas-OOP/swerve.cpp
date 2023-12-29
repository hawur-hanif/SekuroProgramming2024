using namespace std;
#include <cmath>
#include <iostream>

class Swerve{
    private:
        float rx, ry;
        float constant[8][3] = {{1, 0, -0.26363}, {0, 1, 0.26363},{1, 0, -0.26363}, {0, 1, 0.26363},{1, 0, -0.26363}, {0, 1, 0.26363},{1, 0, -0.26363}, {0, 1, 0.26363}};
        float content[631][8];
        float commandInput[3];
        int current_memory = 0;
        float resultant[631][4];
        float pose[631][3];
    public:
        void velocityCommand(float vx, float vy, float omega){
            commandInput[0] = vx;
            commandInput[1] = vy;
            commandInput[2] = omega;
            for(int i=0; i<8; i++){
                content[current_memory][i] = 0;
                for(int j=0; j<3; j++){
                    content[current_memory][i] += constant[i][j] * commandInput[j];
                }
            }
            // memasukkan vx, vy, dan omega ke pose
            for(int i=0; i<3; i++){
                pose[current_memory][i] = commandInput[i];
            }
            velocityResultant();
            current_memory += 1;
        }

        void velocityResultant(){
            for(int i=0; i<7; i+= 2){
                resultant[current_memory][i/2] = sqrt(pow(content[current_memory][i], 2) + pow(content[current_memory][i+1], 2));
            }
        }

        void updatePose(float deltaTime){
            pose[0][0] = 0;
            pose[0][1] = 5;
            pose[0][2] = 0;
            for(int i=1; i<631; i++){
                pose[i][0] = pose[i-1][0] + pose[i][0]*deltaTime;
                pose[i][1] = pose[i-1][1] + pose[i][1]*deltaTime;
                pose[i][2] = pose[i-1][2] + pose[i][2]*deltaTime;
            }

        }

        void Display(int n){
            cout << "resultant v" << n << ':' << '\n' << '{';
            for (int i=0; i<630; i++){
                cout << resultant[i][n-1] << ", ";
            }
            cout << resultant[630][n-1] << '}';
        }

        void DisplayPose(int n){
            string code;
            switch (n)
            {
            case 1:
                code = "x";
                break;
            case 2:
                code = "y";
                break;
            case 3:
                code = "omega";
                break;
            default:
                code : "pose";
                break;
            }
            cout << code << ':' << '\n' << '{';
            for (int i=0; i<630; i++){
                cout << pose[i][n-1] << ", ";
            }
            cout << pose[630][n-1] << '}';
        }
};

int main(){
    Swerve simulasi;
    for(float i=0; i<631; i += 1){
        float t = i/100;
        simulasi.velocityCommand(48*cos(t)*sin(t)*sin(t), 4*sin(4*t)+6*sin(3*t)+10*sin(2*t)-13*sin(t), 0);
    }
    simulasi.updatePose(0.01);
    simulasi.DisplayPose(3);
return 0;
}