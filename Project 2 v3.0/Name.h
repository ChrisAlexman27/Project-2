#ifndef NAME_H
#define NAME_H
#include "header.h"

class Name
{
private:
    int grade;
    
public:
    Name(int g);
    
    int getGrade() const;
    
    void operator = (const Name &right);         //overload = operator
    
};

#endif /* NAME_H */