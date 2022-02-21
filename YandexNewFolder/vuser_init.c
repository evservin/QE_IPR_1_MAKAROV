#include <time.h>
#include <stdio.h>

int x = -1;
int curSec = -1;

vuser_init()
{   
	int x = atoi(lr_eval_string("{num}"));
	return 0;
}

int showCurrentSecDigit(int digit){
		
	return (time(NULL)%(24*60*60) + digit);
	}