// Aahanaa (Atibrewa)

#include <stdio.h>
#include <limits.h>
#include <assert.h>

/*
 *  Libby Shoop
 *  Adapted from CS:APP, Practice Problem 2.32
 */

/*
 * First, 2.30 solution.
 * The overflow casses to consider are 2 very negative numbers or 2
 * very positive numbers, which might overflow.
 */
 int tadd_ok(int x, int y) {
    int sum = x + y;  // we will check to see if this number seems amiss

    // x, y, are 2 negative 2's complement numbers.
    // When they are added, they should remain negative, unless
    // the result overflows, inwhich case sum >= 0, and
    // neg_over gets set to true.
    int neg_over = (x < 0  &&  y < 0)  &&  sum >= 0;

    // x, y, are 2 positive 2's complement numbers.
    // When they are added, they ought to be positive.
    // If the addition overflowed, then sum goes negative
    // and pos_over gets set to true.
    int pos_over = (x >= 0  && y >= 0)  &&  sum < 0;

    return !neg_over && !pos_over;
 }

 /*
  * BUGGY
  * Determine if x - y can be subtracted without overflow.
  *
  * Return 1 if they can be subtracted without overflow and 0 if not.
  */

  int tsub_ok(int x, int y) {
    int sub = x - y;

    int p_over = (x >= 0 && y < 0) && sub < 0;

    int n_over = (x < 0 && y >= 0) && sub > 0;

    return !p_over && !n_over;
  }

/*
 *  main()  to test out the above functions and demonstrate overflow
 */
  int main() {
    int u, v;  // the number we will try in the above functions

    // try t_add_ok with some tests
    // 1. two high positive numbers
    u = 0x7FFFFFF0;
    v = 0x000000FF;  // enough to be slightly over when added to u

    printf("Case 1: High positive numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
    if (tadd_ok(u,v)) {
      printf("Addition was okay and did not overflow.\n");
    } else {
      printf("Addition overflow!\n");
    }

    // 2. two really large negative numbers
    u = 0xBFFFFFFF;
    v = 0xBFFFFFFE;
    printf("Case 2: Large negative numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
    if (tadd_ok(u,v)) {
      printf("Addition was okay and did not overflow.\n");
    } else {
      printf("Addition overflow!\n");
    }

    // 2a. just enough to go over
    u = 0xBFFFFFFF;
    v = 0xB0000001;
    printf("Case 2a: v is just negative enough: u = %x, v = %x, u+v = %x\n", u, v, u+v);
    if (tadd_ok(u,v)) {
      printf("Addition was okay and did not overflow.\n");
    } else {
      printf("Addition overflow!\n");
    }

    // 3. two positive numbers that should not overflow
    u = 0x00000070;
    v = 0x00FF0000;
    printf("Case 3:  Good positive numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
    if (tadd_ok(u,v)) {
      printf("Addition was okay and did not overflow.\n");
    } else {
      printf("Addition overflow!\n");
    }

    // 4. two negative numbers that should not overflow
    u = 0xFFFF0000;
    v = 0x80400000;
    printf("Case 4:  Good negative numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
    if (tadd_ok(u,v)) {
      printf("Addition was okay and did not overflow.\n");
    } else {
      printf("Addition overflow!\n");
    }

    //////////////////////////////////////
    // try t_sub_ok with some tests
    // What should they be?
    u = 0;
    v = INT_MIN;
    assert(0 == tsub_ok(u, v)); // It overflows - returns 0!

    u = INT_MIN;
    v = 1;
    assert(0 == tsub_ok(u, v)); // Overflows

    u = INT_MAX;
    v = -1;
    assert(0 == tsub_ok(u, v)); // Overflows

    u = INT_MIN;
    v = INT_MAX;
    assert(0 == tsub_ok(u, v)); // Overflows

    u = INT_MIN/4;
    v = INT_MAX/4;
    assert(1 == tsub_ok(u, v)); // Doesn't Overflow

    u = INT_MIN*0.75;
    v = INT_MAX*0.75;
    assert(0 == tsub_ok(u, v)); // Overflows

    u = INT_MAX/4;
    v = INT_MIN/4;
    assert(1 == tsub_ok(u, v)); // Doesn't Overflow

    u = INT_MAX*0.75;
    v = INT_MIN*0.75;
    assert(0 == tsub_ok(u, v)); // Overflows

    return 0;
  }
