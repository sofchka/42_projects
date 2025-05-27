# Libft

Libft is a custom implementation of standard C library functions. This project is part of the 42 curriculum and aims to reinforce understanding of fundamental C programming concepts, including memory allocation, pointers, and string manipulation.

## Table of Contents
- [About](#about)
- [Functions](#functions)
- [Installation](#installation)
- [Usage](#usage)
- [Makefile Rules](#makefile-rules)
- [Contributing](#contributing)
- [License](#license)

## About
This project involves re-implementing several standard library functions as well as additional utility functions. The final output is a static library (`libft.a`) that can be used in future projects.

## Functions
### Part 1: Standard Library Functions
- `ft_isalpha`  - Checks if a character is alphabetic
- `ft_isdigit`  - Checks if a character is a digit
- `ft_isalnum`  - Checks if a character is alphanumeric
- `ft_isascii`  - Checks if a character is an ASCII character
- `ft_isprint`  - Checks if a character is printable
- `ft_strlen`   - Returns the length of a string
- `ft_memset`   - Fills a block of memory with a specific value
- `ft_bzero`    - Zeros out a block of memory
- `ft_memcpy`   - Copies memory from one location to another
- `ft_memmove`  - Moves memory safely (handles overlapping regions)
- `ft_strlcpy`  - Copies a string with size checking
- `ft_strlcat`  - Concatenates strings with size checking
- `ft_toupper`  - Converts lowercase letters to uppercase
- `ft_tolower`  - Converts uppercase letters to lowercase
- `ft_strchr`   - Locates a character in a string
- `ft_strrchr`  - Locates a character in a string (from the end)
- `ft_strncmp`  - Compares two strings up to a specified length
- `ft_memchr`   - Searches memory for a byte
- `ft_memcmp`   - Compares memory areas
- `ft_strnstr`  - Locates a substring in a string
- `ft_atoi`     - Converts a string to an integer
- `ft_calloc`   - Allocates memory and sets it to zero
- `ft_strdup`   - Duplicates a string

### Part 2: Additional Functions
- `ft_substr`   - Extracts a substring from a string
- `ft_strjoin`  - Concatenates two strings
- `ft_strtrim`  - Trims characters from both ends of a string
- `ft_split`    - Splits a string into an array of substrings
- `ft_itoa`     - Converts an integer to a string
- `ft_strmapi`  - Applies a function to each character of a string
- `ft_striteri` - Applies a function to each character (modifies in-place)
- `ft_putchar_fd` - Writes a character to a file descriptor
- `ft_putstr_fd`  - Writes a string to a file descriptor
- `ft_putendl_fd` - Writes a string followed by a newline
- `ft_putnbr_fd`  - Writes an integer to a file descriptor

## Installation
To compile and use `libft.a`, follow these steps:
```sh
# Clone the repository
git clone https://github.com/yourusername/libft.git
cd libft

# Compile the library
make
```

## Usage
To use `libft` in your project, include the header file and link the library:
```c
#include "libft.h"

int main() {
    char *str = "Hello, Libft!";
    printf("String length: %zu\n", ft_strlen(str));
    return 0;
}
```
Compile your program with:
```sh
gcc -Wall -Wextra -Werror main.c libft.a
```

## Makefile Rules
- `make`      - Compiles the library (`libft.a`)
- `make clean` - Removes object files (`*.o`)
- `make fclean` - Removes object files and `libft.a`
- `make re`    - Recompiles the library from scratch

