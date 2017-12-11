#ifndef PLAYER_H
#define PLAYER_H
#include "header.h"

//Player class declaration

//******************************************************************************
// the player class holds the experience level of the player. it is the base
// class for the derived class called HighScore
//******************************************************************************
class Player
{
protected:                  //protected for the derived class
    int exp;                //the experience of the player
    
public:  
    void setExp(int e);     //set the experience, mutator function
    
    int getExp() const;     //get the experience, accessor function
    
    void experience();      //determine experience level of player
};

#endif /* PLAYER_H */