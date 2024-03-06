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
    ofstream f_output_file("out1.txt"),
            s_output_file("out2.txt");

    char ch;
    bool to_f_out = false;
    while (input_file.get(ch)){
        if (to_f_out) f_output_file.put(ch);
        else s_output_file.put(ch);
        to_f_out = !to_f_out;
    }

    input_file.close();
    f_output_file.close();
    s_output_file.close();

    string out1_str = "out1.txt";
    string out2_str = "out2.txt";
    print_file(out1_str);
    print_file(out2_str);
}
