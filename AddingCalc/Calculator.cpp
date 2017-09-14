#include "Calculator.h"

Calculator::Calculator() {}

int Calculator::add(int x, int y) {
	return (x + y);
}

int Calculator::subtract(int x, int y) {
	return (x + negative(y));
}

int Calculator::multiply(int x, int y) {
	int product = 0;
	int pos_y;

	// This if stores the absolute value of y in pos_y
	if (y < 0) {
		pos_y = negative(y);
	}
	else {
		pos_y = y;
	}

	// Loop the sum (which is multiplication)
	for (int i = 0; i < pos_y; i++) {
		product = product + x;
	}

	// If y is negative we need to negate the value found.
	// Case 1 (+x, +y): It will just return the product
	// Case 2 (+x, -y): It will calculate using loop and negate answer
	// Case 3 (-x, +y): It will add negative x's and return the negative answer
	// Case 4 (-x, -y): It will add engative x's then negate the negative number
	//					to a positive one simulating negative * negative.
	if (y < 0) {
		product = negative(product);
	}

	return product;
}

std::string Calculator::divide(int x, int y) {

	int quotient = 1, absx, absy;
	std::string str_quo = "";

	// Trivial division of 0 divided by anything other than 0
	if (x == 0 && y != 0) {
		return 0;
	}

	// Collect absolute value of x
	if (x < 0) {
		absx = negative(x);
	}
	else {
		absx = x;
	}

	// Collect absolute value of y
	if (y < 0) {
		absy = negative(y);
	}
	else {
		absy = y;
	}

	// Bulk of our division, done using our multiplication function.
	// We need the absolute value of both dividend and divisor.
	// We'll check for sign after completion of finding the quotient.
	while (quotient < absx) {
		if (multiply(quotient, absy) < absx) {
			quotient++;
		}
		else if (multiply(quotient, absy) == absx) {
			// This if checks for opposing signs.
			if ((x < 0 && y >0) || (x > 0 && y < 0)) {
				quotient = negative(quotient);
			}
			str_quo = std::to_string(quotient);
			break;
		}
		else if (multiply(quotient, absy) > absx) {
			str_quo = "Non-integer answer";
			break;
		}
	}

	return str_quo;
}

int Calculator::exponent(int x, int y) {

	// Trivial cases to reduce time
	if (y == 0) {
		return 1;
	}
	if (x == 0) {
		return 0;
	}
	if (x == 1) {
		return 1;
	}

	// If all trivial cases failed, then procudeed with 
	// calculating the exponent.
	int product = 1;
	for (int i = 1; i <= y; i++) {
		product = multiply(product, x);
	}
	return product;
}

/**
 * Found an idea to negate a given number online.
 */
int Calculator::negative(int a) {
	int negated_val = INT_MIN;
	while (negated_val + a != 0) {
		negated_val++;
	}
	return negated_val;
}

Calculator::~Calculator() {}