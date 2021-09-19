#include <iostream>
using namespace std;

class Student
{
    static int totalStudents;

public:
    int rollNumber;
    int age;

    //static int totalStudents; //total number of students present

    Student()
    {
        totalStudents++;
    }
    int getRollNumber()
    {
        return rollNumber;
    }
    static int getTotalStudent()
    {
        return totalStudents;
    }
};

int Student ::totalStudents = 0;

int main()
{
    Student s1;
    Student s2;
    Student s3;
    Student s4;
    Student s5;
    Student s6;
    cout << Student ::getTotalStudent()<< endl;
}
