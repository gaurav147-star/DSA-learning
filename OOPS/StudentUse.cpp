#include <bits/stdc++.h>
using namespace std;

class StudentUse
{
private:
    int age;

public:
    char *name;
    StudentUse(int age, char *name)
    {
        this->age = age;
        //shallow copy
        //this->name=name;

        //Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    //Copy constructor
    StudentUse(StudentUse const &s)
    {
        this->age = s.age;
        //this->name =s.name;     //Shallo Copy

        //Deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << "  " << age << endl;
    }
};

int main()
{
    char name[] = "abcd";
    StudentUse s1(20, name);
    s1.display();

    StudentUse s2(s1);
    s2.name[0] = 'x';
    s1.display();
    s2.display();
    // name[3] = 'e';
    // StudentUse s2(24, name);
    // s2.display();
    // s1.display();
}
