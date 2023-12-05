//Caleb Crystal 
//lab - 6 Binary 
/*Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings. Here is a sample of the input and output:*/



#include "Binary.h" // includes header file


int main() {
	binaryconvert b; // the class binary convert

	b.header(); // calls the header function to output the header 
	b.convert(); // call the function to convert the binary to decimal
	// also formats the display

	return 0;
};