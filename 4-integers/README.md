# Data Activity 4: Getting deep into integers

In this activity, you are provided working source code. You will modify the code
to illustrate the representation principles of signed vs. unsigned integers,
widening and narrowing during casting, and the limits/boundaries of different
integer data types.

## 1: Differences between signed and unsigned

Recall from Data Activity 1 each integer type has max and min values determined
by how many bytes it has, and that these values can be referenced from named
constants in `limits.h`. We will now examine the differences between the
limits of unsigned and signed numbers.

Note that for this activity, the Makefile has an example of building a program whose name is different than the .c file used to build it.

### Examining two's complement (signed) and unsigned representations of integers.

Build and run the demo code in `test_tc.c`. We are going to first consider the C
data type short, whose size in bytes and max and min limits are printed with the
code at the beginning of `main()`. You may wish to revisit the [printf format
reference](http://www.cplusplus.com/reference/cstdio/printf/).

Add other example values. Print their binary strings and verify that you
understand the bit patterns.

Now, try it with an unsigned short. Using `limits.h`, print the binary
representation of the largest value for this data type.

## 2: Casting

Now consider casting from short to unsigned short, as in the following code
(given in section 2.2.4 of your book and repeated here):

```
	short int v = -12345;

	unsigned short uv = (unsigned short) v;

	printf("v = %hd, uv = %hu\n", v, uv);
```

Try this code and print out the underlying binary representations of u and v
(you can add it to main in `test_tc.c`). What do you observe? Why is this so?

In your text, the author states: "when mapping a signed number to its unsigned
counterpart, negative numbers are converted to large positive numbers, while
non-negative numbers remain the same." Use 2 values to illustrate this and print
their binary representations out as test cases in your `test_tc.c` file.

Next, examine what happens when you cast between short and int. Casting from
short to int is generally fine, but from int to short can be problematic.
Choose some values to illustrate how this problem can be created and why you
should avoid it.


## 3: Integral values have limits

The last part of the main function in `test_tc.c`, commented out, prints the
table of representations of signed char values from -64 to +63. Uncomment it and
re-make your code to see all of the values get printed.  

### What happens if we increase the range?

Values declared to be signed char type are 1 byte long, or 8 bits. What
happens when you change the range in the for loop to go through all values in
the range of signed chars (-128 -- 127)? Make the new version and run it inside
the terminal. 

**Stopping Runaway Code:** CTRL-C will quit any running program on the command
line. You may need to wait quite a bit for the command prompt to come back, but
it will eventually.

Work through in your mind what is happening when you try using the full range of values in the for loop. Discuss this with your neighbors. Improve the code and try again. 

**Saving Output:** Now switch the code to values that will not create an
infinite loop, such as -64 to +63. After building with make, you can run the
program this way to save what is printed:

	./twos_comp > tc_out

This puts the output into a file called `tc_out`. You can view that file using a
program called less:

	less tc_out

Hitting the Q key will quit out of less. Space bar scrolls down, control-b or
control-u goes back up.

### Avoiding overflow in a loop

There are a few ways to avoid having this loop run infinitely. Here is one that
works fairly well. Add this to the bottom of the loop just before it goes back
around:

```
    if (i == 127) break;
```

You can also change the loop to do one fewer value, then print the last one outside of the loop.


## 4: Checking addition and subtraction of 2's complement numbers

Open the file `check_overflow.c`. In this part, you will fill in the function
`tsub_ok()` such that it correctly determines when subtraction of signed numbers
has caused an overflow. You will also test your function using assertion
statements.

There is an example of using logical operations to determine overflow in the
provided function `tadd_ok()`. Note that in C, there is no boolean type in the
standard library; we use integer values, like you've seen with logical
operators.

Be certain to try the interesting case of 0 - TMin.
