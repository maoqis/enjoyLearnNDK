#include <iostream>
#include "Student.h"
#include "Person.h"
#include "Base1.h"
#include "BaseActivity.h"
#include "MainActivity.h"
#include "ILoginResponse.h"
#include "ComparedObject.h"
#include <map>
#include <set>//STL
#include <vector>//STL
#include <algorithm>//算法
#include "Ptr.h"
using namespace std;


class Desk {
public:
    Person *person;
    int age;
    char *name;

};


void test();

void test1(Person *p);

void test2(Person *&p);

void test3(Person &p);

void test4(Person p);


void test1();

void testOperation();

void testMulImplement();

void testVirtual();

void testMap();

void testMultimap();


void testMethodVar();

void testVector();

int main() {
    ;
//    test1();
//    test();

//    testOperation();
//    testMulImplement();

//    testVirtual();

//    testMap();
//    testMultimap();
//    testMethodVar();

//    testVector();


    Person * person1 = new Person();
    Person * person2 = new Person();
    Ptr<Person> share1(person1) ;
    Ptr<Person> share2(person2) ;


    share1 =share2;

    cout << "share1.use_count=" << share1.use_count() << endl;

    cout << "share2.use_count=" << share2.use_count() << endl;



}

void testVector() {
    cout << "1. set 存入对象崩溃，对象没法自动排序，所以崩溃 使用vector" << endl;
    cout << "2. vector c++ 使用拷贝构造函数存入" << "和java很不一样" << endl;
    vector<Student> vectorV;
    Student student("张三", 12);
    cout << "新建对象 student" << student.name << &student << endl;
    vectorV.insert(vectorV.begin(), student);
    cout << "student 赋值 里斯" << endl;
    student.name = "里斯";

    cout << "student" << student.name << &student << endl;

    Student *pStudent = &*vectorV.begin();
    pStudent->name = "3. student1 王武 不赋值 read memory from 0x2 failed (0 of 1 bytes read)";

    cout << "student1 迭代器中值 和拷贝构造函数返回值对应=" << pStudent << endl;
    cout << "student1 age=" << pStudent->age << endl;
    cout << "student1 name=" << pStudent->name << endl;
    cout << "4. vector 插入参数是引用，但是插入值是拷贝函数返回的值" << endl;
}

void testMethodVar() {//
    cout << "1. set:" << "set的遍历有排序根据key排序功能" << endl;
    set<int> setV;
    setV.insert(20);
    setV.insert(30);
    setV.insert(10);
    setV.insert(40);
    //
    cout << "2. 仿函数 : eg 变量名for_each 第三参数_Function 变量名 --f ，一元谓词:方法里面参数只有一个 " << endl;
    cout << "3. 类名->方法参数,仿函数:" << " for_each(setV.begin(), setV.end(), ComparedObject());" << endl;
    for_each(setV.begin(), setV.end(), ComparedObject());
    cout << "4. 方法名->方法参数:" << " for_each(setV.begin(), setV.end(), ComparedObject::showAction)" << endl;
    for_each(setV.begin(), setV.end(), ComparedObject::showAction);
    cout << "5. _Function 值传递" << "" << endl;
}


void testMultimap() {//
    cout << "1. key 可以重复\n2. key 重复数据可以分组" << "" << endl;
    multimap<int, string> mulMapV;
    mulMapV.insert(make_pair(1, "yi"));
    mulMapV.insert(make_pair(2, "er"));
    mulMapV.insert(make_pair(3, "san"));
    mulMapV.insert(make_pair(3, "san"));
    mulMapV.insert(make_pair(3, "san"));
    for (auto mapIterator = mulMapV.begin();
         mapIterator != mulMapV.end();
         ++mapIterator) {
        cout << mapIterator->first << "," << mapIterator->second << endl;
    }
    int result;
    cin >> result;
    cout << "result=" << result << endl;

    multimap<int, string>::iterator iterator = mulMapV.find(result);
    while (iterator != mulMapV.end()) {

        cout << iterator->first << "," << iterator->second << endl;
        if (iterator == mulMapV.end()) {
            break;
        }
        iterator++;
    }
}

void testMap() {
    cout << "1. mapV 会对key 进行排序" << endl;
    map<int, string> mapV;
    cout << "2. class 名可能小写map，和变量名冲突，" << "使用mapV" << endl;
    mapV.insert(pair<int, string>(1, "yi"));
    mapV.insert(make_pair(2, "er"));
    mapV.insert(map<int, string>::value_type(3, "san"));
    for (map<int, string>::iterator it = mapV.begin(); it != mapV.end(); it++) {
        cout << it->first << it->second << endl;
    }
    const map<int, string>::iterator &iterator = mapV.find(3);
    cout << "find 3 =" << iterator->second << endl;
}

void testVirtual() {
    Base1 base1;
    Object object;
    base1.info;
    cout << "c++ 默认关闭多态" << endl;
    cout << "虚函数 ，在父类上函数加上 virtual，动态多态，运行之后才知道用哪个。" << endl;
    cout << "重载，类有多个同名方法，静态多态，编译时候可以决定调用个方法。" << endl;
    cout << "纯虚函数=>抽象类,纯虚函数必须重写 virtual void initView() = 0；" << endl;
    MainActivity m;
    cout << "回调" << ":" << endl;
    cout << "接口不能被实例化，" << "c++没有接口，纯虚函数类不能实例化，= 没有匿名内部类" << endl;
    cout << "泛型不能继承" << endl;
    LoginResponseImpl loginResponse = LoginResponseImpl();
    loginAction("test", "NULL", loginResponse);
}


void testMulImplement() {
    cout << "多继承" << ":start" << endl;
    Student stu = Student("stu", 1); //调用拷贝构造函数
    Student stu1 = Student("stu1", 2); //调用拷贝构造函数;

    cout << "多继承" << "stu.Study::getName()" << stu.Study::getName() << endl;
    cout << "多继承" << "stu1.Person::getName()" << stu1.Person::getName() << endl;

    cout << "多继承" << "在类中定义新成员变量，感觉不好" << endl;
    cout << "多继承" << "virtual" << endl;


    cout << "多继承" << ":end" << endl;
}

void testOperation() {
    Student stu;
    Student stu1;
    cout << "operation" << ":<<" << endl;
    stu = Student("stu", 1); //调用拷贝构造函数
    stu1 = Student("stu1", 2); //调用拷贝构造函数
    cout << stu << stu1 << endl;
    cout << "operation" << ":end" << endl;
}

void test1() {//    std::cout << "Hello, World!" << std::endl;
    cout << "1. 结构体" << endl;

    Person person = {100, "张"};
    Person person1 = person;
    person1.age = 1;
    cout << "person =" << person.age << endl;
    cout << "person1 =" << person1.age << endl;

    cout << "2. 拷贝复制" << endl;


    char *name = "name";
    char t = '1';
    int a = 1;
    int *b = &a;

    int age = person.age;
    Student stu(name, age);

    Student stu1;
    cout << "3. 非拷贝复制" << endl;
    stu1 = stu;
    stu1.setAge(2);


    cout << "stu =" << stu.getAge() << endl;

    cout << "stu1 =" << stu1.getAge() << endl;
    //指针
    cout << "4. 指针" << endl;
    Student *stu2 = &stu;
    stu2->setAge(3);
    cout << "stu =" << stu.getAge() << endl;

    cout << "stu3 =" << stu2->getAge() << endl;
    cout << " 5. 常量指针 和指针常量 " << endl;

    // 常量指针 和指针常量
//    int t = 1;
//    int *const number = &t;
//    const int *number1 = &t;
//    *number = 2;
//    *number1 = 2;//Read-only variable is not assignable

}

void test() {
    Person *p1 = new Person();
    Person *p2 = new Person();
    Person p3 = Person();
    Person p4 = Person();
    p1->age = 1;
    p2->age = 1;

    test1(p1);
    cout << "p1->x = " << p1->age << "; p2->x = " << p2->age << endl;


    test2(p2);
    cout << "p1->x = " << p1->age << "; p2->x = " << p2->age << endl;

    cout << "p1->x = " << p1->age << "; p2->x = " << p2->age << endl;
    test3(p3);
    cout << "p3->x = " << p3.age << endl;
    test4(p4);

    cout << "p4->x = " << p4.age << endl;
}


/*指针*/
void test1(Person *p) {
    cout << "指针传递  " << p << endl;
    p = new Person();
    p->age = 100;
}

/*指针引用*/
void test2(Person *&p) {
    cout << "指针引用传递/对象引用的地址" << p << endl;
    p = new Person();
    p->age = 102;


}

void test3(Person &p) {
    cout << "引用值" << &p << endl;
    p.age = 103;
}

void test4(Person p) {
    cout << "值传递" << &p << endl;
    p.age = 104;


}



