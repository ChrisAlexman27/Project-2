////////////////////////////////////////////////////////////////////////////////
// Christopher Alexman                CSC 17A                       Project 2 //
//                                                                            //
//                                  MINESWEEPER                               //
// 12/11/2017                                                            v2.0 //          
////////////////////////////////////////////////////////////////////////////////
#include "header.h"
#include "Game.h"
#include "Player.h"
#include "HighScore.h"
#include "Name.h"

int main()
{
    Game play;                //player is an instance of the game class
    Player character;
    HighScore result;
    Name test1(100);
    Name test2(50);
    
    intro();
    
    character.experience();

    play.usrInput();          //get user input for width, length, and bombs
    
    play.setup();       //to set up the board, initialize char arrays with '-'
    
    play.setMine();    //to place the mines in random spots in the hidden grid
    
//to calculate for each spot on the hidden grid, how many of the 8 surrounding
//squares are mines
    play.fndMine();
    
    play.start();             //start the game
    
    result.results();
    
    test2 = test1;
    
    output(test1);
    output(test2);

    return 0;
}

void intro()
{
    ifstream file("rules.txt");
    
    if(!file)                               //if file doesn't open
    {
        cout << "CANNOT OPEN FILE\n";
    }
    
    char line[255];
    
    while(!file.eof())                      //while not at end of file
    {
        file.getline(line, 255);            //get the entire line
        if(line)
        {
            cout << line << endl;           //output the entire line
        }   
    }
    
    file.close();                           //close the file
    
    cout << "\n\nPress [ENTER] to continue: ";
    cin.get();                                  //wait for user to read rules
    
    system("CLS");                              //clear the screen
}

void output(Name n)
{
    cout << "\n\nHere is an overloaded = operator:\n";
    cout << "I will say this two times:\n";
    cout << "I want to get " << n.getGrade() << "% on Project 2.";
}