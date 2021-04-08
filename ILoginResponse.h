//
// Created by maoqis on 2021/3/23.
//

#ifndef UNTITLED_ILOGINRESPONSE_H
#define UNTITLED_ILOGINRESPONSE_H

#include <iostream>

using namespace std;

class ILoginResponse {
public:
    virtual void loginSuccess(int code, string msg) = 0;

    virtual void loginFail(int code, string msg) = 0;
};

//
class LoginResponseImpl : public ILoginResponse {
public:
    LoginResponseImpl();

public:
    void loginSuccess(int code, string msg) override;

    void loginFail(int code, string msg) override;
};


void loginAction(string name, string pwd, ILoginResponse &callback);

#endif //UNTITLED_ILOGINRESPONSE_H
