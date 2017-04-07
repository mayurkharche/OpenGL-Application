#include <stdio.h>

int* Rec(int flag)
{
	FILE *fp = fopen("Record.dat","r");

	static int B[81];

	int ch = getc(fp);

	int i=0,f=1;


	while(ch!=EOF)
	{
		ch=ch-48;
		if(i==82 && f<flag)
		{
			i=0;f++;
		}
		else if(i==82)
			return B;
		
		B[i]=ch;
		i++;

		ch = getc(fp);
	}
	fclose(fp);

	return B;
}
