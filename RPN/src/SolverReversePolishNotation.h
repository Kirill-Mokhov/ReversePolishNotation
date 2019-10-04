#ifndef REVERSEPOLISHNOTATION_SOLVERREVERSEPOLISHNOTATION_H
#define REVERSEPOLISHNOTATION_SOLVERREVERSEPOLISHNOTATION_H

#include <stack>
#include <string>
#include "OperationInterface.h"

using namespace std;

class SolveReversePolishNotation {
public:
    double calculateRPN(CollectionOperationsComposite CollectionOperations, string example);
};

#endif //REVERSEPOLISHNOTATION_SOLVERREVERSEPOLISHNOTATION_H