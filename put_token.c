#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "cryption.h"
#include "input_token.h"
#define MAXL 100

/**
 *	Set or reset your token by this file.
 *
 *	Run "put_token" and then follow my hints.
 *
 *	Your token is saved at "token.txt" in cryption.
 */

int main()
{
	char token[MAXL];
	char repeat[MAXL];

	if(access("token.txt",0))
		printf("You don't have token, please set it:");
	else
	{
		printf("You have a token, will you change it (y/n):");
		if(getchar()!='y') { printf("bye~\n"); return 0; }
		printf("Please set it:");
	}

	while(1)
	{
		input_token(token);
		printf("Repeat it:");
		input_token(repeat);
		if(strcmp(token,repeat)) { printf("they are not same, please set it again:"); continue; }
		break;
	}

	FILE *out=fopen("token.txt","w");
	output_line(out,token);
	fclose(out);

	return 0;
}
