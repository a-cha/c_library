/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:36:10 by sadolph           #+#    #+#             */
/*   Updated: 2021/01/14 20:53:14 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h>
#include <unistd.h>

size_t				ft_strlen(char const *str);
char				*ft_strcpy(char * dst, const char * src);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int fildes, const void *buf, size_t nbyte);
char				*ft_strdup(const char *s1);
ssize_t				ft_read(int fildes, void *buf, size_t nbyte);

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int 				ft_atoi_base(char *str, char *base);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void				ft_list_sort(t_list **begin_list, int (*cmp)());

# endif
