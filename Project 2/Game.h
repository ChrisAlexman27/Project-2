// specification file for the Game class
#ifndef GAME_H
#define GAME_H

// Game class declaration

//******************************************************************************
// the Game class stores the entirety of the Minesweeper game with everything
// it needs. all of its various member functions allow the Game class to play
// minesweeper
//******************************************************************************
class Game
{
private: 
    int size;                   //the width and length of the board
    int mines;                  //the number of mines
    char *grid;                 //char array for the visible grid
    char *hdnGrid;              //char array for the hidden grid
    int *eight;                 //array for the 8 surrounding squares
    int count;                  //the position in the for loops
    int positn;                 //the position in the array
    int index;                  //to hold a position
    
    char grdSpot;               //holds the char in hdnGrid arry
    int continu;                //number of spots without a mine
    int holder;                 //holds number of spots without a mine found
    int row;                    //user input of row
    int column;                 //user input of column
    int locatn;                 //location in the array
              
public:  
    
    Game()                                              //Game class constructor
    {  size = 0; mines = 0; holder = 0; column = 0; }

    void display();                 //to display the board
        
    void usrInput();                //to determine the size and mines
    
    void setup();                   //sets up the arrays, dynamically
    
    void setMine();                 //places all of the mines
    
    void fndMine();                 //sets the numbers in each spot of the array
    
    void theEght();                 //the eight surrounding squares
    
    bool checkE();                  //check the eight surrounding squares
    
    char mineCnt();                 //count the number of mines
    
    void theEghtC();                //the eight surrounding squares
    
    bool checkEC();                 //check the eight surrounding squares
    
    void start();                   //start the game
    
    void clear();                   //clear spots for empty space
    
    ~Game();                //destructor, delete dynamically allocated memory
};

#endif /* GAME_H */