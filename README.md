# C library
###### _My own small library_

#### Contains the following functions, rewritten from Standard C Library:
- ft_atof
- ft_atoi
- ft_atoi_base _(written in Assembly language)_
- ft_bzero
- ft_calloc
- ft_isalnum
- ft_isalpha
- ft_isascii
- ft_isdigit
- ft_isprint
- ft_memccpy
- ft_memchr
- ft_memcmp
- ft_memcpy
- ft_memmove
- ft_memset
- ft_numlens
- ft_strchr
- ft_strcmp _(written in Assembly language)_
- ft_strcpy _(written in Assembly language)_
- ft_strdup _(written in Assembly language)_
- ft_strlen _(written in Assembly language)_
- ft_strlcat
- ft_strlcpy
- ft_strncmp
- ft_strnstr
- ft_strrchr
- ft_tolower
- ft_toupper

#### Functions that work with chained lists
> ###### Provided with comments describes how to use them
- ft_lstadd_back
- ft_lstadd_front
- ft_list_push_front _(written in Assembly language)_
- ft_lstclear
- ft_lstdelone
- ft_lstiter
- ft_lstlast
- ft_lstmap
- ft_lstnew
- ft_list_remove_if _(written in Assembly language)_
- ft_list_size _(written in Assembly language)_
- ft_list_sort _(written in Assembly language)_

#### Additional functions 
> ###### Provided with comments describes how to use them
- ft_itoa
- ft_putchar_fd
- ft_putendl_fd
- ft_putnbrs_fd
- ft_putstr_fd
- ft_split
- ft_strjoin
- ft_substr
- ft_strmapi
- ft_strtrim

#### Get Next Line 
Calling function in a loop allows to read the text available on a file descriptor one line at a time until the EOF.

#### And couple of system-call functions (written in Assembly language)
- ft_read
- ft_write

## Usage

Run `make` inside the repository's directory to create a
library file. Now the `libft.a` library at your disposal.

Project's Makefile will compile the **Assembly library** by 
using its Makefile, then compile the `libft.a`
