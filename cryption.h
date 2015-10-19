#ifndef _CRYPTION_H
#define _CRYPTION_H

#include <stdio.h>

int input_line(FILE *in,char* s)
{
	int i;
	for(i=0;;++i)
	{
		if(fscanf(in,"%d",&s[i])==EOF) return EOF;
		if(s[i]=='\n') break;
	}
	s[i]='\0'; return 1;
}

void output_line(FILE *out,char* s)
{
	int i;
	for(i=0;s[i]!='\0';++i) fprintf(out,"%d\n",s[i]);
	fprintf(out,"%d\n",'\n');
}

#endif
