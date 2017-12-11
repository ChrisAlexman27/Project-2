#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Player.h"

class HighScore : public Player
{
private:
    int score;
    
public:
    HighScore()
    { score = 0; }
    
    void setScore(int s)
    { score = s; }
    
    int getScore()
    { return score; }
    
    void results();
    
};

#endif /* HIGHSCORE_H */

