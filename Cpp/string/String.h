/***************************************************************************
 * 
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file String.h
 * @date 2018/09/02 16:24:28
 * @version $Revision$ 
 * @brief 
 *  
**/
#ifndef STRING_H
#define STRING_H
class MyString {
 
    private:
        
        char* str;
    
    public:
        
        MyString():
            str(nullptr)
            {}
        
        const char* c_str(){
            return str;
        }

        char* operator=(const char* s);
    
        MyString& operator=(const MyString& s);
    
         ~MyString();

};

#endif  // STRING_H


