#include "header.h"
#include "HighScore.h"

void HighScore::results()
{
    int result;
    int newExp;
    
    newExp = getExp();
    
    cout << "\n\nDid you end up winning?\n";
    cout << "Enter 1 for a win and 0 for a loss: ";
    
    cin >> result;
    
    while(result > 1 || result < 0)
    {
        cout << "ERROR. Enter 1 or 0: ";
        cin >> result;
    }
    
    if(result == 1)
    {
        newExp += 1;
        
        setExp(newExp);
        
        score += 100;
        
        cout << "\nFor this win you have earned +100 points.\n";
        cout << "Your score is now " << score << "points" << endl;
        cout << "You have also gained experience.\n";
        cout << "The experience you started with was " << newExp - 1 << endl;
        cout << "Now your experience is " << getExp();
    }    
    else
    {       
        setExp(newExp);
        
        cout << "\nFor this win you have earned +0 points.\n";
        cout << "Your score is now " << score << "points" <<  endl;
        cout << "You did not gained any experience.\n";
        cout << "The experience you started with was " << newExp << endl;
        cout << "Now your experience is " << getExp();
    }
}