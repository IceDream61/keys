#ifndef _INPUT_TOKEN_H
#define _INPUT_TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>

static struct termios stored_settings1;
static struct termios stored_settings2;

void echo_off()
{
	struct termios new_settings;
	tcgetattr(0,&stored_settings1);
	new_settings = stored_settings1;
	new_settings.c_lflag &= (~ECHO);
	tcsetattr(0,TCSANOW,&new_settings);
}

void echo_on()
{
	tcsetattr(0,TCSANOW,&stored_settings1);
}

void input_token(char* s)
{
	echo_off();
	scanf("%s",s);
	echo_on();
	putchar('\n');
}

#endif
