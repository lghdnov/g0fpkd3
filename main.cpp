#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream first_file("a1.txt"),
            second_file("a2.txt");

    float p_sum = 0, f = 0, s = 0;

    while (first_file >> f){
        if (f > 0) p_sum += f;
    }
    while (second_file >> s){
        if (s > 0) p_sum += s;
    }
    cout << p_sum << "\n";
    first_file.close();
    second_file.close();
}
