#include "stack.hpp"
#include <iostream>
#include <string>

typedef std::string String;

String infix_to_postfix(const char expr[]) {
    stack<String> S;
    char token;
    String rhs, lhs, op;
    int i = 0;

    while (expr[i] != 0) {
        token = expr[i];
        if (token == ')') {
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(lhs + rhs + op);
        } else if (token != '(') {
            S.push(String(1, token));
        }
        ++i;
    }
    return S.pop();
}

String infix_to_prefix(const char expr[]) {
        stack<String> S;
    char token;
    String rhs, lhs, op;
    int i = 0;

    while (expr[i] != 0) {
        token = expr[i];
        if (token == ')') {
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(op + lhs + rhs);
        } else if (token != '(') {
            S.push(String(1, token));
        }
        ++i;
    }
    return S.pop();
}