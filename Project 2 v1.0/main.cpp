////////////////////////////////////////////////////////////////////////////////
// Christopher Alexman                CSC 17A                       Project 2 //
//                                                                            //
//                                  MINESWEEPER                               //
// 12/11/2017                                                            v2.0 //          
////////////////////////////////////////////////////////////////////////////////
#include "header.h"
#include "Game.h"

int main()
{
    Game player;                //player is an instance of the game class

    player.usrInput();          //get user input for width, length, and bombs
    
    player.setup();       //to set up the board, initialize char arrays with '-'
    
    player.setMine();    //to place the mines in random spots in the hidden grid
    
//to calculate for each spot on the hidden grid, how many of the 8 surrounding
//squares are mines
    player.fndMine();
    
    player.start();             //start the game
    
    return 0;
}