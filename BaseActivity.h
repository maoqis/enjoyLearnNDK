//
// Created by maoqis on 2021/3/23.
//
#include <iostream>
#ifndef UNTITLED_BASEACTIVITY_H
#define UNTITLED_BASEACTIVITY_H
using namespace std;
class BaseActivity {
private:
    void setContentView(string layoutResId) {
        cout << "XmlResourceParser" << "反射" << endl;

    }

public:
//    virtual string getLayoutId(); //虚函数
    virtual string getLayoutId() = 0; //纯虚函数

//    virtual void initView();
    virtual void initView() = 0;

//    virtual void initData();
    virtual void initData() = 0;

//    virtual void initListener();
    virtual void initListener() = 0;

    void onCreate() {
        setContentView(getLayoutId());
    }
};


#endif //UNTITLED_BASEACTIVITY_H
