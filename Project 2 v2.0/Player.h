#ifndef PLAYER_H
#define PLAYER_H
#include "header.h"

class Player
{
protected:
    int exp;                //the experience of the player
    
public:  
    void setExp(int e)
    { exp = e; }
    
    int getExp() const
    { return exp; }
    
    void experience();
    
};

#endif /* PLAYER_H */