#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "header.h"

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

template <class T>
MiniGame<T>::MiniGame(int s)
{
    sze = s;
    
    try
    {
    line = new T [s];
    }
    catch (bad_alloc)
    {
        cout << "This will catch any errors.";
    }
}

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

template <class T>
MiniGame<T>::~MiniGame()
{
    if (sze > 0)
        delete [] line;
}

template <class T>
T &MiniGame<T>::operator [](const int &sub)
{
    if(sub < 0 || sub > sze)
        cout << "ERROR.";
    
    return line[sub];
}