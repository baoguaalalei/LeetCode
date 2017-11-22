#include <iostream>
#include <stdlib.h>
#include <string.h>

char * atoi(const char *str,int &res) {
	static char ok[] ="ok";
	static char wrong[] = "wrong";
	if(NULL == str) return wrong;

	int sign = 1, i = 0;
	res = 0;
	while (str[i] == ' ') { i++; }
	if (str[i] == '-' || str[i] == '+') {
		sign = 1 - 2 * (str[i++] == '-'); 
	}
	while (str[i] >= '0' && str[i] <= '9') {
		if (res >  INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
			if (sign == 1) 
			{
				res =INT_MAX;
				return wrong;
			}
			else
			{
				res= INT_MIN;
				return wrong;
			}
		}
		res  = 10 *res + (str[i++] - '0');
	}
	
	return ok;
}