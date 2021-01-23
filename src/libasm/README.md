# Assembly library

###### _Small library written on Assembly language_

#### Contains the following functions, rewritten from Standard C Library:

- ft_strlen
- ft_strcmp
- ft_strcpy
- ft_strdup

#### System-call functions:
- ft_read
- ft_write

#### Extra functions:
- ft_atoi_base
- ft_list_push_front
- ft_list_size
- ft_list_remove_if
- ft_list_sort

Source files of extra functions are provided with 
comments, explaining how the functions works. There are also 
test files that will show how to use the Assembly library.

## Usage

Run `make` inside the repository's directory to create a 
library file. Now the `libasm.a` library at your disposal.

Run `make test` creates binary file using `libasm.a` to test it.