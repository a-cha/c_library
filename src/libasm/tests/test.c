#include "../includes/libasm.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>

void 	print_list(t_list *lst)
{
	while (lst)
	{
		if ((char *)lst->data)
			printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}
}

int 	cmp(t_list *l1, t_list *l2)
{
	char 	*s1;
	char 	*s2;

	s1 = l1->data;
	s2 = l2->data;
	return (ft_strcmp(s1, s2));
}

int		main(void)
{
	char *small = "Hello";
	char *smalln = "Hello\n";
	char *big2016 = "Hello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg[qoime[woifnvinsdpbinpiuwhpiwenpvjnwnvs nHello sldfnovishfiunsid fnvsf nobingsibnsi bindf inpginfdspnbvpi dsnfibnosd igjg";
	char *dst;
	int fd;
	t_list	*one;

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
	fd = open("tests/test_read_write", O_RDWR);
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

	printf("\n\n=====  TEST WRITE  =====\n");
	sleep(1);
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

	printf("\n\n==========================\n");
	printf("======  TEST BONUS  ======\n");
	printf("==========================\n");

	printf("\n====  TEST ATOI_BASE  ====\n");
	printf("%s = %d\n", "1111011 b2", ft_atoi_base("1111011", "01"));
	printf("%s = %d\n", "11120 b3", ft_atoi_base("11120", "012"));
	printf("%s = %d\n", "173 b8", ft_atoi_base("173", "01234567"));
	printf("%s = %d\n", "-173 b8", ft_atoi_base("-173", "01234567"));
	printf("%s = %d\n", "123 b10", ft_atoi_base("123", "0123456789"));
	printf("%s = %d\n", "-123 b10", ft_atoi_base("-123", "0123456789"));
	printf("%s = %d\n", "7B b16", ft_atoi_base("7B", "0123456789ABCDEF"));
	printf("%s = %d\n", "7b b16", ft_atoi_base("7b", "0123456789abcdef"));
	printf("invalid base: %d\n", ft_atoi_base("123", "0123456a789"));

	printf("\n\n======  TEST LISTS  ======\n");
	printf("push front:\n");
	one = malloc(0);
	one = NULL;
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "0");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "1");
	ft_list_push_front(&one, "2");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "4");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "3");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	print_list(one);
	printf("\nsize: %d\n", ft_list_size(one));
	ft_list_remove_if(&one, "-", &ft_strcmp);
	printf("\nremove_if:\n");
	print_list(one);
	printf("\nsize: %d\n", ft_list_size(one));
	ft_list_sort(&one, &cmp);
	printf("\nsort:\n");
	print_list(one);
	printf("\nempty lst size: %d\n", ft_list_size(NULL));

	return(0);
}
