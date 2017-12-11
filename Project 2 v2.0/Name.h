#ifndef NAME_H
#define NAME_H
#include "header.h"

class Name
{
private:
    int grade;
    
public:
    Name(int g)
    { grade = g; }
    
    int getGrade() const
    { return grade; }
    
    void operator = (const Name &right)         //overload = operator
    { grade = right.grade; }
    
};

#endif /* NAME_H */

