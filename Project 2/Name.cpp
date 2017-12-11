#include "header.h"
#include "Name.h"

//******************************************************************************
// constructor, set value of g equal to the private member grade
//******************************************************************************
Name::Name(int g)
{
    grade = g;
}

//******************************************************************************
// return the value in the private member grade
//******************************************************************************
int Name::getGrade() const
{
    return grade;
}

//******************************************************************************
// overload the = operator, for right side of operator
//******************************************************************************
void Name::operator =(const Name& right)
{
    grade = right.grade;
}