/*************************************************************
Author:		John Griner
Program:	Hamming Code

Description:	This program reads in a 7-bit hamming code, checks for errors,
							and then converts the code to the corresponding
							character. The program prints out ascii art style writing.

Input:	The program requires a data file called "lab4data.dat" which
					has only a set of 7 bit hamming code sets

Output:	The only output from the program is the "ascii art" banner
**************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// begin main function
int main(){

	// array used to store symbols
	char symbols[9] = {'_', '/', '\\', '|', ' ', '*', '(', ')', '\n'};

	// string to read in hamming code
	string message;

	// stores the error place
	int hammingError;

	// stores the encoded word
	int codeWord;

	// value of the parity bits
	int parityBit1;
	int parityBit2;
	int parityBit3;

	// input file
	ifstream myInput;
	// open input file
	myInput.open("hamming_data.dat");

	// if unsuccessful file open
	if(!myInput){
		// print error to screen
		cerr << "File was not read." << endl;
		// terminate from program
		return 0;
	}

	// while not end of file
	while(!myInput.eof()){
		// read in hamming code
		myInput >> message;

		// calculate parity bit 1
		parityBit1 =	((message[0]-'0')+
									(message[2]-'0')+
									(message[4]-'0')+
									(message[6]-'0')) % 2;

		// calculate parity bit 2
		parityBit2 =	((message[1]-'0')+
									(message[2]-'0')+
									(message[5]-'0')+
									(message[6]-'0')) % 2;

		// calculate parity bit 3
		parityBit3 =   ((message[3]-'0')+
										(message[4]-'0')+
										(message[5]-'0')+
										(message[6]-'0')) % 2;

		// calculate the error position
		hammingError = parityBit1 + parityBit2*2 + parityBit3*4;

		// if an error occurred
		if(hammingError > 0){
			// if the bit is a 1
			if(message[hammingError-1] == 1+'0'){
				// change it to a 0
				message[hammingError-1] = 0+'0';
			}
			else
				message[hammingError-1] = 1+'0';	// ... ... change it to a 1
		}	// end if statement

		// calculate the code word
		codeWord = 	(message[2]-'0')*8+
								(message[4]-'0')*4+
								(message[5]-'0')*2+
								(message[6]-'0');

		// print the corresponding symbol
		cout << symbols[codeWord];
	}// end while loop

	// end main function
	return 0;
}
