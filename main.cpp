#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define range(a, b) % (b - a + 1) + a

const string OUTPUT_FILE = "out.dat";

struct Student{
    string last_name;
    string group;
    vector<int> points;
    int scholarship;
};

ostream& operator<<(ostream& os, const Student& student) {
    os
        << student.last_name << " "
        << student.group << " ";
    for (const auto &item: student.points)
        os << item << " ";

    return os << student.scholarship;
}

std::istream& operator>>(std::istream& is, Student& student) {
    is >> student.last_name >> student.group;
    int points[3];
    is >> points[0] >> points[1] >> points[2] >> student.scholarship;

    student.points.insert(student.points.begin(), points, points + 3);

    return is;
}

vector<Student> create_random_students(int n){
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        Student student{
            "last_name",
            "group",
            {rand() range(1, 100),
             rand() range(1, 100),
             rand() range(1, 100)},
            0
        };
        students.push_back(student);
    }
    return students;
}

int main() {
    ofstream file(OUTPUT_FILE, ios::binary);

    vector<Student> students = create_random_students(5);
    for (const auto &item: students)
        file.write((char*)&item, sizeof item);
    file.close();

    for (const auto &item: students)
        if (item.points[0] > 50 && item.points[1] > 50 && item.points[2] > 50)
            cout << item;
}
