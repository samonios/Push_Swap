*This project has been created as part of the 42 curriculum by niesteba.*

# Libft - 42 Project

## Description
Libft is the very first project in the 42 school curriculum. Its objective is to create a custom C library that implements many of the standard C library functions, alongside other utility functions that will be used repeatedly throughout the rest of the curriculum.

Since standard functions are often forbidden in 42 projects, this library serves as a fundamental building block for future assignments. By rewriting these standard `libc` functions from scratch, students gain a deep understanding of data structures, memory management, and algorithm optimization in C.

## Library Details
This library contains several categories of functions:

### 1. Libc Functions
These are recreations of standard C library functions. 
*   **Character checks & manipulation:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
*   **Memory manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
*   **String manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
*   **Memory allocation:** `ft_calloc`
*   **Type conversion:** `ft_atoi`, `ft_strdup`

### 2. Additional Functions
These are utility functions not found in the standard libc but highly useful for string and memory handling.
*   **String generation/modification:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
*   **File Descriptor operations (Output):** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 3. Linked Lists Functions
A set of functions designed to manipulate a custom linked list structure (`t_list`).
*   **List operations:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

### Compilation
The project includes a `Makefile` to compile the library. The compiler used is `cc` with the standard 42 flags (`-Wall -Wextra -Werror`).

To compile the standard and additional functions, run:
```bash
make
```
This will generate the `libft.a` static library file.

**Other Makefile rules:**
*   `make clean`: Removes all `.o` (object) files.
*   `make fclean`: Removes object files and the compiled `libft.a` library.
*   `make re`: Cleans the repository and recompiles the library from scratch.

### Usage
To use this library in your own projects, include the header file in your C files:
```c
#include "libft.h"
```
Then, compile your project along with the library:
```bash
cc my_program.c -L. -lft -o my_program
```

## Resources
*   **Documentation:** 
    *   Linux Programmer's Manual (`man` commands in terminal, e.g., `man 3 memset`).
    *   [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)
*   **Use of AI:**
    *   Gemini was used occasionally to test the code and to help generate this descriptive `README.md` layout.
	*	No AI was used to directly write or copy-paste the core logic of the functions, preserving the educational integrity of the project.
