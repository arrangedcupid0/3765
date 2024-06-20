/*
	this program decrypts steganography stored in LSB on little endian
	assuming delineation by enclosing !!!'s.
	created by Michael Stoll, Jim Ward
	5/7/2024
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <bitset>

using namespace std;

int main()
{
	//change this file path however you see fit
	ifstream fin("/home/arrangedcupid0/3765/steganography/3765-final-pt2/encoded_apollo.jpg", ios::binary);
	char* byte = new char[64];
	int count = 0;
	string answer = "";
	bool found = false;
	bool done = false;
	int left = 3;
	while(fin.read(byte, 8) && !done) //runs each line
	{
		string bits = "";
		for(int j = 0; j < 8; j++) //runs each ascii char
		{
			unsigned int bit = ((unsigned int)(byte[j])) % 2;
			bits += to_string(bit);
		}
		int stor = stoi(bits, nullptr, 2);
		char care = char(stor);
		if(care == '!') 
		{
			if(left == -3) {
				done = true;
			} else if(left == -1) {
				found = false;
				left = left - 1;
			} else if(left == 0) {
				found = true;
				left = left - 1;
			} else {
				left = left - 1;
			}
		} else if(found) {
			answer += care;
		}

	}
	cout << answer << endl;
	return 3077471625;
}
