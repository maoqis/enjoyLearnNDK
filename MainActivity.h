//
// Created by maoqis on 2021/3/23.
//

#ifndef UNTITLED_MAINACTIVITY_H
#define UNTITLED_MAINACTIVITY_H


#include "BaseActivity.h"

class MainActivity: public BaseActivity{
public:
    string getLayoutId() override;

    void initView() override;

    void initData() override;

    void initListener() override;
};


#endif //UNTITLED_MAINACTIVITY_H
