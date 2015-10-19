#include <stdio.h>
#include <string.h>
#include "cryption.h"
#include "input_token.h"
#define MAXL 100

/**
 *      Add your keys by this file.
 *	Your keys consist of url, cn_name, en_name, id, key and more.
 *	You can input in English or Chinese.
 *
 *      Run "put" and then follow my hints.
 *
 *      Your keys are saved at "data.txt" in cryption.
 */


int main()
{
	FILE *out=fopen("data.txt","a+");

	char s[MAXL],ps[MAXL];
	while(1)
	{
		printf("Input your new keys:(y/n)"); scanf("%s",s); if(strcmp(s,"n")==0) break;
		printf("\turl:");	scanf("%s",s); getchar(); output_line(out,s);
		printf("\tcn_name:");	scanf("%s",s); getchar(); output_line(out,s);
		printf("\ten_name:");	scanf("%s",s); getchar(); output_line(out,s);
		printf("\tid:");	scanf("%s",s); getchar(); output_line(out,s);
		printf("\tkey:");	input_token(s); output_line(out,s);
		printf("\tmore:");	scanf("%s",s); getchar(); output_line(out,s);
	}

	fclose(out);
	return 0;
}
