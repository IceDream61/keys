#include <stdio.h>
#include <string.h>
#include "input_token.h"
#include "cryption.h"
#define MAXL 100
#define MAXN 100
typedef char str[MAXL];

/**
 *      Search your keys by this file (with your token).
 *	You can just input any words which in the url, cn_name or cn_name of your keys.
 *	Then this program will search it for you.
 *
 *      Run "get" and then follow my hints.
 *	You also can input "-q" to quit and "-cls" to clear your terminal screen.
 *
 *      Your token is saved at "token.txt" in cryption.
 */

struct Data
{
	str url;
	str cn_name;
	str en_name;
	str id;
	str key;
	str more;
};

int N;
struct Data all[MAXN];
str TOKEN;

void Input()
{
	char c;
	str password;
	FILE *in=fopen("token.txt","r");
	input_line(in,TOKEN);
	fclose(in);

	in=fopen("data.txt","r");
	N=0;
	while(input_line(in,all[N].url)!=EOF)
	{
		input_line(in,all[N].cn_name);
		input_line(in,all[N].en_name);
		input_line(in,all[N].id);
		input_line(in,all[N].key);
		input_line(in,all[N].more);
		++N;
	}
	fclose(in);
}

int contains(str s,char* S)
{
	int i,l=strlen(s);
	for(i=0;i!=l;++i)
		if(s[i]!=S[i]) return 0;
	return 1;
}

int contain(int i,str s)
{
	int j=0;
	int l,ls=strlen(s);

	l=strlen(all[i].url);
	for(j=0;j+ls<=l;++j)
		if(contains(s,all[i].url+j)) return 1;

	l=strlen(all[i].cn_name);
	for(j=0;j+ls<=l;++j)
		if(contains(s,all[i].cn_name+j)) return 1;

	l=strlen(all[i].en_name);
	for(j=0;j+ls<=l;++j)
		if(contains(s,all[i].en_name+j)) return 1;

	return 0;
}

void print(int i)
{
	printf("%s %s %s\n",all[i].cn_name,all[i].en_name,all[i].url);
	printf("\tid = %s\n",all[i].id);
	printf("\tkey = %s\n",all[i].key);
	printf("\tmore = %s\n",all[i].more);
}

int test_token()
{
	str token;

	printf("Input your TOKEN: ");
	input_token(token);

	if(strcmp(token,TOKEN)) { printf("Beat you!\n"); return 0; }

	return 1;
}

int Work()
{
	str s,token;
	printf("\nkeyword: "); scanf("%s",s); getchar();
	if(strcmp(s,"-q")==0) return 0;
	if(strcmp(s,"-cls")==0) { system("clear"); return 1; }
	if(test_token()==0) return 1;

	int i;
	for(i=0;i!=N;++i)
		if(contain(i,s)) print(i);

	return 1;
}

int main(int argc,char* argv[])
{
	printf("Input .."); Input(); printf("OK\n");
	int i;
//	for(i=0;i!=N;++i) print(i);
	while(Work());
	printf("Bye~\n");
	return 0;
}

