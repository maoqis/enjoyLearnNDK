//
// Created by maoqis on 2021/3/18.
//

#include "Person.h"

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}

char *Person::getName() const {
    return name;
}

void Person::setName(char *name) {
    Person::name = name;
}

