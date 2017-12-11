#ifndef HEADER_H
#define HEADER_H
#include "Name.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <new>              //for bad_alloc
#include <cstdlib>          //for the exit function


using namespace std;

//function prototypes
void intro();
void output(Name);
void minigame();

#endif /* HEADER_H */