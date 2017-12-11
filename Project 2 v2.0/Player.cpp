#include "header.h"
#include "Player.h"

void Player::experience()
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