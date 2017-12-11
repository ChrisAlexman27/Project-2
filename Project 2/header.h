#ifndef HEADER_H
#define HEADER_H
#include "Name.h"           //for the output function

#include <iostream>         //for general input/output
#include <iomanip>          //for setw()
#include <fstream>          //for file input/output
#include <new>              //for bad_alloc
#include <cstdlib>          //for the exit function

using namespace std;

//function prototypes
void intro();               //calls the rules file, tells user the rules
void output(Name);          //shows off the overload = operator
void minigame();            //its a mini game that uses templates

#endif /* HEADER_H */