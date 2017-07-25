//#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
//I'll make this header file open-source later. (It's not related anyway)
#include <iostream>
#include <string>
#include <vector>

#ifdef __MSVC__
// Probably some error. I have no idea. Ask @spear-root if wondering
#pragma warning (disable: 4996)
#endif

using namespace std;

string inputfile = "input.txt", outputfile = "";
bool mode_interactive;

vector<char> original;
char buf[4096 + 5];

const char str_hello[] = "Hello! Welcome to new-encryption-program!";
const char str_request_inputfile[] = "Input file name (including path) : ";
const char str_request_outputfile[] = "Output file name (Empty to assume filename.enc) : ";
const char str_processing[] = "Encrypting the file... Might take some time.";
const char str_finished[] = "Encryption has finished!";

/**
 * @brief Process the program's parameter
 * 
 * This function will process the paramater (a.k.a. argument) given
 * to this program. Improvements needed.
 *
 * @param argc The 'argc' variable from main function
 * @param argv The 'argv' variable from main function
 */
void parse_parm(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--interactive") == 1)
			mode_interactive = true;
		else if (strcmp(argv[i], "--non-interactive") == 1)
			mode_interactive = false;
	}
}

/**
 * @brief Encrypt one byte of data
 * 
 * This function encrypts one byte of data.
 * 
 * @param data The data to encrypt (input)
 * @param pos The position of this data in file
 * 
 * @return The encrypted byte
 *
 * @todo Remove the need of pos (I added it because @spear-root used it
 * in his older encryption program. I honestly have no idea what he's planning.)
 */
inline char encrypt(const char data, const size_t pos) {
	//TODO: Implement encryption
	return data;
}

/**
 * @brief Encrypt one block (4096 bytes) of file
 * 
 * This function encrypts one block of file by read from the file,
 * then rapidly call encrypt, then write it to the file.
 *
 * @param r The file to read from
 * @param w The file to write to
 *
 * @todo Implement multithread (parhaps by OpenMP?)
 */
void encrypt_block(FILE* r, FILE* w) {
	const int size = fread((void*)buf, sizeof(char), 4096, r);

	for (register int i = 0; i<size; i++)
		buf[i] = encrypt(buf[i], i);

	fwrite(buf, sizeof(char), size, w);
}

/// @brief main function
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
