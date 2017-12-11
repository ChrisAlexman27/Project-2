#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Player.h"

class HighScore : public Player
{
private:
    int score;
    
public:
    HighScore();
    
    void setScore(int s);
    
    int getScore();
    
    void results();
    
};

#endif /* HIGHSCORE_H */