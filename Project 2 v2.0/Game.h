// specification file for the Game class
#ifndef GAME_H
#define GAME_H

// Game class declaration

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

    void display();
        
    void usrInput();                 //to determine the size and mines
    
    void setup();
    
    void setMine();
    
    void fndMine();
    
    void theEght();
    
    bool checkE();
    
    char mineCnt();
    
    bool checkEC();
    
    void start();
    
    void clear();
    
    void theEghtC();
    
    ~Game();
};

#endif /* GAME_H */