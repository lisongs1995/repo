/***************************************************************************
 * 
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file String.cpp
 * @date 2018/09/02 16:29:23
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

char* MyString::operator=(const char* s){

    if(str) delete[] str;
    if(s){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
        str = nullptr;
    return str;
}

MyString::~MyString(){

    if(str) delete[] str;
}

MyString& MyString::operator=(const MyString& s){
    // MyString s1, s2;
    // s1 = "test 1";
    // s2 = "test 2";
    // s2 = s1; //浅拷贝，需要对类=运算符进行重载。
    // 防止s1 s2同时指向一片内存的时候，若析构其中一个对象，另一个对象所指向的内存就会不合法。
    if(str == s.str) return *this;
    if(str)
        delete[] str;
    if(s.str) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    else
        str = nullptr;
    return *this;
}

int main(int argc, char** argv){

    MyString s;
    s = "Good luck !"; // 调用第一个=重载函数
    //MyString s2 = "test"; //未指定类型转换构造函数，因此这样写会报错。
    cout << s.c_str() << endl;
    s = "test 2";
    cout << s.c_str() << endl;
    
    MyString s1, s2;
    s1 = "this";
    s2 = "that";
    s1 = s2;
    return 0;
}


