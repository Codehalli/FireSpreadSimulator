/*
*  Purpose for program
*  This program will be using 2D arrays to simulate a
*  fire a spreading. 
*
*  Programmer: Pranav Rao
*  Date: March 31st, 2019
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
#include "fire.h"

void fire( string input, string output ) //fire function which is declared in the header file
	{
		ifstream in(input);     //reading file
		ofstream out(output);   //outputting file  
		
		string enter;			//Declaring the variables			
		
		int moist, burn;
		string grid;
	
		in >> enter; 			//input  

		while(!in.fail()) //while loop to declare which command
		{
			if ( enter == "Moisture:" )              //inputs moisture values
			{
				in >> moist;
				
				out << "Moisture: " << moist << endl;   
			}
			else if ( enter == "Burn:" )             //inputs burn values
			{
				in >> burn;
				
				out << "Burn: " << burn << endl;
			}
			else if ( enter == "Grid:" )             //inputs grid file
			{
				in >> grid;
				
				out << "Grid_file: " << grid << endl;
			}
			in >> enter;
		
		}
		
		fire_create( out, moist,  burn, grid);           //calls in the fire_create function
		
	}
	
void fire_create( ostream& out, int moist, int burn, string grid )	//fire_create function which is 
{																	//declared in the header file
	
	ifstream in(grid);  //reading file  
	
	string enter;     //declaring variable
	
	int r, c;
	int x, y;
	
	string data[30][30]; //declaring 30x30 arrays
	int m [30][30];
	int b [30][30];
	
	out << "Initial State: " << endl;          //output initial state: word
	
	in >> enter >> r >> enter >> c;            //input the values for the variables
	
	if (r > 30)         //selection statement for rows
	{                  
		x = 30;
	}
	else 
	{
		x  = r; 
	}
	
	if (c > 30)         //selection statement for columns
	{
		y = 30; 
	}
	else 
	{
		y = c;
	}
	
	int j = 0;
	int i = 0;
	
	while(i < x)      //while loop for irritation of letters
	{
		j=0;
		while(j < y)
		{
			in >> enter;
			data[j][i]= enter;
			
			if(enter == "n")     //selection statement for letters 
			{
				m[j][i]= moist;
				b[j][i]= 0;
				
				
			}
			else if( enter == "b") //used an else-if
			{
				m[j][i]= 0;
				b[j][i]= burn; 
				
				
			}
			else 
			{
				m[j][i]= 0;
				b[j][i]= 0; 
				
				
			}
			
			j = j + 1;              //counter
		}
		if (c > y)                     //statements for break in lines
		{
			in.ignore(500, '\n');
		}
		
	 
		i = i + 1;                  //counter
	}
	
	
	fire_display(out, data,  m,  b, x, y);  //calls in in the display function

	int number = 1;
	
	while( fire_burning(b, x, y))          //while loop for iteration  of steps 
	{
		out<< "Step: " << number << endl;   //output the word step:
	
		number= number +1;                   //counter
	
		fire_next(out, data,  m,  b, x, y, burn);       //calls in fire_next function
	}
	
	out<< "Final State: " << endl;             //output words final step 
	fire_display(out, data,  m,  b, x, y);  
}                                               //calls in fire_display function

//fire_next function which is declared in the header file
void fire_next( ostream& out, string data[30][30], int m[30][30], int b[30][30], int x, int y, int burn )
{
	
	int j = 0;      //declaring and initializing variable
	int i = 0;
	
	while(i < x)     //while loop for irritation of near burning
	{                //checks each time
	 
	 j = 0;
	 while(j < y)	//while-in-a while
	 {
		
		if(data[j][i] == "n") //selection statement for n  
		{
			m[j][i] = m[j][i] - fire_neighbors(data, i, j, x, y);
		}	
		
		if ( m[j][i] < 0)  //selection statement for less than 0
		{ 
			m[j][i] = 0;
			data[j][i] = "b";
			b[j][i] = burn +1;
		}
		  
		if(data[j][i] == "b")   //selection statement for b
		{

			b[j][i] = b[j][i] - 1;
			
			if(b[j][i] == 0)
			{
				data[j][i]= "t";
			}
		
		}
		
		j = j + 1;      //counter
	 }
	 
	 i = i + 1;			//counter
	}
	
	fire_display(out, data, m, b, x, y); //calls in fire_display function
}	

bool fire_burning( int b[30][30], int x, int y) //fire_burning boolean function which is declared in the header file
{
	int j = 0; 	//declared and initializing variables 
	int i = 0;
	bool fire = false;	//declare boolean false
	
	while(i < x) //while loop for irritation of it's still burning
	{
		j=0;
		while(j < y)
		{
			
			if ( b[j][i] > 0)   //array b is less than 0
			{
				fire = true;
				
			}
			
			j = j + 1; 		//counter
		
		}

		i = i + 1;         //counter
	}


	return fire;        //return fire


}	
	
int fire_neighbors(string data[30][30], int i, int j, int x, int y ) //fire_neighbors function which is declared in the header file	
{		
	int neighbors = 0;  //declared and initialized variable
	
	if( j !=0 && data[j-1][i] == "b" )   //selection statement to determine where it is burning
	{
		neighbors ++; 
	} 
	if ( j != y -1 && data[j+1][i] == "b" )
	{
		neighbors ++;
	}
	if ( i !=0 && data[j][i - 1] == "b" )
	{
		neighbors ++;
	}
	if ( i != x -1 && data[j][i +1] == "b" )
	{
		neighbors ++;
	}
	
	return neighbors;	//return neighbors
}

void fire_display( ostream& out, string data[30][30], int m[30][30], int b[30][30], int x, int y ) //calling the fire_display function 
{
	int j=0;        //declared and initialized variables
	int i = 0;
	
	while(i < x)   //while loop to output the values that have been calculated 
	{
		j=0;    
		while(j < y)
		{
			out << data[j][i];  //output the data array
			
			j= j+1;            //counter
			
		}
		out << "\t" << "\t";
	
		j = 0;
		while(j < y)
		{
			out << m[j][i];     //output  the m array
			
			j= j+1;				//counter
			
		}
		out << "\t" << "\t";
		
		j = 0;
		while(j < y)
		{
			out << b[j][i];		//output for b array
			
			j= j+1;				//counter
			
		}	
		out << endl;
	
		i = i + 1;				//counter for outside while loop
	}
	
}


