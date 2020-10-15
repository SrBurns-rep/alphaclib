#ifndef __alphaclib_h_
#define __alphaclib_h_

#define MAX_ALPHA "3W5E11264SGSF"

#include <stdint.h>

//Integer exponentiation
uint64_t integer_pow(int base, int exp);

/**
 * Conversion from an integer to alphanumeric
 * (36) base as a string.
 * This function uses calloc.
 */
char* to_alpha(uint64_t num);

/**
 * Conversion from an alpanumeric string is
 * restricted to the maxmimum unsigned integer
 * value is: 3W5E11264SGSF
 */
uint64_t to_decimal(char* alpha, int size);

//Returns a specific char from MAX_ALPHA
char ch_from_max(int i);

//Checks if a char is alphanumeric.
int is_alphanum(char c);

/**
* Decimal to alpha + string size.
*/
char* to_alphas(uint64_t num, int* alpha_size);

//Prints the number and then clears from memory.
int print_to_alpha(uint64_t num);


#endif