/*
*  Purpose for program
*  This program will be using 2D arrays to simulate a
*  fire a spreading through an area. 
*
*  Programmer: Pranav Rao
*  Date: March 31st, 2019
*/

#include <iostream> //Including all the proper directives and headers
#include <string>   //for the opening/closing files, string, etc.
#include <cmath>
#include <fstream>
#include <iomanip>
#include <array>

using namespace std; //Including all the proper using declarations 

void fire( string input, string output );
/*
*  	Function: fire
*  	Purpose: This function will be the primary function for reading in the data.
*  	input - this is the filename to read in the simulation .
*  	output - this is the filename to use for output.
*/

void fire_create( ostream& out, int moist, int burn, string grid);
/*
*  	Function: fire_create
*  	Purpose: This function will be the primary function for reading in the grid data provided
*  	and creating the right output for the initial state values.
*	Command - this is the command and based on which function it will do the proper process.
*/

void fire_display( ostream& out, string data[30][30], int m[30][30], int b[30][30], int x, int y);
/*
*  	Function: fire_display
*  	Purpose: This function will be the primary function for this function is displaying the proper
*  	output based on the calculations in fire_create.
*	Command - this is the command and based on which function it will do the proper process.
*/

void fire_next( ostream& out, string data[30][30], int m[30][30], int b[30][30], int x, int y, int burn); 
/*
*  	Function: fire_next
*  	Purpose: This function will be the primary function for properly calculating the next step after the 
*  	the initial state output based on the calculations in fire_create. This is iteration.
*	Command - this is the command and based on which function it will do the proper process.
*/

int fire_neighbors(string data[30][30], int i, int j, int x, int y);
/*
*  	Function: fire_neighbors
*  	Purpose: This function will be the primary function for properly identifying where and the locations
*	in relation to burning.
*	Command - this is the command and based on which function it will do the proper process.
*/

bool fire_burning( int b[30][30], int x, int y);
/*
*  	Function: fire_buring
*  	Purpose: This function will be the primary function is a boolean function(true or false) to deterermine 
*	where it burning. 
*	Command - this is the command and based on which function it will do the proper process.
*/








