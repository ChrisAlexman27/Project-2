#include "header.h"
#include "Name.h"

Name::Name(int g)
{
    grade = g;
}

int Name::getGrade() const
{
    return grade;
}

void Name::operator =(const Name& right)
{
    grade = right.grade;
}