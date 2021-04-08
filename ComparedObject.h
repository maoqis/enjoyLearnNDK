//
// Created by maoqis on 2021/3/30.
//

#ifndef UNTITLED_COMPAREDOBJECT_H
#define UNTITLED_COMPAREDOBJECT_H
#include "iostream"
using namespace std;

class ComparedObject {

public:
    void operator()(int content) {
        cout << "自定义仿函数，class '作为方法参数':" << content << endl;
    }
    static void showAction(int content);
};




#endif //UNTITLED_COMPAREDOBJECT_H
