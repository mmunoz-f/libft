<h1>libft</h1>

This is the first project we have to face in 42, it's a recopilation of util functions we will use in the future projects, as you can see many of these utilities can be found in standard C libraries.

This was one of my first projects so the code is not the best, also as students, we have to respect a norm to suit some prerequisites, the function should not have more than 25 lines, no more than 4 parameters, no ternarie allowed... etc.

The objective of this project was to remember the basics, and to have our own utils library for future projects as we are not allowed to use many functions from the standard libraries, we were only allowed to use a few system functions.

<h3>How to use it</h3>

As soon as you compile the work with `make`, a ".a" file will be generate, add this to your own project and when compiling use it as you where using any other external library. For example in C:

```bash
gcc main.c -L. -lft
```

After the -L flag you are supposed to add the path to the static library file (the .a file), in the example above the static library, is located on the root.

Remember to include the .h file in your code.
