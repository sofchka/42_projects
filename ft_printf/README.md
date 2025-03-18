# ft_printf

## 📌 Overview

`ft_printf` is a custom implementation of the standard `printf` function in C. It mimics the original `printf` by handling various format specifiers and outputting formatted strings. This project is part of the 42 school curriculum and aims to deepen understanding of variadic functions and formatted output.

## 📜 Subject Requirements
- The project must be written in C following the 42 Norm.
- No memory leaks allowed—heap allocations must be properly freed.
- The program should not produce segmentation faults, bus errors, or double frees.
- The function `ft_printf()` should behave similarly to `printf()` but without buffer management.
- The following format specifiers must be implemented:
  - `%c` → Prints a single character.
  - `%s` → Prints a string.
  - `%p` → Prints a pointer in hexadecimal format.
  - `%d` & `%i` → Prints an integer (base 10).
  - `%u` → Prints an unsigned integer (base 10).
  - `%x` & `%X` → Prints a number in hexadecimal (lowercase & uppercase).
  - `%%` → Prints a percent sign.

## 🛠️ Installation & Usage

### 1️⃣ Compilation
```sh
make
```
This will generate `libftprintf.a`, a static library that you can link in your programs.

### 2️⃣ Using `ft_printf`
You can include `ft_printf.h` and compile it with your code:
```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! The number is %d.\n", "World", 42);
    return 0;
}
```
Compile with:
```sh
cc main.c libftprintf.a
```

## ⚠️ Limitations
🚫 Does not support all `printf` features (e.g., floating points, width, precision, flags)
🚫 No buffer management like the original `printf`
