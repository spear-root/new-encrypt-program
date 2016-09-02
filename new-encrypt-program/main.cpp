#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
using namespace std;

char buf[4096 + 5];
vector<char> original;

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

	int len = fread(buf, sizeof(char), 4096, r);  // 파일 크기가 4kB를 넘을 경우 for문으로 4kB씩 잘라 받는 코드 추가 예정.
	
	original.resize(len);
	// char[]에 들어있는 바이너리 데이터를 vector<char>으로 옮긴다
	for (int i = 0; i < len; i++)
	{
		original[i] = buf[i];
	}


	//TODO: Implement encrypt function.


	// Output
	w = fopen("output.txt", "wb");
	fwrite(&original[0], sizeof(char), original.size(), stdout);// w);

	fclose(r);
	fclose(w);
	return 0;
}
