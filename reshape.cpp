#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Check if reshape is possible
    if (rows * cols != r * c)
        return mat;

    vector<vector<int>> result(r, vector<int>(c));

    for (int i = 0; i < rows * cols; i++) {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }

    return result;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };

    int r = 1, c = 4;

    vector<vector<int>> ans = matrixReshape(mat, r, c);

    cout << "Reshaped Matrix:\n";
    for (auto row : ans) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}