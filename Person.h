//
// Created by maoqis on 2021/3/18.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H


class Person  {
public:
    int getAge() const;

    void setAge(int age);

    char *getName() const;

    void setName(char *name);

public:
    int age;
    char *name;
};


#endif //UNTITLED_PERSON_H
