//
// Created by maoqis on 2021/3/18.
//
#include <iostream>
#include "Student.h"

using namespace std;


Student::Student() {
    cout << "空" << endl;
}

Student::Student(char *name, int age) {
    this->name = name;
    this->age = age;
}

Student::Student(const Student &p) {
    cout << "拷贝函数p=" << &p << endl;
    cout << "拷贝函数ret=" << this << endl;

}

Student::~Student() {
    cout << "析构函数" << endl;
}


Student Student::operator+(const Student &student) {
    this->age = this->age + student.age;
}

ostream &operator<<(ostream &os, Student &student) {
    int i = student.getAge();
    os << student.Person::getName() << ":" << i;
    return os;
}

istream &operator>>(istream &is, Student &dt) {
    int i = dt.getAge();
    is >> dt.Person::getName() >> i;
    return is;
}

