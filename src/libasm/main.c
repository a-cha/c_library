#include "includes/libasm.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>

int		main(void)
{
	char *small = "Hello";
	char *smalln = "Hello\n";
	char *big2016 = "Hello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg";
	char *dst;
	int fd;

	printf("\n=====  TEST STRLEN  =====\n");
	printf("\nSmall\n");
	printf("My:\t%zu\n", ft_strlen(small));
	printf("Std:\t%zu\n", strlen(small));
	printf("\nBig2016\n");
	printf("My:\t%zu\n", ft_strlen(big2016));
	printf("Std:\t%zu\n", strlen(big2016));
	printf("\nEmpty\n");
	printf("My:\t%zu\n", ft_strlen(""));
	printf("Std:\t%zu\n", strlen(""));

	printf("\n\n=====  TEST READ  =====\n");
	fd = open("test", O_RDWR);
	dst = malloc(6);
	dst[5] = 0;
	printf("\nStdin\n");
	printf("My:\treturn: %ld\tbuf: %s\terrno: %d\n", ft_read(0, dst, 5), dst, errno);
	free(dst);
	dst = NULL;
	dst = malloc(6);
	dst[5] = 0;
	printf("Std:\treturn: %ld\tbuf: %s\terrno: %d\n", read(0, dst, 5), dst, errno);
	free(dst);
	dst = NULL;
	dst = malloc(6);
	dst[5] = 0;
	printf("\nError fd\n");
	printf("My:\treturn: %ld\tbuf: %s\terrno: %d\n", ft_read(-1, dst, 5), dst, errno);
	free(dst);
	dst = NULL;
	dst = malloc(6);
	dst[5] = 0;
	printf("Std:\treturn: %ld\tbuf: %s\terrno: %d\n", read(-1, dst, 5), dst, errno);
	free(dst);
	dst = NULL;
	dst = malloc(6);
	dst[5] = 0;
	printf("\nFile\n");
	printf("My:\treturn: %ld\tbuf: %s\terrno: %d\n", ft_read(fd, dst, 5), dst, errno);
	free(dst);
	dst = NULL;
	dst = malloc(6);
	dst[5] = 0;
	printf("Std:\treturn: %ld\tbuf: %s\terrno: %d\n", read(fd, dst, 5), dst, errno);
	close(fd);

/*
	printf("\n\n=====  TEST WRITE  =====\n");
	sleep(1);
	fd = open("test", O_RDWR);
	printf("\nStdout\n");
	printf("My:\treturn: %ld\n", ft_write(1, smalln, ft_strlen(smalln)));
	printf("Std:\treturn: %ld\n", write(1, smalln, ft_strlen(smalln)));
	printf("\nError fd\n");
	printf("My:\treturn: %ld\terrno: %d\n", ft_write(-1, "a", 1), errno);
	printf("Std:\treturn: %ld\terrno: %d\n", write(-1, "a", 1), errno);
	printf("\nFile\n");
	printf("My:\treturn: %ld\terrno: %d\n", ft_write(fd, small, ft_strlen(small)), errno);
	printf("Std:\treturn: %ld\terrno: %d\n", write(fd, small, ft_strlen(small)), errno);
	close(fd);
*/

	printf("\n\n===== TEST STRCMP =====\n");
	printf("\nEqual\n");
	printf("My:\t%d\n", ft_strcmp(small, small));
	printf("Std:\t%d\n", strcmp(small, small));
	printf("\nGreather\n");
	printf("My:\t%d\n", ft_strcmp("abc", "abe")); // -2
	printf("Std:\t%d\n", strcmp("abc", "abe"));
	printf("\nLower\n");
	printf("My:\t%d\n", ft_strcmp("abe", "aba")); // 4
	printf("Std:\t%d\n", strcmp("abe", "aba"));

	printf("\n\n=====  TEST STRCPY  =====\n");
	printf("\nSmall\n");
	free(dst);
	dst = NULL;
	dst = malloc(6);
	printf("My:\t%s\n", ft_strcpy(dst, small));
	free(dst);
	dst = NULL;
	dst = malloc(6);
	printf("Std:\t%s\n", strcpy(dst, small));
	printf("\nBig2016\n");
	free(dst);
	dst = NULL;
	dst = malloc(2017);
	printf("My:\t%s\n", ft_strcpy(dst, big2016));
	free(dst);
	dst = NULL;
	dst = malloc(2017);
	printf("Std:\t%s\n", strcpy(dst, big2016));
	printf("\nEmpty\n");
	free(dst);
	dst = NULL;
	dst = malloc(1);
	printf("My:\t%s\n", ft_strcpy(dst, ""));
	free(dst);
	dst = NULL;
	dst = malloc(1);
	printf("Std:\t%s\n", strcpy(dst, ""));

	printf("\n\n=====  TEST STRDUP  =====\n");
	printf("\nSmall\n");
	printf("My:\t%s\n", (smalln = ft_strdup(small)));
	printf("Std:\t%s\n", (small = strdup(small)));
	printf("Check malloc (str[0] = 'L')\n");
	smalln[0] = 'L';
	printf("My:\t%s\n", smalln);
	small[0] = 'L';
	printf("Std:\t%s\n", small);
	printf("\nBig2016\n");
	printf("My:\t%s\n", ft_strdup(big2016));
	printf("Std:\t%s\n", strdup(big2016));
	printf("\nEmpty\n");
	printf("My:\t%s\n", (small = ft_strdup("")));
	printf("My len:\t%zu\n", ft_strlen(small));
	printf("Std:\t%s\n", (small = strdup("")));
	printf("Std len:%ld\n", strlen(small));

	return(0);
}
