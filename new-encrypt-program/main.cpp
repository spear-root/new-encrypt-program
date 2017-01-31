//#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h" // I'll make this header file open-source later.
#include <iostream>
#include <string>
#include <vector>

#pragma warning (disable: 4996)  // Because of VS2015.

using namespace std;

string inputfile = "input.txt", outputfile = "";
bool mode_interactive;

vector<char> original;
char buf[4096 + 5];

const char str_hello[] = "Hello! Welcome to <put this program name here>!";
const char str_request_inputfile[] = "Input file name (including path) : ";
const char str_request_outputfile[] = "Output file name (Empty to assume filename.enc) : ";
const char str_processing[] = "Encrypting the file... Might take some time.";
const char str_finished[] = "Encryption is finished now!";

void parse_parm(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--interactive") == 1)
			mode_interactive = true;
		else if (strcmp(argv[i], "--non-interactive") == 1)
			mode_interactive = false;
	}
}

//Encrypt one byte of data.
inline char encrypt(const char data) {
	//TODO: Implement encryption
	return -1;
}

//Process one block(4096 bytes) of file.
void process(FILE* r, FILE* w) {
	const int size = fread((void*)buf, sizeof(char), 4096, r);

	for (register int i = 0; i<size; i++)
		buf[i] = encrypt(i);

	fwrite(buf, sizeof(char), size, w);
}

int main(int argc, char* argv[])
{
	parse_parm(argc, argv);
	if (mode_interactive) {
		cout << str_hello << endl << endl;

		cout << str_request_inputfile;
		cin.getline(buf, 4096);
		inputfile = buf;

		cout << str_request_outputfile;
		cin.getline(buf, 4096);
		outputfile = buf;
	}
	if (outputfile == "")
		outputfile = inputfile + ".enc";


	//Input
	FILE * r, *w;
	r = fopen(inputfile.c_str(), "rb");
	if (r == 0) {
		cerr << "Unable to open input file!" << endl;
		return 1;
	}
	w = fopen(outputfile.c_str(), "wb");


	//Encrypt
	cout << str_processing;
	while (!feof(r))
		process(r, w);
	cout << endl;


	//Close
	fclose(r);
	fclose(w);
	if (mode_interactive)
		cout << str_finished << endl;
	return 0;
}