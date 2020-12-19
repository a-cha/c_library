//
// Created by Антон Чапарин on 13.12.2020.
//

#include <stdio.h>
#include "includes/libasm.h"

void 	print_list(t_list *lst)
{
	while (lst)
	{
		if ((char *)lst->data)
			printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}
}

void 	print_current(t_list *lst)
{
	if (lst->data)
		printf("curr: %s\n", (char *)lst->data);
	if (lst->next)
		printf("next: %s\n", (char *)lst->next->data);
}

int 	cmp(t_list *l1, t_list *l2)
{
	char 	*s1;
	char 	*s2;

	s1 = l1->data;
	s2 = l2->data;
	return (ft_strcmp(s1, s2));
}

int 	main()
{
	t_list	*one;
	t_list	*tmp;
	char	*str;

//	printf("%d\n", ft_atoi_base("\n    -2147483647", "0123456789"));

	one = ft_lstnew("-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "1");
	ft_list_push_front(&one, "2");
	ft_list_push_front(&one, "3");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "4");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "5");
	ft_list_push_front(&one, "-");
	ft_list_push_front(&one, "-");
//	print_list(one);
//	printf("\n");
	ft_list_remove_if(&one, "-", &ft_strcmp);
//	print_list(one);
	printf("\n");
	tmp = ft_list_sort(&one, &cmp);
	print_current(tmp);
//	print_list(one);

//	printf("%d\n", ft_list_size(one));

//	print_list(one);
//	printf("\n");
//	ft_list_push_front(&one, "hello");
//	print_list(one);

//	print_list(one);
//	printf("\n");
//	ft_list_remove_if(&one, "3", &ft_strcmp);
//	print_list(one);

//	tmp = ft_list_remove_if(&one, "1", &ft_strcmp);
//	print_current(tmp);
//	print_list(tmp);

//	printf("%d\n", ft_list_remove_if(&one, "1", &ft_strcmp));

//	str = ft_list_remove_if(&one, "2", &ft_strcmp);
//	printf("%s\n", str);

//	printf("%s\n", (char *)ft_list_remove_if(&one, "2", &ft_strcmp)->data);
}
