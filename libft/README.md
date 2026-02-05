*This project has been created as part of the 42 curriculum by hahel.*

## Description

This project is a custom C library called libft that reimplements a selection of standard C functions and adds useful utility functions for future 42 projects.
It helps build a solid foundation in C by making you understand how common functions work internally and by encouraging clean, reusable code design.

## Instructions

To compile the library:
1. Clone the repository
2. Navigate to the project directory
3. Run `make` to compile the library
4. This will create `libft.a`

Additional Makefile rules:
- `make clean` - removes object files
- `make fclean` - removes object files and the library
- `make re` - recompiles everything from scratch

To use libft in another project:
1. Include the header in your C file: `#include "libft.h"`
2. Compile with: `gcc your_file.c -L. -lft`

## Resources

- [W3Schools C Tutorial](https://www.w3schools.com/c/) - Basic C syntax and string functions
- [GeeksforGeeks C Programming](https://www.geeksforgeeks.org/c-programming-language/) - Examples and explanations of standard library functions
- [Stack Overflow](https://stackoverflow.com/) - Community solutions for debugging specific issues
- Man pages: `man malloc`, `man memcpy`, `man strlen`, and other standard C functions in part 1

**AI Usage:**
AI was used to learn about testing methodologies and understand how to properly test each function. All function implementations were written independently based on understanding gained from the resources listed above.
