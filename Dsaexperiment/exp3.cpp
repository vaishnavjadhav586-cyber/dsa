
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Return operator precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

// Perform the operation
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;

        case '/':
            if (b == 0) {
                throw runtime_error("Division by zero");
            }
            return a / b;
    }

    throw runtime_error("Invalid operator");
}

// Evaluate infix expression directly
int evaluate(string expr) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++) {

        // Ignore spaces
        if (isspace(static_cast<unsigned char>(expr[i])))
            continue;

        // Read a complete number
        if (isdigit(static_cast<unsigned char>(expr[i]))) {
            int num = 0;

            while (i < expr.length() &&
                   isdigit(static_cast<unsigned char>(expr[i]))) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            values.push(num);
            i--;
        }

        // Opening parenthesis
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }

        // Closing parenthesis
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(a, b, op));
            }

            if (ops.empty())
                throw runtime_error("Mismatched parentheses");

            ops.pop();  // Remove '('
        }

        // Operator
        else if (expr[i] == '+' || expr[i] == '-' ||
                 expr[i] == '*' || expr[i] == '/') {

            while (!ops.empty() && ops.top() != '(' &&
                   precedence(ops.top()) >= precedence(expr[i])) {

                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(a, b, op));
            }

            ops.push(expr[i]);
        }

        else {
            throw runtime_error("Invalid character");
        }
    }

    // Process remaining operators
    while (!ops.empty()) {
        if (ops.top() == '(')
            throw runtime_error("Mismatched parentheses");

        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOperation(a, b, op));
    }

    if (values.size() != 1)
        throw runtime_error("Invalid expression");

    return values.top();
}

int main() {
    string expr;

    cout << "Enter infix expression: ";
    getline(cin, expr);

    try {
        cout << "Result = " << evaluate(expr) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
