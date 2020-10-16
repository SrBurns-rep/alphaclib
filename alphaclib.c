#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALPHA_BASE 36

uint64_t integer_pow(int base, int exp) {
	
	uint64_t res = 1;

	if (exp < 0) return 0;

	for (int i = 0; i < exp; i++) {
		res *= base;
	}

	return res;
}

char* to_alpha(uint64_t num, char* alpha) {

	int i = 0, j, ans;

	uint64_t val[2] = {0, num - integer_pow(36, i)};

	while (val[1] > val[0]) {
		val[1] = num - integer_pow(36, i);
		i++;
		val[0] = num - integer_pow(36, i);
	}

	if (num == 0)i++;

	i--;

	for (j = 0; i >= 0; i--, j++) {

		ans = num / integer_pow(ALPHA_BASE, i);
		num -= ans * integer_pow(ALPHA_BASE, i);

		// ASCII
		if (ans < 10) {
			alpha[j] = ans + 48;
		}
		else {
			alpha[j] = ans + 55;
		}
	}

	return alpha;
}

uint64_t to_decimal(char* alpha, int size) {

	uint64_t ans = 0;

	if (size > 14)return 0;

	for (int i = (size - 1), j = 0; i >= 0; i--, j++) {
		if ((alpha[i] >= '0') && (alpha[i] <= '9')) {
			ans += ((uint64_t) alpha[i] - 48) * integer_pow(36, j);
		}
		else if ((alpha[i] >= 'A') && (alpha[i] <= 'Z')) {
			ans += ((uint64_t) alpha[i] - 55) * integer_pow(36, j);
		}
		else {
			return 0;
		}
	}

	return ans;
}

char ch_from_max(int i) {
	char c[] = "3W5E11264SGSF";
	if (i > 12)return '&';

	return c[i];
}

int is_alphanum(char c) {
	if ((c >= '0') || (c <= '9')) {
		return 1;
	}
	else if ((c >= 'A') || (c <= 'Z')) {
		return 1;
	}
	else {
		return 0;
	}
}

char* to_alphas(uint64_t num, int* alpha_size, char* alpha) {

	int i, j, ans;
	
	uint64_t val[2] = {0, num - integer_pow(36, i)};

	while (val[1] > val[0]) {
		val[1] = num - integer_pow(36, i);
		i++;
		val[0] = num - integer_pow(36, i);
	}
	
	if (num == 0)i++;

	i--;

	for (j = 0; i >= 0; i--, j++) {
		ans = num / integer_pow(ALPHA_BASE, i);
		num -= ans * integer_pow(ALPHA_BASE, i);

		// ASCII
		if (ans < 10) {
			alpha[j] = ans + 48;
		}
		else {
			alpha[j] = ans + 55;
		}
	}

	*alpha_size = j;

	return alpha;
}

int print_to_alpha(uint64_t num) {

	int i;

	char* alpha = to_alpha(num);

	i = printf("%s", alpha);

	free(alpha);

	return i;
}
