////////////////////////////////////////////////////////////////////////////////
// Christopher Alexman                CSC 17A                       Project 2 //
//                                                                            //
//                                  MINESWEEPER                               //
// 12/11/2017                                                            v2.0 //          
////////////////////////////////////////////////////////////////////////////////
//include all of the classes
#include "header.h"
#include "Game.h"
#include "Player.h"
#include "HighScore.h"
#include "Name.h"
#include "Template.h"

int main()
{
    Game play;                //player is an instance of the game class
    Player character;         //character is an instance of the Player class
    HighScore result;         //result is an instance of the HighScore class
    Name test1(100);          //test1 sends over the value 100
    Name test2(50);           //test2 sends over the value 50
    
    intro();                    //call intro function, outputs instructions
    
    character.experience();     //get experience level of the player

    play.usrInput();          //get user input for width, length, and bombs
    
    play.setup();       //to set up the board, initialize char arrays with '-'
    
    play.setMine();    //to place the mines in random spots in the hidden grid
    
//to calculate for each spot on the hidden grid, how many of the 8 surrounding
//squares are mines
    play.fndMine();
    
    play.start();             //start the game
    
    result.results();           //determine and output the results
    
    test2 = test1;              //set values in test1 equal to test2
    
    output(test1);              //output the results
    output(test2);
    
    cout << "\nPress [Enter] to continue: ";
    cin.get();
    
    system("CLS");
    
    minigame();                 //start the mini game
    
    cout << "Thank you for playing.";

    return 0;
}

//******************************************************************************
// the intro function uses ifstream to read in the rules.txt file and output it
// one line at a time. It waits for the user to read the rules and hit enter
// before it continues. It also uses system to clear the screen so the rules
// are no longer taking up so much space
//******************************************************************************
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

//******************************************************************************
// the output function outputs the results of the = operator being overloaded.
// it uses the Name class as an argument and accesses its member function
// with the n.getGrade().
//******************************************************************************
void output(Name n)
{
    cout << "\n\nHere is an overloaded = operator:\n";
    cout << "I will say this two times:\n";
    cout << "I want to get " << n.getGrade() << "% on Project 2.";
    
}

//******************************************************************************
// the minigame function is the entire line minesweeper mini game. It uses
// vectors of ints and initializes one to have all 0s and the other to have all
// 1s. It randomly places 2s, or mines, in the 1s vector. the user enters in
// guesses as to which elements contain the mines. 
// this function shows off the template.h file
//******************************************************************************
void minigame()
{
    MiniGame<int> zeroTable(64);            //create a vector of 64 elements
    MiniGame<int> intTable(64);
    
    for(int count = 0; count < 64; count++)
    {
        zeroTable[count] = 0;               //fill with respective values
        intTable[count] = 1;
    }

    int twos = 10;              //the number of mines, or 2s
    int holder = 0;             //holds how many mines have been placed
    int spot;                   //the element in the array
    
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
    cout << "Try to find 10 of the 54 total safe spots, represented as 1s.";
    
    int found = 0;          //the number of mines found
    int guess;              //the element of the guess
    int change = 0;
    
    do
    {
        cout << "\n\n";
        
        for(int count = 0; count < 64; count++)     //output the 0s vector
            cout << zeroTable[count] << " ";
        
        cout << "\nYour guess(0-63): ";
        cin >> guess;                       //get guess from user
        
        if(intTable[guess] == 1)            //if it is a 1, it is safe
        {
            zeroTable[guess] = intTable[guess];     //bring 1 to visible array
            found++;                                //only have to find 10
        }
        
        else if(intTable[guess] == 2)           //if it is a mine
        {
            system("CLS");
            
            cout << "Sorry that was a mine. Better luck next time!\n";
            change = 1;             //to exit do while loop
            
            zeroTable[guess] = intTable[guess];     //bring out the mine
            
            for(int index = 0; index < 64; index++)     //output table
                cout << zeroTable[index] << " ";
            
            cin.ignore();
            
            cout << "\n\nPress [ENTER] to continue: ";
            cin.get();                                  //wait for user
        }
        
        system("CLS");
        
    }while(found != 10 && change == 0);       //the challenge is only to find 10
    
    if(found == 10)             //if they found 10
    {
        cout << "\n\nCongratulations you have won the Minesweeper Mini Game!";
    }
}