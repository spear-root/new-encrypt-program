//#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string inputfile, outputfile;
char buf[4096];
vector<char> original;

const char str_hello[] = "Hello! Welcome to <put this program name here>!";
const char str_request_inputfile[] = "Input file name (including path) : ";
const char str_request_outputfile[] = "Output file name (Empty to assume filename.enc)";
const char str_processing[] = "Encrypting the file... Might take some time.";
const char str_finished[] = "Encryption is finished now!";

//Encrypt one byte of data.
inline char encrypt(const char data) {
	//TODO: Implement encryption
}

//Process one block(4096 bytes) of file.
void process(FILE* r, FILE* w) {
	const int size = fread((void*)buf, sizeof(char), 4096, r);
	for(register int i=0; i<size; i++)
		buf[i] = encrypt(i);
	fwrite(buf, sizeof(char), size, w);
}

int main()
{
	cout << str_hello << endl;
	cout << str_request_inputfile;
	cin.getline(buf);
	inputfile = buf;
	cout << str_request_outputfile;
	cin.getline(buf);
	outputfile = buf;
	if(outputfile == "")
		outputfile = inputfile + ".enc";
	
	//Input
	FILE * r, w;
	r = fopen(inputfile.c_str(), "rb");
	if(r==0) {
		cerr << "Unable to open input file!" << endl;
		return 1;
	}
	w = fopen(outputfile.c_str(), "wb");
	
	//Encrypt
	cout << str_processing;
	while(!feof(r))
		process(r, w);
	cout << endl;

	//Close
	fclose(r);
	fclose(w);
	cout << str_finished << endl;
	return 0;
}
