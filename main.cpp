#include <iostream>
#include <fstream>

using namespace std;

void print_file(string& filename) {
    ifstream file(filename);

    string line;
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("out.txt");

    char ch;
    while (input_file.get(ch))
        output_file.put(toupper(ch));

    input_file.close();
    output_file.close();

    string out_str = "out.txt";
    print_file(out_str);
}
