#include <stdio.h>
#include <string.h>
#define MAXLINE 10000
#define COMMENTEND " */\n"
#define COMMENTBEGIN "/**\n"

void make_readme(FILE *in,FILE *out,char* title)
{
	int p=0;
	char line[MAXLINE];

	fprintf(out,"File name: %s\n",title);
	while(fgets(line,MAXLINE,in)!=NULL)
	{
		if(p==0 && strcmp(line,COMMENTBEGIN)==0) p=1;
		if(p==1)
		{
			fprintf(out,"%s",line);
		}
		if(p==1 && strcmp(line,COMMENTEND)==0) p=0;
	}
	fprintf(out,"Comment end.\n\n");
}

int main()
{
	FILE *in,*out=fopen("readme","w");

	fprintf(out,"Okay, you can use this code -- \"keys\".\n");
	fprintf(out,"You can know how to use it by these commets:\n\n");

	fprintf(out,"Warning!!\n");
	fprintf(out,"\tIf you use \"make clean\" to uninstall this code,\n");
	fprintf(out,"\tyou will delete \"token.txt\" and \"data.txt\".\n\n");

	in=fopen("put_token.c","r"); make_readme(in,out,"put_token.c"); fclose(in);
	in=fopen("put.c","r"); make_readme(in,out,"put.c"); fclose(in);
	in=fopen("get.c","r"); make_readme(in,out,"get.c"); fclose(in);

	fclose(out);
	return 0;
}
