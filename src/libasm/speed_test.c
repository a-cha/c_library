#include "libasm.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n = 10000000;
	char *str = "kjvfnvn;sdfnvbk;nd;kbjnpiwrnbpiunri";
	char *str1 = "kjvfnvn;sdfnvbk;nd;kbjnpiwrnbpiunr";
	char *dest = malloc(35);

	clock_t a;

	a = clock();
	// while (n--)
	// 	ft_strlen(str);
	while (n--)
		ft_strcmp(str, str1);
	// while (n--)
	// 	ft_strdup(str);
	// while (n--)
	// 	ft_strcpy(dest, str);
	
	a = clock() - a;
	printf("%f\n", ((double)a)/CLOCKS_PER_SEC);
	a = clock();
	n = 10000000;
	// while (n--)
	// 	strlen(str);
	while (n--)
		strcmp(str, str1);
	// while (n--)
	// 	strdup(str);
	// while (n--(dest, str);
	a = clock() - a;
	printf("%f\n", ((double)a)/CLOCKS_PER_SEC);
	
	return 0;
}
