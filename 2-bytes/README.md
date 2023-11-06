# Data Activitiy : Observing each byte

Folder: `2-bytes`

In this activity, you will use provided source code to answer questions about
how integers and strings are represented by the computer.

## 1. Which end? 

Open the *show-bytes.c* file, taken from your textbook, and examine the code.
Notice that the file called test.c uses the functions in the show-bytes file.
This will be a common way that you will separate your code. 

Use `make` in the terminal to build these code files before you change them.

Discuss with your neighbor: what aspects of the C language are unfamiliar? If
you cannot determine what they mean or what some part of the code is doing, try
to find an answer or ask your instructor. 

Run show-bytes and use the results to answer this question in a new text file: 

* Is the machine you are running this on big-endian or little-endian? Why? Refer to section 2.1.3 of your book for help.

Note that the makefile also lets you remove the binaries and start a fresh
build. Try this by doing the following:

	make clean

	make all

## 2.  Verifying ascii representation of strings

Open this [Manual page for ascii characters.](http://man7.org/linux/man-pages/man7/ascii.7.html) Make sure that your browser window is wide enough to display the acsii table nicely. This is from a typical linux manual page, or 'man page' for short. You can use this to see all of the ascii character codes
used in strings.  

The command `man` is short for manual.  It is used to provide more information
for various commands and other information in unix. You can try other commands
in your own terminal on the server, e.g.

	man gcc

	man ls

	man bash   (a long page about the terminal shell called bash that you are typing in)

	man man


Using `showbytes.c`, answer the following question in your text file:
  
* How is the storage of each byte of a string different from the storage of the
  bytes of an int? Consider the topic of Endianness again. Are strings Endian?

### Note

Strings have one extra character added to them called a *trailing null byte*.
The end of the string is signaled by having this one last character that is
always a zero, which is not used for any ascii character. All strings have this
and we need to account for it in our code, as we store strings as arrays of
characters.

Modify the function `string_leg()` to also print the trailing null byte of a
string. Discuss this with your neighbor--how should you do this? Also change the
string to add some other character from the ascii table other than a letter or
number. Verify that you observe the correct ascii code for it.

## 3.  Also try this: 

Try changing the printf statement in the `show_bytes` function to look like this:

	printf("%p\t0x%.2x\n",start+i, start[i]);

`%p` tells printf to print the pointer address. `start` is pointing to the
zeroth element of an array of bytes. 

Answer these questions in your text file:

* What does this changed print statement do?

* How is the value for the pointer increasing in this loop? Discuss in terms of
  bytes.

## 4. Make the code work for long ints

Add a function to show all the bytes of a `long` variable. Change `main()` to
use it.
