#include "Calculator.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	string equation;
	int x, y, oper_pos;
	char op;

	cout << "Input equation that you would like the adding calculator to solve. \n" <<
		"Example: 15+27 \n" <<
		"Or you can quit with \"quit\", \"Quit\", \"Q\", \"q\"" << endl;
	getline(cin, equation);
	
	while(true) {

		if ((equation.compare("quit") == 0) ||
			(equation.compare("q") == 0) ||
			(equation.compare("Quit") == 0) ||
			(equation.compare("Q") == 0)) {
			break;
		}

		oper_pos = equation.find_first_of("+-*/^");
		if (!oper_pos) {
			string temp = equation.substr(1, equation.length());
			oper_pos = temp.find_first_of("+-*/^") + 1;
		}

		x = stoi(equation.substr(0, oper_pos));
		y = stoi(equation.substr(oper_pos + 1, equation.length()));
		op = equation[oper_pos];

		switch (op) {
		case '+':
			cout << x << op << y << '=' << Calculator::add(x, y) << endl;
			break;
		case '-':
			cout << x << op << y << '=' << Calculator::subtract(x, y) << endl;
			break;
		case '*':
			cout << x << op << y << '=' << Calculator::multiply(x, y) << endl;
			break;
		case '/':
			if (y == 0) {
				cout << "Not-defined" << endl;
				break;
			}
			cout << x << op << y << '=' << Calculator::divide(x, y) << endl;
			break;
		case '^':
			if (y < 0) {
				if (x > 1) {
					cout << "Non-integer answer" << endl;
					break;
				}
				else if (x == 0) {
					cout << "Not-defined" << endl;
					break;
				}
			}
			cout << x << op << y << '=' << Calculator::exponent(x, y) << endl;
		}

		getline(cin, equation);
		
	}

	return 0;
}
