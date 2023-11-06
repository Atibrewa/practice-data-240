# Data Activity 5: Floating Point representation at the bit level

Folder: `5-floating-point`

The file `fp_coding_ex.c` contains code designed to examine the bit-level
encodings of floating point numbers. This line near the top of the file is a key
aspect of the code:

    typedef unsigned float_bits;

We are going to look at how the machine actually treats the single precision
floating point numbers by treating their bit patterns as unsigned integers. This
typedef helps us use the moniker `float_bits` to refer to the bit-level
representation of a float.

The code contains some functions from an earlier activity where we broke down
data representations into their individual bytes. You should be able to compile
and run this code as-is.

The function `float_denorn_zero()` provides you with an example of how the
machine can manipulate the bits that make up the portions of a floating point
number. The unsigned data type, which is 32 bits long and is defined to have the
name `float_bits`, represents how a 32-bit floating point number could be stored
as a bit pattern. Recall that in the IEEE single precision representation:


- the leftmost, or most significant bit, is the sign bit
- the next 8 bits are the 'exp' value
- the next 23 bits, or the least significant 23 bits are the 'frac' value

For this activity, it is useful to also recall that the floating point numbers
fall into several categories, each of which encodes the above pieces differently
and which represent a range of possible represented values as follows:

![Floating Point Numberline](./img/FPRangeLine.png)

You will now investigate each of these encodings by considering their bit level
representations, just like the machine does.

## 1: Denormalized values 

Your first task is to determine some positive and negative denormalized
bit-pattern values for 32-bit single precision and test this function,
`float_denorm_zero()`, with them.

Recall from class (see lecture notes on moodle) that numbers are represented using this equation:

<p>(-1)<sup>s</sup>   x  M   x   2<sup>E</sup></p>

In the case of denormalized values, which are used for small numbers, the exp
bits are all zero.  

1. How is the exponent E computed for the *denormalized* numbers in 32-bit
   single precision representation?
2. How is the significand, M, encoded?
3. For 32-bit single precision IEEE floats, what are the largest possible and
   smallest possible denormalized values? Write the answers for both the
   positive and negative ranges in hex.

Once you have done so, test your answers in `main()` by calling
`float_denorn_zero()`. Additionally, create values between those endpoints and
test them as well.  [This reference by Steve Hollasch may be
useful](http://steve.hollasch.net/cgindex/coding/ieeefloat.html).

## 2: Normalized numbers

Now let's turn our attention to the normalized numbers. Consider the following questions for review:

1. How is the exponent E computed for the *normalized* numbers in 32-bit single precision representation?
2. How is the significand, M, encoded?
3. Determine the largest and smallest normalized values, both positive and
   negative. Give your answers in hex.

Again, test your answers in `main()` by calling `float_denorn_zero()`.


## 3: Infinity and NaN 

How might you write a similar function to test whether a value is either
infinity or NaN (not a number)? Implement and call this function.

## 4: Negation

Complete the function called `float_negate()` and test it in `main()`. This also
illustrates how the machine would perform this operation.

## 5: Challenge

Suppose you wished to test out the full range of 32-bit patterns for floats.
Recall from previous activities that we can use a pointer to unsigned char
(`unsigned char*`) to inspect individual bytes of various types, including
floats. This was done in the `show_bytes` example code early in the semester and
is provided again here.

Let's start this process by creating a function that will make a float from its
given bit pattern.

Complete a function called `generate_float()` that returns a float from a given
input set of bits represented by the `float_bits` type. You will need to create
the float value using the formula:

<p>(-1)<sup>s</sup> x  M x  2<sup>E</sup></p>

where you compute M and E from the rules for IEEE single precision floating
point. You will need to use the exp and frac portions from the original bit
pattern, along with the sign bit.

Note that once you have the floating point representation, you can check whether
the bytes match your original bytes from the input bit pattern. Add a test in
`main()` that checks this on some bit patterns.

Now that this seems to work, you can use `generate_float` on a range of
denormalized bit patterns in a loop and use assert to ensure that
`float_denorn_zero()` returns what you expect. The you can try it for ranges of
normalized numbers.
