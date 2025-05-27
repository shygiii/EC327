#include "PolishNotation.h"
#include <vector>
#include <string>

template <typename InputType>
int RPNCalculator<InputType>::evaluate(const InputType& expression) {
    /*
    std::vector<std::string> expressionvector;
    std::vector<std::string>::iterator i;
    for (i=expressionvector.begin(); i!=expressionvector.end(); i++) {
        std::string token = *i;
        if (token=="+"||token=="-"||token=="*" ||token=="/") {
            if (stack.size()>=2) {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (token=="+") stack.push(a+b);
                else if (token=="-") stack.push(a-b);
                else if (token=="*") stack.push(a*b);
                else if (token=="/" && b!=0) stack.push(a/b);
            }
        }
        else stack.push(std::stoi(token));
    }
    return stack.top();
    */
    return 0;
}

template <typename InputType>
std::vector<std::string> RPNCalculator<InputType>::tokenize(const std::string &expr) {
    std::vector<std::string> tokenvector;
    /*
    for (int i=0; i<expr.size(); i++) {
        if (expr[i]!=" ") tokenvector.push_back(expr[i]);
    }
    */
    return tokenvector;
}

template class RPNCalculator<std::string>;
template class RPNCalculator<std::vector<std::string>>;