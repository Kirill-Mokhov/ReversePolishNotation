#ifndef RPN_EXCEPTION_H
#define RPN_EXCEPTION_H

#include <string>
#include <vector>
#include "OperationInterface.h"

using namespace std;

class ExceptionInterface{
public:
    virtual void checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) = 0;
};

class UnknownOperation : public ExceptionInterface {
public:
    void checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) override ;
};

class RightBracketNotFound : public ExceptionInterface {
public:
    void checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) override ;
};

class LeftBracketNotFound : public ExceptionInterface {
public:
    void checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) override ;
};

class FoundTwoOperationsRow : public ExceptionInterface {
public:
    void checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) override ;
};

class ExtraOperationFound : public ExceptionInterface {
public:
    void checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) override ;
};

class ExceptionCollection {
    vector<ExceptionInterface*> Exception;
    int numbExeption = 4;
public:
    void allExeption();
    int howMuchExeption();
    ExceptionInterface* ExeptionCheckForErrors(int numb);
};

class ErrorChekingExeption {
public:
    void errorCheking(string example, ExceptionCollection &ExeptionCollection, CollectionOperationsComposite &CollectionOperations, int numb);
};

#endif //RPN_EXCEPTION_H
