#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
using namespace std;

char buf[4096 + 5];
vector<char> original;

void encrypt()
{
	// Write the code
}

void decrypt()
{
	// Write the code
}

int main()
{
	// Input
	FILE *r, *w;
	r = fopen("input.txt", "rb");
	if (r == NULL)
	{
		_D_RED;
		perror("input.txt");
		_RESET;
		return EXIT_FAILURE;
	}

	//for (asdf)  // ���� ũ�Ⱑ 4kB ���� ��� for������ 4kB�� �߶� �޴� �ڵ� �߰� ����.
	{
		int len = fread(buf, sizeof(char), 4096, r);

		original.resize(len);
		// char[]�� ����ִ� ���̳ʸ� �����͸� vector<char>���� �ű��
		for (int i = 0; i < len; i++)
		{
			original[i] = buf[i];
		}
	}


	// Encrypt
	//encrypt();


	// Decrypt (for Debug)
	//decrypt();


	// Output
	w = fopen("output.txt", "wb");
	fwrite(&original[0], sizeof(char), original.size(), stdout);// w);

	fclose(r);
	fclose(w);
	return 0;
}
