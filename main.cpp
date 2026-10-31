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

    return output;
}

vector<vector<double>>relu(const vector<vector<double>>& convolved){
    vector<vector<double>> output(convolved.size(), vector<double>(convolved.size(), 0));
    for(int i = 0; i < convolved.size(); i++){
        for (int j = 0; j < convolved.size(); j++){
            if(convolved[i][j] >= 0){
                output[i][j] = convolved[i][j];
            } else {
                output[i][j] = 0;
            }
        }
    }
    return output;
}

vector<vector<double>>pool(const vector<vector<double>>& relued){
    //define poolSize and stride
    int poolSize = 2;
    int stride = 1;
    vector<vector<double>> output((relued.size() - poolSize) / stride + 1, vector<double>((relued.size() - poolSize) / stride + 1, 0));

    for(int i = 0; i <= relued.size() - poolSize; i += stride){
        for(int j = 0; j <= relued.size() - poolSize; j += stride){
            double MAX_VAL = 0.0;
            for(int m = 0; m < poolSize; ++m){
                for(int n = 0; n < poolSize; ++n){
                    MAX_VAL = max(MAX_VAL, relued[i + m][j + n]);
                }
            }
            output[i / stride][j / stride] = MAX_VAL;
        }
    }

    return output;
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

    cout << "--------convolve---------" << endl;
    auto convolved = convolve(image, kernel);
    for(const auto& row : convolved){
        for (double value : row){
            cout << value << "\t";
        }
        cout << endl;
    }

    cout << "--------relu---------" << endl;
    auto relued = relu(convolved);
    for(const auto& row : relued){
        for (double value : row){
            cout << value << "\t";
        }
        cout << endl;
    }

    cout << "--------pool---------" << endl;
    auto pooled = pool(relued);
    for(const auto& row : pooled){
        for (double value : row){
            cout << value << "\t";
        }
        cout << endl;
    }

    return 0;
}