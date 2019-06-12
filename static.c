
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void test()
{
	static char *c; 
	
	c = (char*)malloc(11 * sizeof(char));
	int a = open("test", O_RDONLY);
	
	read(a, c, 5);
	printf("%s\n", c);
	free(c);
	c = (char*)malloc(11 * sizeof(char));
	read(a, c, 5);
	printf("%s", c);
}

int main()
{
	test();
	return (0);
}

