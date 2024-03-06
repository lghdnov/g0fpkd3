#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("a.txt");
    int p_counter = 0, n_counter = 0, n;
    while (file >> n){
        if (n > 0) p_counter++;
        if (n < 0) n_counter++;
    }
    printf("positive: %i, negative: %i", p_counter, n_counter);
    file.close();
}
