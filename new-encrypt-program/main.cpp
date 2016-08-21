#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
using namespace std;

char buf[4096 + 5];

int main()
{
	FILE *r, *w;
	r = fopen("input.txt", "r");
	if (r == NULL)
	{
		_D_RED;
		perror("input.txt");
		_RESET;
		return EXIT_FAILURE;
	}

	
	fread(buf, 1, 4096, r);
	//fscanf(r, "%s", buf);
	//fgets(buf, 4096, r);

	printf("%s", buf);

	fclose(r);
	return 0;
}
