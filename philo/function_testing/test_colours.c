#include <stdio.h>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define COLOUR "\033[0m"

int main()
{
	char *str = "HELLO\n";

	printf(GREEN "%s" COLOUR, str);
	printf(RED "%s" COLOUR, str);
}
