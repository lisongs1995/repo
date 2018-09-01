/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file strcpy.cpp
 * @author __OPERATOR__(_OPERATOR@baidu.com)
 * @date 2018/09/01 18:58:06
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <iostream>
#include <cstring>

using namespace std;

char* _strcpy(char* strDst, char* strSrc){

    assert(strDst != nullptr &&  strSrc != nullptr);
    char* ret = strDst;
    while ((*strDst++=*strSrc++)!='\0');
    return ret;
}


int main(int argc, char** argv){

    char dst_1[10];
    char dst_2[10];
    char* src = "test func";
    char* ret_1 = _strcpy(dst_1, src);
    char* ret_2 = strcpy(dst_2, src);  //当src越界的时候我写的函数会报错，但是  
    cout << ret_1 << endl;  // 系统strcpy却没有。
    cout << ret_2 << endl;
    return 0;
}
