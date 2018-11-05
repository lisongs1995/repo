/***************************************************************************
 * 
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file vector.cpp
 * @date 2018/09/02 17:33:45
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "vector.h"

Vector::Vector(int s):size(s) {
    
    if (s==0)
        ptr = nullptr;
    else
        ptr = new int[s];
}

Vector::Vector(Vector& a) {

    if(!a.ptr) {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memecpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

Vector::~Vector() {

    if(ptr) delete[] ptr;
}

Vector& Vector::operator=(const Vector& a) {

    if(ptr == a.ptr) //防止a=a 赋值出错
        return *this;
    if(a.ptr == nullptr) {
        if(ptr) delete[] ptr;
        ptr = nullptr;
        size = 0
        return *this;
    }
    if(size < a.size) { //如果原有的空间够大，就不用分配新的空间了
        if(ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * size);
    size = a.size;
    return *this;
}

void Vector::push_back(int v){

    if(ptr) {
    
        int* tmpPtr = new int[2*size + 1];
        memcpy(tmpPtr, ptr, sizeof(int) * size); //拷贝原数组内容
        delete[] ptr;
        ptr = tmpPtr;
    }
    else
        ptr = new int[initialcapacity]; //表明数组为空
    ptr[size++] = v;
}

