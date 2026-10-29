#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>>convolve(const vector<vector<double>>& image, const vector<vector<double>>& kernel){
    //define stride
    int stride = 1;

    //dimension of output matrix
    int outputDimension = (image.size() - kernel.size()) / stride + stride;

    vector<vector<double>> output(outputDimension, vector<double>(outputDimension, 0));

    for(int i = 0; i < output.size(); i++){
        for (int j = 0; j < output.size(); j++){
            for(int k = 0; k < kernel.size(); k++){
                for(int l = 0; l < kernel.size(); l++){

                    int m = i * stride + k;
                    int n = j * stride + l;

                    output[i][j] += image[m][n] * kernel[k][l];
                }
            }
        }
    }

    cout << "------------Convolved------------" << endl;

    for(int i = 0; i < output.size(); i++){
        for (int j = 0; j < output.size(); j++){
            cout << output[i][j] << "\t";
        }
        cout << endl;
    }

    return {};
}

int main(){
    vector<vector<double>> image = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16} };
    vector<vector<double>> kernel = { { 1, 0 }, { 0, 1 }};

    cout << "-----------image-----------" << endl;
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << image[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "-----------kernel-----------" << endl;
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << kernel[i][j] << "\t";
        }
        cout << endl;
    }

    auto output = convolve(image, kernel);

    for(const auto& row : output){
        for (double value : row){
            cout << value << "\t";
        }
        cout << endl;
    }

    return 0;
}