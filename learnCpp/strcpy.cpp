 /**
 * @file strcpy.cpp
 * @date 2018/09/01 18:58:06
 * @version $Revision$ 
 * @brief 
 *  
 **/
//thinking：
//c++在编译期与运行期不会检查strcpy带来的数组越界
//但有可能出现未知内存被占用而导致程序崩溃的危险
//建议使用string类或者用更安全的strncpy

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
