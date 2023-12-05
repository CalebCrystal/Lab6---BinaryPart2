#include "Binary.h" // includes the header 
using namespace std; // using the std namespace 
binaryconvert::binaryconvert() // constructor
{

}

binaryconvert::~binaryconvert() {} // destructor

void binaryconvert::header() { // header function 

	cout << "Binary" << setw(20) << "Decimal" << endl; 
	//outputs the header for the lists of decimal and binary numbers 

};

int binaryconvert::convert() { // convert function 

	ifstream inFile; // opens in stream for a file
	inFile.open("Binaryln.dat"); // opens binary.dat file to be read in

	char binary; // local char variable as the binary numbers to allow to evaluate things other than numbers 
	int decimal = 0; // sets the decimal value to '0'
	bool error = false; // error bool is set to false for there being no error 
	                   // this I used for the leading spaces for when the first number was read the 
						//program would output an error if any other character besides a 1 or 0 was read in
	bool go = true; // this was another flag if somthing else triggerd a wrong input like a letter 

	if (!inFile)//verifys the file opened 
	{
		return 9999;
	}

	inFile.get(binary); // using the get function to bring in one character at a time

	do { // do while loop to encorperate all numbers in the file 


		if (binary == ' ' || binary == '\t') { // if statement for a space or tab

			if (error == false) { // the bool error all ways starts at false for each line read 
				continue;         // will continue if a number has not yet been read on that line

			}
			if (error == true) { // if a number has been read and there is a space than 
				cout << "Incorrect formating" << endl; // it out puts an error
				inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // and skips the rest of the line
				go = false; // sets go to false to skip the rest of the conversion from the line

			}
		}
		if (go == true) { // if an error in the space has not yet occured than it will continue to convert to a decimal 
			if (binary == '0' || binary == '1') { // makes sure only 1's and 0's are evaluated if not it's passed to the else

				decimal = (2 * decimal) + (binary - '0'); // this is the converter 
				cout << binary; // outputs the number of binary
				error = true; // sets error to true so if a space is found inside the binary number than it stops reading the line the  next time through
			}
		else if (binary == '\n') { // if it's a new line character and there is no error 
				if (go == true) { 
					cout << setw(20) << decimal << endl; // this outputs the decimal value 
					decimal = 0; // sets decimal to 0 for the next line 
					error = false; // resets error to false
				}
				else // anything other than a new line or a 1/0 than the line will output an error and go to the next
				{
					cout << "Incorrect formating" << endl;
					inFile.ignore(numeric_limits<streamsize>::max(), '\n');
					go = false;
				}

			}
		else { // if things go really wrong this will ensure that it stops 

				cout << "Incorrect formating" << endl;
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
				error = false;
				go = false;
				//return 9999;
			}
		}

		if (go == false) {

			decimal = 0;
			go = true;
			continue;
		}


	} while (inFile.get(binary)); // end of while loop
	cout << setw(20) << "3";
	 


	inFile.close(); // closes file
};

