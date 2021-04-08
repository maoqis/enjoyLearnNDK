//
// Created by maoqis on 2021/3/23.
//

#include "ILoginResponse.h"

void LoginResponseImpl::loginSuccess(int code, string msg) {
    cout << "loginSuccess" << code << endl;
}

void LoginResponseImpl::loginFail(int code, string msg) {
    cout << "loginFail" << code << endl;
}

LoginResponseImpl::LoginResponseImpl() {}

void loginAction(string name, string pwd, ILoginResponse &callback) {
    if (name.empty() || pwd.empty()) {
        callback.loginFail(500, "参数错误");
        return;
    }
    callback.loginSuccess(200, "test");
    return;
}