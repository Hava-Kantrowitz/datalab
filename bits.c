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

   int x = 0xaa;//Start the pattern
   int y = x << 8;//Shift by 8
   int z = (y | x);//or it with itself
   int z2 = z << 16;//repeat with a 16 shift in order to repeat the pattern over all 32 bits
   int result = (z | z2);
   return result;//return the pattern
}
/*
 * isTmin - returns 1 if x is the minimum two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {

	int comp2 = (~x) + 1;//Find two's complement
	int eq = (x ^ comp2);//xor it with original
	int check = !x;//Not the original
	int combine = !(eq + check);//And them together, then not the value to obtain 1 if tMin and 0 otherwise
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

  int var1 = x & (~y);//not y and x
  int var2 = (~x) & y;//not x and y
  int var3 = ~(~(var1) & ~(var2));//Demorgan's Law to compare
  return var3;//return result of comparison
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
  * return z if x is 0, y if x is anything else
  */

  int notX = !!x;//double not x in order to make it 0 if 0 or 1 if anything else
  int twoComp = (~notX) + 1;//take two's complement
  return (twoComp & y) | (~twoComp & z);//And it with y, and the inverse with z, or them together
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

	int rs1 = x >> 1;//Right shift the integer over, oring it with itself before each shift
	int rs1or = x | rs1;//in order to get all 1's in the bits at the MSB and to the right
	int rs2 = rs1or >> 2;
	int rs2or = rs1or | rs2;
	int rs4 = rs2or >> 4;
	int rs4or = rs2or | rs4;
	int rs8 = rs4or >> 8;
	int rs8or = rs4or | rs8;
	int rs16 = rs8or >> 16;
	int rs16or = rs8or | rs16;

	int add1 = rs16or + 1;//add 1 in order to get 0's in all bits MSB and right, and a 1 to the left of the MSB
	int specialMask = add1 >> 1;//create the mask
	int tMin = 1 << 31;//create tMin
	int negCheck = ((x >> 31) & (tMin)) | ((~(x >> 31)) & (specialMask >> 31) & (1 << 30));//check for negative
	int oneCheck = negCheck | ((~specialMask >> 31) & specialMask);//check for tMax
	return oneCheck;//return the specific masks for special cases checked for, return the original mask otherwise
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

	/*
	 * roughly follows technique described in chapter 2 of textbook
	 */

	int rightShift = x >> 31;//ultra right shift to get leftmost bit
	int leftShift = 1 << n;//determine bias in order to round toward zero
	int handleRound = leftShift + ~0;
	int together = rightShift & handleRound;//add together
	int addX = x + together;//add to x
	return addX >> n;//right shift by n in order to perform the actual division
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  return !(x >> 31);//ultra right shift to get last bit, not the value
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
	/*
	 * Negative overflow saturates to tMin, positive overflow saturates to tMax
	 */

	int mult = x << 1;//Multiply by 2
	int xSign = x >> 31;//Isolate the sign of the original
	int multSign = mult >> 31;//Isolate the sign of the multiplied
	int checkSame = (((!!(multSign ^ xSign)) << 31) >> 31);//compare them, ultra-shifting both left and right in order to populate all 32 bits with sign bit
	int tMin = 1 << 31;//get tMin
	int tMax = ~tMin;//get tMax
	int maxOrMin = (xSign & tMin) | ((~xSign) & tMax);//Use the sign to determine whether it's negative or positive
	int answer = (checkSame & maxOrMin) | ((~checkSame) & mult);//if the first check shows the signs are different, perform the min or max check
	return answer;//return the value saturated to, or if neither of the checks are hit, return the multiplied value
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {

	int sameSign = (x >> 31) ^ (y >> 31);//or the last bits together to determine if sign is the same
	int yShift = !(y >> 31);//get the leftmost bit and not it
	int handleSame = sameSign & yShift;//handle the same case
	int twoComp = (~y) + 1;//find two's complement of y
	int addX = x + twoComp;//add x to the two's complement
	int xShift = addX >> 31;//ultra right shift the value in order to get the last digit
	int handleDiff = !sameSign & !!xShift;//compare and return lesser value
	return handleSame | handleDiff;//two's complement handles when the sign is different

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

	/*
	 * Shift the given value by 4 in order to isolate the 5th and 6th bits
	 * Check that they are both ones by checking that they are 3 (xor with 3)
	 * Add 6 (max value that can be added to an ascii digit and still remain in range)
	 * Shift added value and check that 5th and 6th digits are still 1
	 * Not the compared values in order to receive a 1 if it is within range, a 0 if not in range
	 * If both are in range, return 1, if one or both are out of range, return 0
	 */

	int shiftFirst = x >> 4;//Shift the given value by 4 in order to isolate the 5th and 6th bits
	int compareFirst = !(shiftFirst ^ 3);//Check that they are both ones by checking that they are 3 (xor with 3)
	int add = x + 6;//Add 6 (max value that can be added to an ascii digit and still remain in range)
	int shiftSecond = add >> 4;//Shift added value
	int compareSecond = !(shiftSecond ^ 3);//Check that 5th and 6th digits are still 1, not the compared values in order to receive a 1 if it is within range, a 0 if not in range
	return (compareFirst & compareSecond);//If both are in range, return 1, if one or both are out of range, return 0
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

  int xVal = ((~(x >> 31)) & x) | ((x >> 31) & (x+1));//if x is positive, keep x as x, if it's negative x is x + 1
  int endBits = xVal & 3;//save the last 2 bits of x
  int div4full = xVal >> 2;//divide x value by 4 to avoid overflow
  int mult3full = div4full + (div4full << 1);//multiply it by 3 to get actual number
  int mult3end = endBits + (endBits << 1);//do the same with the last two bits, starting with multiplication
  int div4end = mult3end >> 2;
  int together = div4end + mult3full; //add both computations together for final adjusted result

  return together;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

	int rs1 = x >> 1;//greatest bit positive code in order to get mask with one in gbp location
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

	int tMax = ~(1 << 31);//get tmax
	int specialVal = 4 << 28;//get the value that must be returned when rs16or is tMax

	int logInput = ((((!(rs16or ^ tMax)) << 31) >> 31) & specialVal) | ((((!!(rs16or ^ tMax)) << 31) >> 31) & specialMask);//correct the log input depending on if rs16or is tMax
	int counter = 0;//counter to keep track of location of gbp

	int firstHalf = logInput >> 16;//shift by 16 to grab first half of bit patterm
	int secondHalf = logInput;//second half is just the bit pattern

	int firstHalfZero = !!firstHalf;//0 if first half is all 0's, one otherwise
	int ultraShift = (firstHalfZero << 31) >> 31;//populate the bit with all 0's if first half is all 0's, all 1's otherwise
	int whatToKeep = (ultraShift & firstHalf) | (~ultraShift & secondHalf);//return the half with the one in it
	counter = ultraShift & (counter + 16) ;//update the counter to reflect bit location

	firstHalf = whatToKeep >> 8;//the above steps are repeated for shift of 8, shifting the bits in half again
	secondHalf = whatToKeep;

	firstHalfZero = !!firstHalf;
	ultraShift = (firstHalfZero << 31) >> 31;
	counter = (ultraShift & (counter + 8)) | (~ultraShift & counter);
	whatToKeep = (ultraShift & firstHalf) | (~ultraShift & secondHalf);

	firstHalf = whatToKeep >> 4;//the above steps are repeated for shift of 4, shifting the bits in half again
	secondHalf = whatToKeep;

	firstHalfZero = !!firstHalf;
	ultraShift = (firstHalfZero << 31) >> 31;
	counter = (ultraShift & (counter + 4)) | (~ultraShift & counter);
	whatToKeep = (ultraShift & firstHalf) | (~ultraShift & secondHalf);

	firstHalf = whatToKeep >> 2;//the above steps are repeated for shift of 2, shifting the bits in half again
	secondHalf = whatToKeep;

	firstHalfZero = !!firstHalf;
	ultraShift = (firstHalfZero << 31) >> 31;
	counter = (ultraShift & (counter + 2)) | (~ultraShift & counter);
	whatToKeep = (ultraShift & firstHalf) | (~ultraShift & secondHalf);

	firstHalf = whatToKeep >> 1;//the above steps are repeated for shift of 1, shifting the bits in half again

	firstHalfZero = !!firstHalf;
	ultraShift = (firstHalfZero << 31) >> 31;
	counter = (ultraShift & (counter + 1)) | (~ultraShift & counter);

    return counter;//return the counter of where the bit position is kept
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

 unsigned exp = uf >> 23;//grab the exponent by right shifting it over 23
 unsigned expNAN = exp & 0xff;//And with 11111111 to check if all one's
 unsigned fraction = uf << 9; //grab fraction by left shifting it over 9
 unsigned tMin = 1 << 31;//create tMin
 unsigned fracNotZero = !fraction;//yields 0 if there are any ones in the fraction, 1 otherwise

 if ((expNAN == 0xff) && !fracNotZero){//If the exponent is all 1's and the fraction isn't 0, it's NAN
	 return uf;//so just return the argument
 }
 else{//otherwise return the argument xored with tMin in order to flip just the sign bit
	 return (uf ^ tMin);
 }

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

	unsigned signPrep = uf >> 31;//grab the sign by grabbing the leftmost bit
	unsigned sign = signPrep << 31;//fill the rest of the float with 0's so the sign can be or-ed back in later - THIS IS THE SIGN
	unsigned noSign = uf << 1;//right shift to chop off sign bit
	unsigned expPrep = noSign >> 24;//grab the exponent
	unsigned exp = expPrep << 23;//fill the rest of the float with 0's so the exponent can be or-ed back in later - THIS IS THE EXPONENT
	unsigned mantPrep = uf << 9;//grab the mantissa
	unsigned mant = mantPrep >> 9;//fill the rest of the float with 0's so the mantissa can be or-ed back in later - THIS IS THE MANTISSA
    unsigned nan = 0x7f800000;//not a number

	if (exp == 0){//if the exponent is 0, just multiply normally
		unsigned times2 = uf << 1;//to multiply, left shift by 1
		return (times2 | sign);//or sign bit back in before returning
	}
	else if (exp == nan){//If the exponent is NAN, just return argument
		return uf;
	}
	else{//otherwise return the argument multiplied by 2
	 unsigned one = 1 << 23; //fill the entire float with 1's to have a thing of 1 to add
	 unsigned multExp = exp + one;//to multiply, add 1 to the exponent
	 return (sign | multExp | mant);//or the sign and mantissa bits back in before returning
	}


}
