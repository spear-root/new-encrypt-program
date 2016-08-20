#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.10.h"
using namespace std;

char buf[4096 + 5];

int main()
{
	FILE *r, *w;
	r = fopen("input.txt", "r");
	if (r == NULL)
	{
		_RED;
		cout << "input.txt이 존재하지 않습니다.\n";
		_RESET;
		return 0;
	}

	
	fread(buf, 1, 1, r); //fscanf(r, "%s", buf); //fgets(buf, 4096, r);

	printf("%s\n", buf);

	fclose(r);
	return 0;
}