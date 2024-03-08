#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string HUMANS_FILE = "humans.txt";

struct Address{
    string index, country, region, district, city,
            street, house, apartment;
};

ostream& operator<<(ostream& os, const Address& addr) {
    return os
        << addr.index << " "
        << addr.country << " "
        << addr.city << " "
        << addr.region << " "
        << addr.district << " "
        << addr.street << " "
        << addr.house << " "
        << addr.apartment;
}
istream& operator>>(istream& is, Address& addr) {
    return is
            >> addr.index
            >> addr.country
            >> addr.city
            >> addr.region
            >> addr.district
            >> addr.street
            >> addr.house
            >> addr.apartment;
}

struct Date{
    unsigned int day, month, year;
};

ostream& operator<<(ostream& os, const Date& date) {
    return os
            << date.day << " "
            << date.month << " "
            << date.year;
}
istream& operator>>(istream& is, Date& date) {
    return is
            >> date.day
            >> date.month
            >> date.year;
}

struct Chuvak {
    string last_name, first_name, patronymic,
        gender, nationality, phone;
    float height, weight;
    Date birth;
    Address address;

};
ostream& operator<<(ostream& os, const Chuvak& chel) {
    return os
        << chel.last_name << " "
        << chel.first_name << " "
        << chel.patronymic << " "
        << chel.gender << " "
        << chel.nationality << " "
        << chel.phone << " "
        << chel.height << " "
        << chel.weight << " "
        << chel.birth << " "
        << chel.address;
}
istream& operator>>(istream& is, Chuvak& chel) {
    return is
            >> chel.last_name
            >> chel.first_name
            >> chel.patronymic
            >> chel.gender
            >> chel.nationality
            >> chel.phone
            >> chel.height
            >> chel.weight
            >> chel.birth
            >> chel.address;
}

void print_file(const string& filename) {
    ifstream file(filename);

    string line;
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

void create_random_humans(int c){
    ofstream file(HUMANS_FILE);

    for (int i = 0; i < c; ++i) {
        Date date{ (unsigned int)rand(), (unsigned int)rand(), (unsigned int)rand()};
        Address address{ "index", "country",
                         "region", "district",
                         "city","street",
                         "house", "apartment"};

        Chuvak chuvak{"last_name", "first_name",
                      "patronymic", "gender",
                      "nationality", "phone",
                      80, 70, date, address};

        file << chuvak << " ";
    }
    file.close();
}

void parse_humans(vector<Chuvak>& humans){
    ifstream file(HUMANS_FILE);
    Chuvak chel;
    while (file >> chel) humans.push_back(chel);
}

void get_youngest_chuvak(const vector<Chuvak>& humans, Chuvak& youngest) {
    if(humans.empty()) {
        return;
    }
    youngest = humans[0];
    for (const auto &chuvak : humans) {
        if (chuvak.birth.year > youngest.birth.year ||
            (chuvak.birth.year == youngest.birth.year && chuvak.birth.month > youngest.birth.month) ||
            (chuvak.birth.year == youngest.birth.year && chuvak.birth.month == youngest.birth.month &&
            chuvak.birth.day > youngest.birth.day))
        {
            youngest = chuvak;
        }
    }
}

int main() {
    create_random_humans(10);
    print_file(HUMANS_FILE);

    vector<Chuvak> chuvaki;
    parse_humans(chuvaki);

    Chuvak youngest;
    get_youngest_chuvak(chuvaki, youngest);
    cout << "\n\n\n" << youngest;
}
