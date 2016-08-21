#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
using namespace std;

char buf[4096 + 5];

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
	int len = fread(buf, sizeof(char), 4096, r);
	buf[len] = NULL;

	// Output
	printf("%s", buf);

	fclose(r);
	return 0;
}
