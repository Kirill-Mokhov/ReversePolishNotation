#include "CreateReversePolishNotation.h"

string CreateReversePolishNotation::createReversePolishNotation(CollectionOperationsComposite &CollectionOperations, string example) {
    stack<char> operationStack;
    string convertedExample, stringOutNumb;
    size_t i = 0;
    while (example[i] != '\0') {
        stringOutNumb = "";
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                stringOutNumb += example[i];
                i++;
            }
            convertedExample += stringOutNumb + ", ";
        }
        else {
            for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
                if (example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) {
                    if (operationStack.empty()) {
                        operationStack.push(CollectionOperations.OperationsFunctional(j)->designationOperation());
                    }
                    else {
                        if (CollectionOperations.OperationsFunctional(j)->whichOperationPriority() == 1) {
                            operationStack.push(example[i]);
                        }
                        else {
                            if (CollectionOperations.OperationsFunctional(j)->whichOperationPriority() == 0) {
                                while (findPriorityLastOperationOnTheStack(operationStack, CollectionOperations) != 1) {
                                    convertedExample += operationStack.top();
                                    convertedExample += ", ";
                                    operationStack.pop();
                                }
                                operationStack.pop();
                            }
                            else {
                                if (CollectionOperations.OperationsFunctional(j)->whichOperationPriority() > findPriorityLastOperationOnTheStack(operationStack, CollectionOperations)) {
                                    operationStack.push(example[i]);
                                } else {
                                    while ((operationStack.size() > 0) && (CollectionOperations.OperationsFunctional(j)->whichOperationPriority() <= findPriorityLastOperationOnTheStack(operationStack,CollectionOperations))) {
                                        convertedExample += operationStack.top();
                                        convertedExample += ", ";
                                        operationStack.pop();
                                    }
                                    operationStack.push(example[i]);
                                }
                            }
                        }
                    }
                }
            }
            i++;
        }
    }
    while (!operationStack.empty()) {
        convertedExample += operationStack.top();
        convertedExample += ", ";
        operationStack.pop();
    }
    convertedExample += "\0";
    return convertedExample;
}