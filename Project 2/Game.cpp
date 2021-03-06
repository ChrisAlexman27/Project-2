#include "header.h"
#include "Game.h"
#include "Player.h"
#include "HighScore.h"

//******************************************************************************
// This function passes the structure by reference to access the structure 
// members. It uses an int choice to get the choice of the user from one of 
// three preset options. There is input validation for the choice in the while
// loop. Based on the choice of the user, the size and number of mines are set
// to the values in the if/ else if statements.
//******************************************************************************
void Game::usrInput()
{   
    int choice;                         //the choice the user enters
    
    cout << "\n\nMINESWEEPER v2.0\n";
    cout << "The options:\n";
    cout << "1. BEGINNER -     8x8   field, 10 mines\n";
    cout << "2. INTERMEDIATE - 16x16 field, 40 mines\n";
    cout << "3. EXPERT -       24x24 field, 99 mines\n";
    cout << "Your choice: ";
    
    cin >> choice;                      //get the choice
    
    while(choice > 3 || choice < 1)     //loop while choice is not 1,2, or 3
    {
        cout << "ERROR. Enter a valid input : ";
        cin >> choice;
    }
    
    if(choice == 1)                    //if they chose 1
    {
        size = 8;                    //set structure members = to these values
        mines = 10;
    }
    else if(choice == 2)               //if they chose 2
    {
        size = 16;                   //set structure members = to these values
        mines = 40;
    }   
    else if(choice == 3)               //if they chose 3
    {
        size = 24;                   //set structure members = to these values
        mines = 99;
    }
    
    system("CLS");                      //clear the screen after the choice
}

//******************************************************************************
// this function dynamically allocates memory for the grid, hdnGrid, and eight
// arrays. It goes on to initialize them with values of -, -, and 0
// respectively
//******************************************************************************
void Game::setup()
{
//dynamically allocate a char array large enough to hold the size*size
    grid = new char[size * size];
    hdnGrid= new char[size * size];
    
    eight = new int[8];
    
    int ttlSize = size * size;         //total size of the char arrays
    
    for(int count = 0; count < ttlSize; count++)
    {
        grid[count] = '-';              //initialize with the dash char '-'
        hdnGrid[count] = '-';           //initialize with the dash char '-'
    }
    
    for(int count = 0; count < 8; count++)
    {
        eight[count] = 0;
    }
}

//******************************************************************************
// This function randomly creates an element number for the hidden grid and
// puts a bomb into that spot. It uses an increment operator to make sure the
// number of mines never exceeds the amount of mines selected. It also uses an
// if statement to make sure a bomb is not already there.
//******************************************************************************
void Game::setMine()
{
    int mine;           //random number created, the element of the char array
    int mineCnt = 0;      //number of mines, for while loop, start at 0
    
    unsigned seed = time(0);        //get the system time
    srand(seed);                    //seed the random number generator
    
    while (mineCnt < mines)       //loops while current mine num less than ttl
    {
        mine = rand() % (size * size);    //rand num range 0 to size*size -1
        
        if(hdnGrid[mine] != '*')            //if its not already a bomb
        {
            hdnGrid[mine] = '*';            //put a bomb there
            mineCnt++;                      //increment number of mines
        }
    }   
}

//******************************************************************************
// This function will ultimately determine how many bombs are surrounding each
// spot on the n*n grid. The int array eight holds the position of the 8 
// spots that surround a center square. The theEght function determines the 
// positions of the 8 spots. The mineCnt function is then called which in turn
// counts the number of mines, setting it equal to the center square in the
// hdnGrid array.
//******************************************************************************
void Game::fndMine()
{    
    for(count = 0; count < size * size; count++)
    {
        if(hdnGrid[count] != '*')           //if center spot not a mine
        {
            theEght();       //call function
            
            hdnGrid[count] = mineCnt();  //call function
        }
    }
}

//******************************************************************************
// This function determines the element location of the 8 spots surrounding a 
// center spot. Here is a visual:
//  
//    (count - size) - 1    |    (count - size)    |    (count - size) + 1  
//    ----------------------------------------------------------------------
//    (count - 1)           |    CENTER SPOT       |    (count + 1)
//    ----------------------------------------------------------------------
//    (count + size) - 1    |    (count + size)    |    (count + size) + 1
//
// This is a 3x3 grid. The center spot is the spot being looked at currently by
// the hidden grid. This logic of subtracting/adding the size and subtracting
// or adding 1 is to find their respective spots and store them in the eight
// array. The top are 0, 1, 2. The left of center is 3, right is 4. The bottom
// row is 5, 6, and 7.
// This works because the size, adding or subtracting it, lands you above or 
// below the current spot. The +/- 1 is just an adjustment.
//******************************************************************************
void Game::theEght()
{
    eight[0] = (count - size) - 1;
    eight[1] = (count - size);
    eight[2] = (count - size) + 1;
    
    eight[3] = (count - 1);
    eight[4] = (count + 1);
    
    eight[5] = (count + size) - 1;
    eight[6] = (count + size);
    eight[7] = (count + size) + 1;
}

//******************************************************************************
// This function takes in the positions from the eight array and searches each
// of them to count the number of mines. It also uses the check function to 
// determine if the position is outside of the grid. If it is not it sees if 
// that position spot has a mine and increments the number of mines. Since the
// number of mines needs to be stored in the hdnGrid array and it is a char
// array the int has to be converted to a ' ' space or a char value.
//******************************************************************************
char Game::mineCnt()
{
    int mines = 0;              //the number of mines found
    char value;                 //the char value to put into the hdnGrid array
    
    for(positn = 0; positn < size; positn++)
    {
        if( checkE() )     //call check function, if false stops
        {
            int holder = eight[positn];          //holder for position in array
            
            if(hdnGrid[holder] == '*')          //if theres a mine there
            {
                mines++;                        //increment the mines
            }
        }
    }
    
    if(mines == 0)                              //if no mines found
    {
        value = ' ';                            //no number will be shown
    }   
    else
    {
        value = ( char ) ( ( ( int ) '0' ) + mines );   //int converted to char
    }
    
    return value;               //return either a blank space or a char number
}

//******************************************************************************
// This function checks the eight positions found by the eight int function and
// determines whether or not they are inside the array. If they are outside of
// the array it will return false and not check for a mine there. The boolean
// result that it return is automatically true, until proven false. It goes
// through conditions to figure out if it is outside the grid.
//******************************************************************************
bool Game::checkE()
{
    bool result = true;                 //returns true if nothing found false
    
    if(count < size)                 //checks NW, N, NE
    {
        if((positn == 0) || (positn == 1) || (positn == 2))
        {
            result = false;
        }
    }
    
    if(size * (size - 1) <= count) //checks SW, S, SE
    {
        if((positn == 5) || (positn == 6) || (positn == 7))
        {
            result = false;
        }
    }
    
    if(count % size == 0)            //checks NW, W, SW
    {
        if((positn == 0) || (positn == 3) || (positn == 5))
        {
            result = false;
        }
    }
    
    if((count + 1) % size == 0)      //checks NE, E, SE
    {
        if((positn == 2) || (positn == 4) || (positn == 7))
        {
            result = false;
        }
    }
    
    if(positn > 7)                       //for options 2 and 3, makes sure the
    {                                   //bounds of the array are kept, only 0-7
        result = false;
    }
    
    return result;
}

//******************************************************************************
// This function outputs the one dimensional array into the shape of an n by n
// minesweeper board. It achieves this by first outputting a top line of
// numbers which is equal to n (the width or height). It then checks if the 
// value is under 10 so it can add another space, making the dashes ( - ) be 
//able to line up with the later 2 digit numbers if there are any. The next
// for loop outputs the row numbers and the entire row itself.
//This function is also called after every move, it changes based on the move.
//******************************************************************************
void Game::display()
{
    cout << endl << endl;                           //initial formatting
    cout << "  ";                                   //initial formatting
    for(int count = 1; count <= size; count++)    //1 to row length
    {
        cout << "  " << count;                      //space between numbers
        if(count < 10)                              //more space, only 1 digit
        {                                             //versus the 2 digits
            cout << " ";
        }
    }
    cout << endl;                                   //to start the rows
    
    for(count = 0; count < size; count++)     //0 to row length - 1
    {
        cout << setw(2) << count + 1 << "  ";       //to output row number
        
        for(index = 0; index < size; index++) //outputs the dashes in each
        {                                                                  //row
            cout << grid[size*count + index] << "   ";   //[here] for the dash
        } 
        cout << endl;
    }
}

//******************************************************************************
// This function controls the game in determining that the board is displayed
// after every turn and in checking for a potential win/loss. It achieves this
// with a do while loop, allowing it to loop until the spot searched by the user
// it not a mine and the number of mines uncovered is less that the amount of
// free spots available. It leaves when one of these are met and uses some if
// statements to determine if the user hit a bomb or uncovered all of the 
// squares on the grid.
//******************************************************************************
void Game::start()
{ 
    holder = 0;
    continu = size * size - mines; 
    
    do{
        system("CLS");                  //clear the screen
        display();               //call function, displays board

        cout << "Enter row [space] column: ";
        cin >> row >> column;                       //get input for row, column

//input validation for row and column amount
        while(row > size || row < 1 || column > size || column < 1)
        {
            cout << "ERROR. Invalid input.\n";
            cout << "Enter row [space] column: ";
            cin >> row >> column;
        }

//position in the array
        locatn = (size * (row - 1)) + (column - 1);    

        if(grid[locatn] == '-')             //if it is a dash ( - )
        {
            grdSpot = hdnGrid[locatn];      //take the hidden grid char
            grid[locatn] = grdSpot;         //put it in the regular grid spot
            
            if(grdSpot == ' ')              //if no mines around it
            {
                clear();   //call clear function
            }
        }
        
        if(grdSpot != '*')                  //it not a mine
        {
            holder++;                       //increment holder
        }
    
    }while(holder < continu && grdSpot != '*');     //while not mine, and
                                                    //not all spots uncovered
    system("CLS");
    
    if(holder == continu)       //if all spots possible uncovered
    {
        display();                       //display grid
        cout << "\nYOU HAVE WON MINESWEEP";     //cout win message
    }
    
    if (grdSpot == '*')         //if a mine was found
    {
        for(int count = 0; count < size * size; count++)
        {
            if(hdnGrid[count] == '*')               //put all from hidden grid
            {
                grid[count] = '*';                  //into the regular grid
            }       
        }
        display();                           //display the grid
        cout << "\n\nYOU HAVE LOST MINESWEEP";      //cout lose message
    }
}

//******************************************************************************
// This function determines if a whole section of squares on the grid are 
// empty. If they are it opens up the section with spaces.
//******************************************************************************
void Game::clear()
{
//    int eight[8];                   //for the 8 surrounding spots
    
    theEghtC();
    
    for(count = 0; count < 8; count++)
    {
        if( checkEC() )          //check if outside the grid
        {
            if(grid[eight[count]] == '-')       //if its a dash ( - )
            {
//move space from hidden grid to regular grid, increment counter
                grid[eight[count]] = hdnGrid[eight[count]];
                holder++;
                
                if(hdnGrid[eight[count]] == ' ')    //if theres a space
                {
//checks surrounding squares of the original 8 surrounding squares, recursive
                    clear();
                }
            }
        }
    }
}

//******************************************************************************
// This function determines the element location of the 8 spots surrounding a 
// center spot. Here is a visual:
//  
//    (count - size) - 1    |    (count - size)    |    (count - size) + 1  
//    ----------------------------------------------------------------------
//    (count - 1)           |    CENTER SPOT       |    (count + 1)
//    ----------------------------------------------------------------------
//    (count + size) - 1    |    (count + size)    |    (count + size) + 1
//
// This is a 3x3 grid. The center spot is the spot being looked at currently by
// the hidden grid. This logic of subtracting/adding the size and subtracting
// or adding 1 is to find their respective spots and store them in the eight
// array. The top are 0, 1, 2. The left of center is 3, right is 4. The bottom
// row is 5, 6, and 7.
// This works because the size, adding or subtracting it, lands you above or 
// below the current spot. The +/- 1 is just an adjustment.
//******************************************************************************
void Game::theEghtC()
{
    eight[0] = (locatn - size) - 1;
    eight[1] = (locatn - size);
    eight[2] = (locatn - size) + 1;
    
    eight[3] = (locatn - 1);
    eight[4] = (locatn + 1);
    
    eight[5] = (locatn + size) - 1;
    eight[6] = (locatn + size);
    eight[7] = (locatn + size) + 1;
}

//******************************************************************************
// This function checks the eight positions found by the eight int function and
// determines whether or not they are inside the array. If they are outside of
// the array it will return false and not check for a mine there. The boolean
// result that it return is automatically true, until proven false. It goes
// through conditions to figure out if it is outside the grid.
//******************************************************************************
bool Game::checkEC()
{
    bool result = true;                 //returns true if nothing found false
    
    if(locatn < size)                 //checks NW, N, NE
    {
        if((count == 0) || (count == 1) || (count == 2))
        {
            result = false;
        }
    }
    
    if(size * (size - 1) <= locatn) //checks SW, S, SE
    {
        if((count == 5) || (count == 6) || (count == 7))
        {
            result = false;
        }
    }
    
    if(locatn % size == 0)            //checks NW, W, SW
    {
        if((count == 0) || (count == 3) || (count == 5))
        {
            result = false;
        }
    }
    
    if((locatn + 1) % size == 0)      //checks NE, E, SE
    {
        if((count == 2) || (count == 4) || (count == 7))
        {
            result = false;
        }
    }
    
    if(count > 7)                       //for options 2 and 3, makes sure the
    {                                   //bounds of the array are kept, only 0-7
        result = false;
    }
    
    return result;
}

//******************************************************************************
// this function deletes the dynamically allocated memory of the grid,
// hdnGrid, and eight arrays
//******************************************************************************
Game::~Game()
{
//free dynamically allocated memory for grid and hdnGrid and eight
    delete [] grid;
    grid = nullptr;                     //make grid a null pointer
    delete [] hdnGrid;
    hdnGrid = nullptr;                  //make hdnGrid a null pointer
    delete [] eight;
    eight = nullptr;                    //make eight a null pointer
}   