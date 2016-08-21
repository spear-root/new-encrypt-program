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
		cout << "input.txt doesn't exist. Shutting down the program.\n";
		_RESET;
		return 0;
	}

	
	fread(buf, 1, 4096, r);
	//fscanf(r, "%s", buf);
	//fgets(buf, 4096, r);

	printf("%s\n", buf);

	fclose(r);
	return 0;
}