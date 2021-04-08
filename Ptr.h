//
// Created by maoqis on 2021/4/8.
//

#ifndef UNTITLED_PTR_H
#define UNTITLED_PTR_H


template<typename T>

class Ptr {
    T *object;
    int *count;

public:


    Ptr() {
        count = new int(1);
    }

    Ptr(T *t) : object(t) {
        count = new int(1);
    }

    virtual ~Ptr() {
        int i = --(*count);
        if (i == 0) {
            if (object) {
                delete object;
            }
            delete count;
            object = 0;
            count = 0;
        }

    }

    Ptr(const Ptr<T> &p) {
        ++(*p.count);
        object = p.object;
        count = p.count;


    }

    Ptr<T> operator=(const Ptr<T> &);

    int use_count();

};

template<typename T>
int Ptr<T>::use_count() {
    return *count;
}

template<typename T>
Ptr<T> Ptr<T>::operator=(const Ptr<T> &p) {
    ++(*p.count);

    cout << "被赋值的对象：" << "--并试图释放" << endl;
    if (--(*count) == 0) {
        if (object) {
            delete object;
        }
        delete count;
    }

    object = p.object;
    count = p.count;
    return *this;


}


#endif //UNTITLED_PTR_H
