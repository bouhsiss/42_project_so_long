#include"so_long.h"

void print_arr(char **arr)
{
	int i=0;
	
	while(arr[i])
	{
		printf("line %d   %s\n", i, arr[i]);
		i++;
	}
}
