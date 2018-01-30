## Homework 1

### C Exercises

Modify the link below so it points to the `ex01` directory in your
student repository.

[Here is a link to the ex01 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Determining types of variables at runtime. For example, in python:

```python
def add_nums(x, y):
    return x + y
```

There is no guarantee that x and y are both type int. They could be strings, doubles, or a mix, and this function may or may not crash. In C you have to declare the types beforehand, and then the compiler will error if you try passing a variable of the wrong type.

2) Name two advantages of static typing over dynamic typing.

1. More errors are caught at compile-time (no TypeErrors, you know what types all variable/function inputs are)
2. You can define more explicit APIs (ie, you design a set of library methods which expect certain types of inputs. You don't need to worry your user doesn't know what types your functions expects, and then passes the incorrect ones, resulting in potentially unexpected behavior.)

3) Give an example of a static semantic error.

```C
int x = 5;
double y = x;
```

4) What are two reasons you might want to turn off code optimization?

1. If your code runtime errors, the error message you get might make less sense or be harder to interpret, since the compiler has modified your code.
2. Might take longer to compile? Not sure.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Other computers may be running different OSs, have different architectures, or be running a different version of `gcc`.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

When you misspell a variable name, you get: `'c' undeclared` (I named my variable `d`). However, if you treat `c` like a function, typing `c()`, you only get a warning: `implicit declaration of function 'c'` when compiling. You get an error when linking, however. I think it's because if another object file has the declaration for `c()`, then this function will be called. So we don't know whether or not `c` is a function until we link to an executable.

7) What is a segmentation fault?

When your program tries to read/write illegal memory. Probably means you messed something up with pointers.
