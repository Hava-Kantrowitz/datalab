/* 
 * CS:APP Data Lab 
 * 
 * Hava Kantrowitz, hskantrowitz
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
    /*
    * start the pattern, then shift it over and or it with itself
    * repeat a second time with the shifted pattern so the pattern repeats over all 32 bits
    */

   int x = 0xaa;
   int y = x << 8;
   int z = (y | x);
   int z2 = z << 16;
   int result = (z | z2);
   return result;
}
/*
 * isTmin - returns 1 if x is the minimum two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	/*
	 * Find the two's complement and xor it with the original
	 * then not the original, add them together, and not that
	 */

	int comp2 = (~x) + 1;
	int eq = (x ^ comp2);
	int zeroCheck = !x;
	int combine = !(eq + zeroCheck);
    return combine;

}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*
   * not y, and it with x; not x, and it with y
  not both results
  Use Demorgan's law*/
  int var1 = x & (~y);
  int var2 = (~x) & y;
  int var3 = ~(~(var1) & ~(var2));
  return var3;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //return z if x is 0, y if x is anything else
  //double not x in order to make it 0 if 0 or 1 if anyone else
  //Take the two's complement
  //And it with y, and the inverse with z, or them together
  int notX = !!x;
  int twoComp = (~notX) + 1;
  return (twoComp & y) | (~twoComp & z);
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {

	/*
	 * Right shift the integer over, oring it with itself before each shift in order to get all 1's in
	 * the bits at the MSB and to the right. Create the mask. Check for negative and tMax,
	 * returning their specific masks if found. If not found, return created mask
	 */

	int rs1 = x >> 1;
	int rs1or = x | rs1;
	int rs2 = rs1or >> 2;
	int rs2or = rs1or | rs2;
	int rs4 = rs2or >> 4;
	int rs4or = rs2or | rs4;
	int rs8 = rs4or >> 8;
	int rs8or = rs4or | rs8;
	int rs16 = rs8or >> 16;
	int rs16or = rs8or | rs16;

	int add1 = rs16or + 1;
	int specialMask = add1 >> 1;
	int tMin = 1 << 31;
	int negCheck = ((x >> 31) & (tMin)) | ((~(x >> 31)) & (specialMask >> 31) & (1 << 30));
	int oneCheck = negCheck | ((~specialMask >> 31) & specialMask);
	return oneCheck;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	//ultra right shift to get leftmost bit
	//determine bias in order to round toward zero
	//And together, add to x
	//right shift by n in order to perform the actual divison
	//roughly follows technique described in chapter 2 of textbook
	int rightShift = x >> 31;
	int leftShift = 1 << n;
	int handleRound = leftShift + ~0;
	int together = rightShift & handleRound;
	int addX = x + together;
	return addX >> n;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  //ultra right shift to get last bit, not the value
  return !(x >> 31);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	/**
	 * Multiply, then isolate the sign of the original and multiplied. Compare them, ultra-shifting
	 * both left and right in order to populate an entire integer with the sign bit. Use the sign of
	 * the original to determine whether it is negative, and therefore might saturate to tMin, or positive,
	 * and therefore might saturate to tMax. If the first check shows the signs are different, perform
	 * the min or max check. Else, just return the multiplied value
	 */

	int mult = x << 1;
	int xSign = x >> 31;
	int multSign = mult >> 31;
	int checkSame = (((!!(multSign ^ xSign)) << 31) >> 31);
	int tMin = 1 << 31;
	int tMax = ~tMin;
	int maxOrMin = (xSign & tMin) | ((~xSign) & tMax);
	int answer = (checkSame & maxOrMin) | ((~checkSame) & mult);
	return answer;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
	//or the last bits together to determine if sign is the same
	//Use two's complement for case when signs are different
	//Use DeMorgan's law to perform comparison
	int sameSign = (x >> 31) ^ (y >> 31);
	int yShift = !(y >> 31);
	int handleSame = sameSign & yShift;
	int twoComp = (~y) + 1;
	int addX = x + twoComp;
	int xShift = addX >> 31;
	int handleDiff = !sameSign & !!xShift;
	return handleSame | handleDiff;

}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	/**
	 * COMMENT
	 */
	int shiftFirst = x >> 4;
	int compareFirst = !(shiftFirst ^ 3);
	int add = x + 6;
	int shiftSecond = add >> 4;
	int compareSecond = !(shiftSecond ^ 3);
	return (compareFirst & compareSecond);
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
  return 2;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	//gbp code
	//divide in half
	//is one in first half or second half?
	//if one is in second half, add 16
	//if one is in first half, return that value
	int rs1 = x >> 1;
	int rs1or = x | rs1;
	int rs2 = rs1or >> 2;
	int rs2or = rs1or | rs2;
	int rs4 = rs2or >> 4;
	int rs4or = rs2or | rs4;
	int rs8 = rs4or >> 8;
	int rs8or = rs4or | rs8;
	int rs16 = rs8or >> 16;
	int rs16or = rs8or | rs16;

	int add1 = rs16or + 1;
	int specialMask = add1 >> 1;


  return oneCheck;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
