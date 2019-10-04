#include "OperationInterface.h"
#include <cmath>

double ClosingBracket::binarySurgerySolution(double a, double b) {double answer;return answer;}
unsigned int ClosingBracket::whichOperationPriority() { return operationPriority; }
char ClosingBracket::designationOperation() { return designation; }

double OpeningBracket::binarySurgerySolution(double a, double b) {double answer;return answer;}
unsigned int OpeningBracket::whichOperationPriority() { return operationPriority; }
char OpeningBracket::designationOperation() { return designation; }


double Subtraction::binarySurgerySolution(double a, double b) {
    double answer;
    answer = a - b;
    return answer;
}
unsigned int Subtraction::whichOperationPriority() { return operationPriority; }
char Subtraction::designationOperation() { return designation; }

double Addition::binarySurgerySolution(double a, double b) {
    double answer;
    answer = a + b;
    return answer;
}
unsigned int Addition::whichOperationPriority() { return operationPriority; }
char Addition::designationOperation() { return designation; }

double Division::binarySurgerySolution(double a, double b) {
    double answer;
    answer = a / b;
    return answer;
}
unsigned int Division::whichOperationPriority() { return operationPriority; }
char Division::designationOperation() { return designation; }

double Multiplication::binarySurgerySolution(double a, double b) {
    double answer;
    answer = a * b;
    return answer;
}
unsigned int Multiplication::whichOperationPriority() { return operationPriority; }
char Multiplication::designationOperation() { return designation; }


double Exponentiation::binarySurgerySolution(double a, double b) {
    double answer;
    answer = pow(a, b);
    return answer;
}
unsigned int Exponentiation::whichOperationPriority() { return operationPriority; }
char Exponentiation::designationOperation() { return designation; }

void CollectionOperationsComposite::addOperation(OperationInterface &Operation) {
    Operations.push_back(&Operation);
    numbOperation++;
}
int CollectionOperationsComposite::howMuchOperations() {
    return numbOperation;
}
OperationInterface* CollectionOperationsComposite::OperationsFunctional(int numb){
    return Operations[numb];
}
unsigned int findPriorityLastOperationOnTheStack(stack<char> &operationStack, CollectionOperationsComposite &CollectionOperations) {
    unsigned int priorityLastOperation;
    int last = 0;
    while (CollectionOperations.OperationsFunctional(last)->designationOperation() != operationStack.top())
        last++;
    priorityLastOperation = CollectionOperations.OperationsFunctional(last)->whichOperationPriority();
    return priorityLastOperation;
}