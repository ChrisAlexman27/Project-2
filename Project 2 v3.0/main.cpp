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
#include "Template.h"

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
    
    cout << "\nPress [Enter] to continue: ";
    cin.get();
    
    system("CLS");
    
    minigame();
    
    cout << "Thank you for playing.";

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

void minigame()
{
    MiniGame<int> zeroTable(64);
    MiniGame<int> intTable(64);
    
    for(int count = 0; count < 64; count++)
    {
        zeroTable[count] = 0;
        intTable[count] = 1;
    }

    int twos = 10;
    int holder = 0;
    int spot;
    
    unsigned seed = time(0);        //get the system time
    srand(seed);                    //seed the random number generator
    
    while (holder < twos)       //loops while current mine num less than ttl
    {
        spot = rand() % 64;             //generates random numbers 0 - 63
        
        if(intTable[spot] != 2)            //if its not already a bomb
        {
            intTable[spot] = 2;            //put a bomb there
            holder++;                      //increment number of mines
        }
    }   
    
    cout << "\n\nYOU WILL NOW PLAY A MINESWEEPER MINI GAME\n";
    cout << "In this row of 64 spots there are 10 mines, represented as 2s. ";
    cout << "Try to find them all.";
    
    int found = 0;
    int guess;
    int change = 0;
    
    do
    {
        cout << "\n\n";
        
        for(int count = 0; count < 64; count++)
            cout << zeroTable[count] << " ";
        
        cout << "\nYour guess(0-63): ";
        cin >> guess;
        
        if(intTable[guess] == 1)
        {
            zeroTable[guess] = intTable[guess];
            found++;
        }
        
        else if(intTable[guess] == 2)
        {
            cout << "Sorry that was a mine. Better luck next time!";
            change = 1;
            
            zeroTable[guess] = intTable[guess];
            
            for(int index = 0; index < 64; index++)
                cout << zeroTable[index] << " ";
            
            cout << "\n\nPress [ENTER] to continue: ";
            cin.get();                                  //wait for user
        }
        
        system("CLS");
        
    }while(found != 10 && change == 0);
    
    if(found == 10)
    {
        cout << "\n\nCongratulations you have won the Minesweeper Mini Game!";
    }
}