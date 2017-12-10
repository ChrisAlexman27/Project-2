// specification file for the Game class
#ifndef GAME_H
#define GAME_H

// Game class declaration

class Game
{
private: 
    int size;                   //the width and length of the board
    int mines;                  //the number of mines
    int positn;                 //the position in the array
    char *grid;                 //char array for the visible grid
    char *hdnGrid;              //char array for the hidden grid
    int *eight;                 //array for the 8 surrounding squares
    
    int count; 
    int locatn;
    int row;                    //user input of row
    int column;                 //user input of column
    char grdSpot;               //holds the char in hdnGrid arry
    int continu;                //number of spots without a mine
    int holder;                 //holds number of spots without a mine found
              
public:  
    
    Game();                         //Game class constructor
    
    void intro();
    
    void usrInput();                 //to determine the size and mines
    
    void setup();
    
    void setMine();
    
    void fndMine();
    
    void theEght();
    
    void theEghtC();
    
    char mineCnt();
    
    bool checkE();
    
    bool checkEC();
    
    void start();
    
    void clear();
    
    void display();
    
    ~Game();
};

#endif /* GAME_H */