# Libft
<br>

>This project is the first project as a student at 42. It is about coding a `C library`. It will contain a lot of **general purpose functions** your programs will rely upon.
<br>

## ✅ Mandatory part

- To begin, you must redo a set of functions from the `libc`. Your functions will have the same prototypes and implement the same behaviors as the originals. They must comply with the way they are defined in their manual.

- In the second part, you must develop a set of functions that are either not in the `libc`, or that are part of it but in a different form.
<br>

### Libc Functions:

| Function | Description |
| :------: | :---------: |
| [`ft_isalpha`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_isalpha.c) | The `isalpha()` function checks whether the character is alphabetic or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isdigit`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_isdigit.c) | The `isdigit()` function checks whether the character is digit `0 - 9` or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isalnum`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_isalnum.c) | The `isalnum()` function checks whether the character is alphanumeric or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isascii`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_isascii.c) | The `isascii()` function checks whether the character is `ASCII` character or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_isprint`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_isprint.c) | The `isprint()` function checks whether the character is printable (including space) or not and returns a non-zero value if the character falls into the tested class, and zero if not. |
| [`ft_tolower`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_tolower.c) | The `tolower()` function converts uppercase letters to lowercase and returns the converted letter. |
| [`ft_toupper`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_toupper.c) | The `toupper()` function converts lowercase letters to uppercase and returns the converted letter. |
| [`ft_strlen`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strlen.c) | The `strlen()` function calculates the length of the string pointed to by `s`, excluding the terminating null byte `'\0'` and returns the length. |
| [`ft_strchr`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strchr.c) | The `strchr()` function returns a pointer to the first occurrence of the character `c` in the string `s`. |
| [`ft_strrchr`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strrchr.c) | The `strrchr()` function returns a pointer to the last occurrence of the character `c` in the string `s`. |
| [`ft_strncmp`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strncmp.c) | The `strncmp()` function compares the two strings `s1` and `s2`, at most `n` bytes, and returns an integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2`. |
| [`ft_strnstr`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strnstr.c) | The `strnstr()` function locates the first occurrence of the null-terminated string `little` in the string `big`, where not more than `n` characters are searched. If `little` is an empty string, `big` is returned; if `little` occurs nowhere in `big`, `NULL` is returned; otherwise, a pointer to the first character of the first occurrence of `little` is returned. |
| [`ft_strlcpy`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strlcpy.c) | The `strlcpy()` function copies up to size - 1 characters from the NUL-terminated string `src` to `dst` and returns the total length of the string they tried to create. |
| [`ft_strlcat`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strlcat.c) | The `strlcat()` function appends the NUL-terminated string `src` to the end of `dst` and returns the total length of the string they tried to create. |
| [`ft_atoi`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_atoi.c) | The `atoi()` function converts the initial portion of the `string` pointed to by `nptr` to `int` and returns the converted value. |
| [`ft_calloc`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_calloc.c) | The `calloc()` function allocates memory for an array of `nmemb` elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero. |
| [`ft_bzero`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_bzero.c) | The `bzero()` function erases the data in the `n` bytes of the memory starting at the location pointed to by `s`, by writing zeros (bytes containing `'\0'`) to that area. |
| [`ft_strdup`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strdup.c) | The `strdup()` function returns a pointer to a new string which is a duplicate of the string `s`. Memory for the new string is obtained with `malloc(3)`, and can be freed with `free(3)`. |
| [`ft_memset`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_memset.c) | The `memset()` function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c` and returns a pointer to the memory area `s`. |
| [`ft_memchr`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_memchr.c) | The `memchr()` function scans the initial `n` bytes of the memory area pointed to by `s` for the first instance of `c` and returns a pointer to the matching byte or `NULL` if the character does not occur in the given memory area. |
| [`ft_memcmp`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_memcmp.c) | The `memcmp()` function compares the first `n` bytes of the memory areas `s1` and `s2` and returns an integer less than, equal to, or greater than zero if the first `n` bytes of `s1` is found, respectively, to be less than, to match, or be greater than the first n bytes of `s2`. |
| [`ft_memcpy`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_memcpy.c) | The `memcpy()` function copies `n` bytes from the memory area `src` to memory area `dest` and returns a pointer to `dest`. The memory areas must not overlap. |
| [`ft_memmove`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_memmove.c) | The `memmove()` function copies `n` bytes from memory area `src` to memory area `dest` and returns a pointer to `dest`. The memory areas may overlap. |
<br>

### Aditional Functions:

| Function | Description |
| :------: | :---------: |
| [`ft_putchar_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_putchar_fd.c) | The `putchar()` function outputs the character `c` to the given file descriptor. |
| [`ft_putstr_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_putstr_fd.c) | The `putstr()` function outputs the string `s` to the given file descriptor. |
| [`ft_putendl_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_putendl_fd.c) | The `putendl()` function outputs the string `s` to the given file descriptor followed by a newline. |
| [`ft_putnbr_fd`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_putnbr_fd.c) | The `putnbr()` function outputs the integer `n` to the given file descriptor. |
| [`ft_itoa`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_itoa.c) | The `itoa()` function allocates (with `malloc(3)`) and returns a string representing the integer received as an argument. |
| [`ft_strjoin`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strjoin.c) | The `strjoin()` function allocates (with `malloc(3)`) and returns a new string, which is the result of the concatenation of `s1` and `s2`. |
| [`ft_strtrim`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strtrim.c) | The `strtrim()` function allocates (with `malloc(3)`) and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string. |
| [`ft_split`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_split.c) | The `split()` function allocates (with `malloc(3)`) and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. |
| [`ft_substr`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_substr.c) | The `substr()` function allocates (with `malloc(3)`) and returns a substring from the string `s`. |
| [`ft_striteri`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_striteri.c) | The `striteri()` function applies the function `f` on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to `f` to be modified if necessary. |
| [`ft_strmapi`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_strmapi.c) | The `strmapi()` function applies the function `f` to each character of the string `s`, and passing its index as the first argument to create a new string (with `malloc(3)`) resulting from successive applications of `f`. |
<br>

## ⭐ Bonus

- Functions to manipulate memory and strings are very useful. But you will soon discover that manipulating `lists` is even more useful.
- You have to use the following structure to represent a `node` of your list:

```C
typedef	struct	s_list
{
	void		*content;
	struct	s_list	*next;
}			t_list;

```
<br>

### Bonus Functions:

| Function | Description |
| :------: | :---------: |
| [`ft_lstnew`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstnew_bonus.c) | The `lstnew()` function allocates (with `malloc(3)`) and returns a new node. |
| [`ft_lstadd_front`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstadd_front_bonus.c) | The `lstadd_front()` function adds the node `new` at the  beginning of the list. |
| [`ft_lstadd_back`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstadd_back_bonus.c) | The `lstadd_back()` function adds the node `new` at the end of the list. |
| [`ft_lstsize`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstsize_bonus.c) | The `lstsize()` function counts the number of nodes in a list. |
| [`ft_lstlast`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstlast_bonus.c) | The `lstlast()` function returns the last node of the list. |
| [`ft_lstdelone`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstdelone_bonus.c) | The `lstdelone()` function takes as a parameter a node and frees the memory of the node’s content using the function `del` given as a parameter and free the node. |
| [`ft_lstclear`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstclear_bonus.c) | The `lstclear()` deletes and frees the given node and every successor of that node, using the function `del`and `free(3)`. |
| [`ft_lstiter`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstiter_bonus.c) | The `lstiter()` function iterates the list `lst` and applies the function `f` on the content of each node. |
| [`ft_lstmap`](https://github.com/daniele-frade/42sp-cursus/blob/main/01_libft/src/ft_lstmap_bonus.c) | The `lstmap()` function iterates the list `lst` and applies the function `f` on the content of each node and creates a new list resulting from the successive applications of the function `f`. |
