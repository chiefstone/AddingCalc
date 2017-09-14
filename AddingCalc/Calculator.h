#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once
#include <climits>
#include <iostream>
#include <string>

class Calculator {
private:
	static int negative(int);
public:

	Calculator();

	static int add(int, int);

	static int subtract(int, int);

	static int multiply(int, int);

	static std::string divide(int, int);

	static int exponent(int, int);

	~Calculator();
};

#endif