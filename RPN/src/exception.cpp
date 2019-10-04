#include "exception.h"
#include "input_output.h"
#include "OperationInterface.h"
#include "CreateReversePolishNotation.h"
#include "SolverReversePolishNotation.h"


void UnknownOperation :: checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) {
    size_t i = 0;
    string error = "";
    bool foundUnknowOperation(true);
    example += "\0";
    while (example[i] != '\0'){
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                i++;
            }
        }
        for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
            if (example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) {
                foundUnknowOperation = false;
            }
        }
        if (foundUnknowOperation){
            error += "Found unknown operation : \"";
            error += example[i];
            error += "\"";
            throw invalid_argument(error);
        }
        i++;
    }
}

void RightBracketNotFound :: checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) {
    size_t i = 0;
    string error = "";
    bool LeftBracket(false), RightBracket(false);
    example += "\0";
    while (example[i] != '\0'){
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                i++;
            }
        }
        for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
            if ((example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) && (example[i] == '(')) {
                LeftBracket = true;
            }
        }
        for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
            if ((example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) && (example[i] == ')')) {
                RightBracket = true;
            }
        }
        i++;
    }
    if (LeftBracket && !RightBracket){
        error += "Not found right bracket!";
        throw invalid_argument(error);
    }
}
void LeftBracketNotFound :: checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) {
    size_t i = 0;
    string error = "";
    bool LeftBracket(false), RightBracket(false);
    example += "\0";
    while (example[i] != '\0'){
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                i++;
            }
        }
        for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
            if ((example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) && (example[i] == '(')) {
                LeftBracket = true;
            }
        }
        for (size_t j = 0; j <= CollectionOperations.howMuchOperations(); j++) {
            if ((example[i] == CollectionOperations.OperationsFunctional(j)->designationOperation()) && (example[i] == ')')) {
                RightBracket = true;
            }
        }
        i++;
    }
    if (!LeftBracket && RightBracket){
        error += "Not found left bracket!";
        throw invalid_argument(error);
    }
}
void FoundTwoOperationsRow :: checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) {
    size_t i = 0;
    string error = "";
    bool foundTwoOperationRow(false);
    example += "\0";
    while (example[i] != '\0') {
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                i++;
            }
        }
        if (((example[i] < 48 || example[i] > 57) && example[i] != '(' && example[i] != ')' && example[i] != '\0')&&((example[i + 1] < 48 || example[i + 1] > 57) && example[i + 1] != '(' && example[i + 1] != ')' && example[i + 1] != '\0')){
            foundTwoOperationRow = true;
        }
        if (foundTwoOperationRow){
            error += "Found two operations row! (\"";
            error += example[i];
            error += "\", \"";
            error += example[i + 1];
            error += ("\")");
            throw invalid_argument(error);
        }
        if (example[i] != '\0')
            i++;
    }
}

void ExtraOperationFound :: checkForErrors(string example, CollectionOperationsComposite &CollectionOperations) {
    size_t i = 0, operations = 0, numbs = 0;
    string error = "";
    example += "\0";
    while (example[i] != '\0'){
        if (example[i] >= 48 && example[i] <= 57) {
            while (example[i] >= 48 && example[i] <= 57) {
                i++;
            }
            numbs++;
        }
        if (example[i] != '(' && example[i] != ')' && example[i] != '\0')
            operations++;
        i++;
    }
    if (numbs <= operations){
        error += "Extra operation found!";
        throw invalid_argument(error);
    }
}

void ErrorChekingExeption :: errorCheking(string example, ExceptionCollection &ExeptionCollection, CollectionOperationsComposite &CollectionOperations, int numb){
    ExeptionCollection.ExeptionCheckForErrors(numb)->checkForErrors(example, CollectionOperations);
}

UnknownOperation UnknowOperation;
RightBracketNotFound RightBracketNotFound;
LeftBracketNotFound LeftBracketNotFound;
FoundTwoOperationsRow FoundTwoOperationsRow;
ExtraOperationFound ExtraOperationFound;

void ExceptionCollection :: allExeption () {
    Exception.push_back(&UnknowOperation);
    Exception.push_back(&RightBracketNotFound);
    Exception.push_back(&LeftBracketNotFound);
    Exception.push_back(&FoundTwoOperationsRow);
    Exception.push_back(&ExtraOperationFound);
}

int ExceptionCollection :: howMuchExeption() {
    return numbExeption;
}

ExceptionInterface* ExceptionCollection :: ExeptionCheckForErrors(int numb) {
    return Exception[numb];
}