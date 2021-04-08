//
// Created by maoqis on 2021/3/18.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <iostream>
#include "Person.h"
#include "Study.h"

using namespace std;

class Student : public Person, public Study {
public:
    Student();

    Student(char *name, int age);

    Student(const Student &p);

    virtual ~Student();


    Student operator+(const Student &);

    friend ostream &operator<<(ostream &os, Student &student);

    friend istream &operator>>(istream &is, Student &);


};


#endif //UNTITLED_STUDENT_H
