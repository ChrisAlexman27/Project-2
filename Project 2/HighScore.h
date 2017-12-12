#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Player.h"

//HighScore class declaration

//******************************************************************************
// the HighScore class is derived from the Player class
//******************************************************************************
class HighScore : public Player
{
private:
    int score;                  //the score of the player
    
public:
    HighScore();                //constructor, set score to 0
    
    void setScore(int s);       //set the score, mutator function
    
    int getScore();             //get the score, accessor function
    
    void experience();      //determine experience level of player
    
    void results();             //print the results
    
};

#endif /* HIGHSCORE_H */