/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file complex.h
 * @author __OPERATOR__(_OPERATOR@baidu.com)
 * @date 2018/09/02 16:59:42
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex {

        double real, imag;
    
    public:
        
        Complex(double r, double i):
            real(r),
            imag(i)
            {}

        Complex operator+(double r);

        friend Complex operator+(double r, const Complex& c);
};
#endif  // COMPLEX_H

