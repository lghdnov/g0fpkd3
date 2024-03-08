#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "out.txt";

#define matrix(T) vector<vector<T>>

void print_file(const string& filename) {
    ifstream file(filename);

    string line;
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

int main() {

    ifstream input_file(INPUT_FILE);
    ofstream output_file(OUTPUT_FILE);

    int m = 3, n = 3;

    vector<matrix(int)> matrices;

    while (!input_file.eof()){
        matrix(int) matrix;
        for (int i = 0; i < m; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                int element;
                input_file >> element;
                row.push_back(element);
            }
            matrix.push_back(row);
        }
        matrices.push_back(matrix);
    }

    for (const auto &matrix: matrices){
        if (matrix[0][0] != 0) continue;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                output_file << matrix[i][j] << " ";
    }

    input_file.close();
    output_file.close();
    print_file(INPUT_FILE);
    print_file(OUTPUT_FILE);
}
