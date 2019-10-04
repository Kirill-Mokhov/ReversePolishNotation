#ifndef REVERSEPOLISHNOTATION_OPERATIONINTERFACE_H
#define REVERSEPOLISHNOTATION_OPERATIONINTERFACE_H

using namespace std;

#include <stack>
#include <vector>

class OperationInterface {
public:
    virtual double binarySurgerySolution(double a, double b) = 0;
    virtual unsigned int whichOperationPriority() = 0;
    virtual char designationOperation() = 0;
};

class ClosingBracket : public OperationInterface {
    unsigned int operationPriority = 0;
    char designation = ')';
public:
    double binarySurgerySolution(double a, double b) override;
    unsigned int whichOperationPriority() override;
    char designationOperation() override;
};

class OpeningBracket : public OperationInterface {
    unsigned int operationPriority = 1;
    char designation = '(';
public:
    double binarySurgerySolution(double a, double b) override;
    unsigned int whichOperationPriority() override;
    char designationOperation() override;
};

class Subtraction : public OperationInterface {
    unsigned int operationPriority = 2;
    char designation = '-';
public:
    double binarySurgerySolution(double a, double b) override;
    unsigned int whichOperationPriority() override;
    char designationOperation() override;
};

class Addition : public OperationInterface {
    unsigned int operationPriority = 2;
    char designation = '+';
public:
    double binarySurgerySolution(double a, double b) override ;
    unsigned int whichOperationPriority() override ;
    char designationOperation() override;
};

class Division : public OperationInterface {
    unsigned int operationPriority = 3;
    char designation = '/';
public:
    double binarySurgerySolution(double a, double b);
    unsigned int whichOperationPriority() override;
    char designationOperation() override;
};

class Multiplication : public OperationInterface {
    unsigned int operationPriority = 3;
    char designation = '*';
public:
    double binarySurgerySolution(double a, double b) override;
    unsigned int whichOperationPriority() override;
    char designationOperation() override;
};

class Exponentiation : public OperationInterface {
    unsigned int operationPriority = 4;
    char designation = '^';
public:
    double binarySurgerySolution(double a, double b) override ;
    unsigned int whichOperationPriority() override;
    char designationOperation() override;
};

class CollectionOperationsComposite {
    vector<OperationInterface*> Operations;
    int numbOperation = -1;
public:
    void addOperation(OperationInterface &Operation);
    int howMuchOperations();
    OperationInterface* OperationsFunctional(int numb);
};

unsigned int findPriorityLastOperationOnTheStack(stack<char> &operationStack, CollectionOperationsComposite &CollectionOperations);

#endif //REVERSEPOLISHNOTATION_OPERATIONINTERFACE_H