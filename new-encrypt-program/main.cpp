//#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h" //You should open this header file is you're willing to ipen this code.
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string inputfile = "input.txt", outputfile = "";
char buf[4096];
vector<char> original;
bool mode_interactive;

const char str_hello[] = "Hello! Welcome to <put this program name here>!";
const char str_request_inputfile[] = "Input file name (including path) : ";
const char str_request_outputfile[] = "Output file name (Empty to assume filename.enc)";
const char str_processing[] = "Encrypting the file... Might take some time.";
const char str_finished[] = "Encryption is finished now!";

void parse_parm(int argc, char* argv[]) {
	for (int i = 1; i<argc; i++) {
		if (strcmp(argv[i], "--interactive") == 1)
			mode_interactive = true;
		else if (strcmp(argv[i], "--non-interactive") == 1)
			mode_interactive = false;
	}
}

//Encrypt one byte of data.
inline char encrypt(const char data) {
	//TODO: Implement encryption
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
		cout << str_hello << endl;
		cout << str_request_inputfile;
		cin.getline(buf);
		inputfile = buf;
		cout << str_request_outputfile;
		cin.getline(buf);
		outputfile = buf;
	}
	if (outputfile == "")
		outputfile = inputfile + ".enc";

	//Input
	FILE * r, w;
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