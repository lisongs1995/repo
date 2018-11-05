/***************************************************************************
 * 
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @date 2018/09/02 17:01:43
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "complex.h"

Complex Complex::operator+(double r) {
    
    return Complex(real + r, imag);
}

Complex operator+(double r, const Complex& c) {

    return Complex(c.real + r, c.imag);
}

int main(int argc, char** argv) {

    Complex src(2.1, 5.3);
    src = src + 5;
    //  question : what hadppen if src = 5 + src ? // error
     
}

