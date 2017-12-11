#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "header.h"

//Template class MiniGame declaration

//******************************************************************************
// the template class MiniGame controls the mini game
//******************************************************************************
template <class T>
class MiniGame
{
private:
    T *line;                        //to point to the array
    int danger;                     //the number of mines
    int sze;                        //the size
        
public:
    MiniGame()
    { line = 0; danger = 0; sze = 0;}
    
    MiniGame(int);
    
    MiniGame(const MiniGame &);
    
    ~MiniGame();
    
    T &operator[](const int &);
            
};

#endif /* TEMPLATE_H */

//******************************************************************************
// constructor. sets the size of the array and allocates memory for it
//******************************************************************************
template <class T>
MiniGame<T>::MiniGame(int s)
{
    sze = s;            //sets size of the array
    
    try
    {
    line = new T [s];   //dynamically allocates memory for it
    }
    catch (bad_alloc)
    {
        cout << "This will catch any errors.";
    }
}

//******************************************************************************
// copy constructor
//******************************************************************************
template <class T>
MiniGame<T>::MiniGame(const MiniGame &obj)
{
    sze = obj.sze;                  //copy the array size
    
    line = new T [sze];             //allocate memory for the array
    
    if (line == 0)
        cout << "ERROR.";
    
    for(int count = 0; count < sze; count++)      //copy elements into obj array
        *(line + count) = *(obj.line + count);
}

//******************************************************************************
//destructor
//******************************************************************************
template <class T>
MiniGame<T>::~MiniGame()
{
    if (sze > 0)
        delete [] line;
}

//******************************************************************************
// overloaded [] operator. the argument is a subscript. this function 
// returns a reference to the element in the array indexed by the subscript
//******************************************************************************
template <class T>
T &MiniGame<T>::operator [](const int &sub)
{
    if(sub < 0 || sub > sze)
        cout << "ERROR.";
    
    return line[sub];
}