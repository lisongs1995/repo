/***************************************************************************
 * 
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file vector.h
 * @date 2018/09/02 17:23:55
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef VECTOR_H
#define VECTOR_H
//暂不使用模版类，设实现一个int vector
class Vector {
    private:
        const int initialCapacity = 10;
        int size; //数组元素个数
        int* ptr;
    
    public:

        Vector(int s=initialCapacity);  //s代表数组元素的个数
        Vector(Vector& a);
        ~Vector();
        void push_back(int v);
        Vector& operator=(const Vector& a); //深拷贝
        
        inline int& operator[](size_t i) {
            //返回引用，从而操作数剧
            return ptr[i];
        }

        inline int length() {
            return size;
        }

};



#endif  // VECTOR_H

