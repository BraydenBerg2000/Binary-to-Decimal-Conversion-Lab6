/*
Brayden Berg
C++ Fall 2019
Due: November 14, 2019
Binary to Decimal Conversion
	Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings.
*/
//these are the necessary libraries that are used to execute this program
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;
//these are the prototypes for the void output and check functions
void check(char& line, char& out, int& space, bool& display, ifstream& inFile, ifstream& inFile2);
void output(char& line, unsigned int& decimal, bool& display, ifstream& inFile, int& space, unsigned int& numcount, int& space2);
//this is the 
int main()
{
	//this sets the identifier, display, as a bool type and sets it as true
	bool display = true;
	//this is the heading for the outputted data
	cout << setw(26)<<"Binary Number"<< setw(38)<<"Decimal Equivilant" << endl;
	//this sets the file that is to be read as a string
	string inputfile = "C:/Users/brayd/OneDrive/Desktop/C++ Projects/Lab 6 Binary Conversion/BinaryIn.dat";
	ifstream inFile;
	//this makes a second copy of the file so that it can be changed in a different way than the original copy so side affects don't occurr
	string inputfile2 = "C:/Users/brayd/OneDrive/Desktop/C++ Projects/Lab 6 Binary Conversion/BinaryIn.dat";
	ifstream inFile2;
	//these open the file two different times, one for the original and one for the copy
	inFile.open(inputfile);
	inFile2.open(inputfile2);
	//this sets the identifier line as a character value
	char line;
	//this sets the identifier out as a character value
	char out = 0;
	//these are the priming reads
	inFile.get(line);
	inFile2.get(out);
	//Precondition: before this while statement initializes the header should have properly outputted andthe file should be read through and opened, and the the previous identifiers 
	//should be set correctly
	//Postcondition: after the program has finished it should execute the desired outcome of this lab without fail or error
	while (inFile)
	{
		//this sets the identifier decimal as an unsigned integer that equals 0
		unsigned int decimal = 0;
		//this sets the identifier numcount as an unsigned integer
		unsigned int numcount;
		//this sets the identifier space as an integer that equals 0
		int space = 0;
		//this sets the identifier space2 as an integer that equals 0
		int space2 = 0;
		//this is the function call to the void check function
		check(line, out, space, display, inFile, inFile2);
		//this is the function call to the void output function
		output(line, decimal, display, inFile, space, numcount, space2);
	}
	return 0;
}
//Precondition: the binary characters must be intialized
//Postcondition: the binary numbers will have been read and determined if they are valid or invalid, skipping over any spaces or 0s until the first 1 is reached. 
//If they are valid then they are sent on to be converted. If they are invalid then they are sent to activate the "Bad digit on input" statement.
void check(char& line, char& out, int&space, bool& display, ifstream& inFile, ifstream& inFile2)
{
	//this while statement allows the program to skip over any spaces, 0s, or new line characters until it reaches a one
	while (line == '0' || line == ' ' || line == '\n')
	{
		inFile.get(line);
		inFile2.get(out);
	}
	//this while statement makes it so that if there is an invalid character read in the binary segment, then display is set equal to false
	while (out != '\n' && inFile2)
	{
		space++;
		if (out != '1' && out != '0')
		{
			display = false;
		}
		inFile2.get(out);
	}
}
//Precondition: the file should've read in and checked the characters sorting the binary statement to make display either equal to true or false
//Postcondition: if display equals true the binary segments should be outputted centered, with the converted decimal value following, also centered. If display equals flase then the sentence
//"Bad digit on input" should be outputted. This should repeat for as many times as there are binary segments.
void output(char& line, unsigned int& decimal, bool& display, ifstream& inFile, int& space, unsigned int&numcount, int&space2)
{
//if display is equal to true then this if statement executes
	if (display == true)
		{
			//this centers the binary segments
			cout << setw(20 - space / 2);
			//this while statement will execute as long as there is no end of line character and the inFile is still valid
			while (line != '\n' && inFile)
			{
				//this converts the character, line, into an integer identifier named, num.
				int num = int(line) - 48;
				//this takes the identifier decimal and multiplies it by 2 and assignes decimal the answer
				decimal *= 2;
				//this outputs the binary numbers
				cout << num;
				//if num equals 1 then this if statement adds one to decimal and assigns the answer
				if (num == 1)
				{
					decimal += 1;
				}
				//if num equals 0 then this else if statement doesn't change decimal
				else if (num == 0)
				{
						decimal;
				}
				inFile.get(line);
			}
			//this sets numcount equal to decimal 
			numcount= decimal;
			//this while statement executes as lomg as numcount is greater than or equal to 1, it divides numcount by 10 and assigns the answer, then adds one to space2, this helps to ensure that
			//the decimal numbers get properly centered 
			while (numcount >= 1)
			{
				numcount /= 10;
				space2++;
			}
			//this is the equation that is used to properly center the decimal numbers
			cout << setw(36+space2/2-(space+3)/2) << decimal << endl;
		}
	//if display is equal to false, then this if statement executes
	if (display == false)
		{
			//this outputs 10 spaces(setw would not work here for some reason so I had to use spaces instead.) then output "Bad digit on input" 
			cout << "          " << "Bad digit on input" << endl;
			//while line does not equal an end of line character and is still inFile, the inFile characters are initialized
			while (line != '\n' && inFile)
			{
				inFile.get(line);
			}
		//this reverts display back to equal true
		display = true;
		}
}