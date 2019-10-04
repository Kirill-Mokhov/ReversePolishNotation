#include "SolverReversePolishNotation.h"
#include <stack>

double SolveReversePolishNotation::calculateRPN(CollectionOperationsComposite CollectionOperations, string example) {
    stack<double> numbStack;
    double numb, n1 ,n2, result;
    size_t i = 0;
    string stringOutNumb = "";
    while (example[i] != '\0') {
        while (example[i] == ',' || example[i] == ' ')
            i++;
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                stringOutNumb += example[i];
                i++;
            }
            numb = stoi(stringOutNumb.c_str(), nullptr, 10);
            numbStack.push(numb);
            stringOutNumb = "";
        }
        else {
            if(example[i] != '\0') {
                n2 = numbStack.top();
                numbStack.pop();
                n1 = numbStack.top();
                numbStack.pop();
                for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
                    if (example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) {
                        result = CollectionOperations.OperationsFunctional(j)->binarySurgerySolution(n1, n2);
                    }
                }
                numbStack.push(result);
                i++;
            }
        }
    }
    result = numbStack.top();
    numbStack.pop();
    return result;
}