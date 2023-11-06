# Data Activity 3: Operators and Masking

Folder: `3-operators-masking`

In this activity, you will:
- Create a C source code file
- Update a Makefile to build more than one executable

### What should a Makefile do?

For all of your code in this course, we expect to be able to type the following
in your directory and build all of the code at once:

  make clean

  make all
  
You will work on ensuring this in this activity. Recall that Makefiles require a
tab character before a command under a given target, not spaces. If you have
trouble getting your Makefile to work and it *looks* correct, start by checking
whether you have a tab or spaces!

### Note: included files `binary_convert.c`, `binary_convert.h`

To assist with checking the values resulting from the operations that you will
attempt in these problems, we have included files called `binary_convert.c`  and
`binary_convert.h` from Data Activity 1, which have functions that return a
string with the binary representation of a given C integral data type value. 


## 1: Bit-wise vs. logical operators

**Code file you create:** `bit_logical.c`

Create a new C code file named `bit_logical.c`. Use examples from past code
files to help determine the syntax of your headers and main function.

You will observe the difference between the bit-wise operators (&, |, and ~) and
the logical operators (&&, ||, !) by writing code that uses both. 

Note the section on `assert()` below--we use these in C to test that our code
functions, and implementing a testing suite is part of your first homework
assignment. Use them in this activity to check that you have correctly computed
the results of each operation.

### Problem Definition

Suppose `x` and `y` are **unsigned single bytes** that have the values 0x66 and
0x39 respectively. Consider what the result of the following operations are and
verify them in a main function.

<table border="0"> <tr> <th>Expression</th> <th>Value</th> </tr> <tr> <td>x &
y</td> <td></td> </tr> <tr> <td>x | y</td> <td></td> </tr> <tr> <td>~x | ~y</td>
<td></td> </tr> <tr> <td>x & !y</td> <td></td> </tr> <tr> <td>x && y</td>
<td></td> </tr> <tr> <td>x || y</td> <td></td> </tr> <tr> <td>!x || !y</td>
<td></td> </tr> <tr> <td>x && ~y</td> <td></td> </tr> </table>

### `printf` output format 

You could start by using the functions in `binary_convert.h/c` to print the
bytes and the operation so that you can see each bitwise operation result along
with its hex value:

```
0110 0110 & 
0011 1001 
---------
0010 0000     20

0110 0110 | 
0011 1001 
--------- 
0111 1111     7f

1001 1001 | 
1100 0110 
--------- 
1101 1111     df
```

Then practice adding asserts along with the prints of the results, as explained
below. 

### Using assertions in C

[This tutorial](http://ptolemy.eecs.berkeley.edu/~johnr/tutorials/assertions.html) provides an overview of how to use assert statements.

We can use assertions to test whether the result of executing our code is what
we expect. This is helpful when running a large number of tests, where we don't
want to deal with a hundred or more lines of printed output.

An example of an assert statement in code is as follows:

```
  #include <assert.h>

  int main() { 

      // set-up code omitted //

    result = x && y;
    //assert(result == 0x1);  // this should pass
    assert(result == 0);  // this should fail

    return 0;  // signifies program completed successfully 
  }
```

Try this with your own code: note that when the assertion fails, you get a
message with a line number of the code, and when the assertion passes, the code
continues to execute.

Using asserts is a good way of testing your code functionality, and it is
expected practice for your homework assignments.

### Notes

- Place your name and a description of your code in a comment at the top of your
  source file
- `main()` should return 0 when it completes successfully
- Watch your types! Which are the correct ones for `x` and `y`, below?
- You can use print statements and functions from `binary_convert.c` as you work
  on your code, but the final submission must use assertions

As you work, please note that there is typically no need to 'clean' each time
you use make. **The beauty and wonder of make is that it knows when a .c or .h
file has changed and that the program needs to be re-compiled.** Therefore, you
simply need to type `make` by itself after you have changed a .c or .h file.

## 2: Shifting

**target executable program name for Makefile:** 
shifts 

**provided starter code:** `shifts.c`

In this part, you will see the results of shifting unsigned and signed numbers.
Make sure that your function works for both signed and unsigned one-byte
values. This is taken from practice problem 2.16 in your book.

You are adding this target to your existing Makefile, rather than writing a new
one. Makefiles can handle building multiple separate executables; which parts of
the file will need to change in order for this executable to be built? Use the
existing target as an example.

### Problem Definition

There is initial code in `shifts.c` to model the code you will write, examining
different shift operations on single-byte quantities. Practice on paper: convert
each value from hexadecimal to binary, perform the shit, and convert back to
hex.

<table> <tr> <td>x</td> <td></td> <td>x&lt&lt3</td> <td></td> <td>Logical
x>>2</td> <td></td> <td>Arithmetic y>>2</td> <td></td> </tr> <tr> <td>Hex</td>
<td>Binary</td> <td>Hex</td> <td>Binary</td> <td>Hex</td> <td>Binary</td>
<td>Hex</td> <td>Binary</td> </tr> <tr> <td>0xC3</td> <td></td> <td></td>
<td></td> <td></td> <td></td> <td></td> <td></td> </tr> <tr> <td>0x75</td>
<td></td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td> </tr> <tr>
<td>0x87</td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
<td></td> </tr> <tr> <td>0x66</td> <td></td> <td></td> <td></td> <td></td>
<td></td> <td></td> <td></td> </tr> </table>

This example is not as much as test as it is an observation of how shifting
works. However, as in the previous example, you could use asserts to test if you
understand what the result from a shift should be.

### Work smart

You probably are considering a lot of cutting and pasting of code for each of
the examples that you chose to try. Instead, develop a function that can take in
x and y and essentially does what the first example code does. Then call that
function. You will need to add a function declaration at the top of your file
for your new function.

### Work smarter

Improve your helper function to have it take in 2 more parameters: how much to
shift left and how much to shift right.

## 3: Masking of bits

**target executable program name for Makefile:** 
mask 

**provided starter code:** `mask.c`

Now let's try working with masks, which are bit patterns, typically of a series of ones followed by a series of zeros, or vise versa, or all ones and all zeroes.  

### Problem Definition

Given an unsigned int x and an unsigned int y, determine the C expression that
will yield an unsigned int consisting of the least significant byte of x and the
remaining bytes of y.

Write a function to produce this result and test it with several different
inputs of x and y. Your function should return the result. Put your code in a
the C file called `mask.c`.

The approach to this problem is to consider what the binary representation is
for integers like 0xFF. You should make an unsigned int called `mask` and use it
with the bitwise operators & and | and x and y in your expression. You should
not use bit-shifting for this task.

Test your function on several values in `main()`. Don't forget our mantra about
testing: try 0, 1, the maximum unsigned int, and several values in between.
Using hexadecimal numbers for the tests will make developing assertions easier.
