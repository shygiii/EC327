#ifndef POLISHNOTATION_H
#define POLISHNOTATION_H
#include <vector>
#include <string>
#include <stack>

template <typename InputType>
class RPNCalculator {
public:
    int evaluate(const InputType &expression);

private:
    std::vector<std::string> tokenize(const std::string &expr);
    std::stack<std::string> stack;
};
#endif // POLISHNOTATION_H