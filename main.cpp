#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "out.txt";

void print_file(const string& filename) {
    ifstream file(filename);

    string line;
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

int main() {
    ifstream file(INPUT_FILE);
    ofstream result_file(OUTPUT_FILE);

    int a, sum = 1;
    while (file >> a) sum *= a;

    result_file << sum;

    file.close();
    result_file.close();

    print_file(INPUT_FILE);
    print_file(OUTPUT_FILE);
}
