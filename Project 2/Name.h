#ifndef NAME_H
#define NAME_H
#include "header.h"

//Name class declaration

//******************************************************************************
// this class shows off operator overloading of the = sign
//******************************************************************************
class Name
{
private:
    int grade;                              //the grade I want to earn
    
public:
    Name(int g);                            //constructor, set g to =
    
    int getGrade() const;           //get the grade, accessor function
    
    void operator = (const Name &right);         //overload = operator
    
};

#endif /* NAME_H */