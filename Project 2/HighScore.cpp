#include "header.h"
#include "HighScore.h"

//******************************************************************************
// constructor, sets score to 0
//******************************************************************************
HighScore::HighScore()
{
    score = 0;
}

//******************************************************************************
// assigns the argument s to the private member variable score
//******************************************************************************
void HighScore::setScore(int s)
{
    score = s;
}

//******************************************************************************
// returns the value in the private member variable score
//******************************************************************************
int HighScore::getScore()
{
    return score;
}

//******************************************************************************
// the experience function asks the experience level of the user.
// it calls the setExp member function to store that experienc value
//******************************************************************************
void HighScore::experience()
{
    int respons;
    
    cout << "How would you rank your experience with playing Minesweeper?\n";
    cout << "The scale is 0-9.\n";
    cout << "Enter: ";
    
    cin >> respons;
    
    while(respons > 9 || respons < 0)
    {
        cout << "ERROR. Enter a value(0-9): ";
        cin >> respons;
        cout << endl;
    }
    
    setExp(respons);
    
    system("CLS");                      //clear the screen after the choice
}

//******************************************************************************
// results prompts the user if they won the game or not. based on that it
// awards them score points and an increase in experience or nothing if they
// lost. it accesses the class that it is derived from with the setExp
// function on line 55
//******************************************************************************
void HighScore::results()
{
    int result;                 //if they won or loss, 1 or 0
    int newExp;                 //their new experience value
    
    newExp = getExp();          //get the amount of experience entered
    
    cout << "\n\nDid you end up winning?\n";
    cout << "Enter 1 for a win and 0 for a loss: ";
    
    cin >> result;
    
    while(result > 1 || result < 0)         //input validation
    {
        cout << "ERROR. Enter 1 or 0: ";
        cin >> result;
    }
    
    if(result == 1)         //if they won
    {
        newExp += 1;        //add 1 to their experience
        
        setExp(newExp);     //call the inherited setExp function
        
        score += 100;
        
        cout << "\nFor this win you have earned +100 points.\n";
        cout << "Your score is now " << score << " points" << endl;
        cout << "You have also gained experience.\n";
        cout << "The experience you started with was " << newExp - 1 << endl;
        cout << "Now your experience is " << getExp();
    }    
    else                    //if they lost
    {       
        setExp(newExp);     //call the inherited setExp function
        
        cout << "\nFor this loss you have earned +0 points.\n";
        cout << "Your score is now " << score << " points" <<  endl;
        cout << "You did not gained any experience.\n";
        cout << "The experience you started with was " << newExp << endl;
        cout << "Now your experience is " << getExp();
    }
    
    cin.ignore();           //get rid of the enter key in the keyboard buffer
    
    cout << "\n\nPress [Enter] to continue: ";
    cin.get();                                      //wait for response
    
    system("CLS");                                  //clear the screen
}