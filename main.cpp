#include<iostream>
using namespace std;

int main(){
    int imagePixels[3][3] = { {0, 50, 0}, {0, 255, 0}, {0, 50, 0} };
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << imagePixels[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}