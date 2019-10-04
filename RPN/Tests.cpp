#include "gtest/gtest.h"
#include "src/input_output.h"
#include "src/OperationInterface.h"
#include "src/CreateReversePolishNotation.h"
#include "src/SolverReversePolishNotation.h"
#include "src/exception.h"

TEST(CreateReversePolishNotation, creationWorks) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    Exponentiation ExpOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    CollectionOperations.addOperation(ExpOperation);
    CreateReversePolishNotation CreateReversePolishNotation;
    string example1 = "4+3-2*20/2^(6+2-1)";
    EXPECT_EQ(CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example1), "4, 3, +, 2, 20, *, 2, 6, 2, +, 1, -, ^, /, -, ");
}

TEST(CreateReversePolishNotation, UnknownOperation) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    ExceptionCollection ExceptionCollection;
    ErrorChekingExeption ErrorChekingExeption;
    ExceptionCollection.allExeption();
    string example1 = "4%3-2";
    ASSERT_THROW(ErrorChekingExeption.errorCheking(example1, ExceptionCollection, CollectionOperations, 0), invalid_argument);
}

TEST(CreateReversePolishNotation, RightBracketNotFound) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    ExceptionCollection ExceptionCollection;
    ErrorChekingExeption ErrorChekingExeption;
    ExceptionCollection.allExeption();
    string example1 = "(4+3*2";
    ASSERT_THROW(ErrorChekingExeption.errorCheking(example1, ExceptionCollection, CollectionOperations, 1), invalid_argument);
}


TEST(CreateReversePolishNotation, LeftBracketNotFound) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    ExceptionCollection ExceptionCollection;
    ErrorChekingExeption ErrorChekingExeption;
    ExceptionCollection.allExeption();
    string example1 = "4+3)*2";
    ASSERT_THROW(ErrorChekingExeption.errorCheking(example1, ExceptionCollection, CollectionOperations, 2), invalid_argument);
}

TEST(CreateReversePolishNotation, FoundTwoOperationsRow) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    ExceptionCollection ExceptionCollection;
    ErrorChekingExeption ErrorChekingExeption;
    ExceptionCollection.allExeption();
    string example1 = "4+3*3*^2";
    ASSERT_THROW(ErrorChekingExeption.errorCheking(example1, ExceptionCollection, CollectionOperations, 3), invalid_argument);
}


TEST(CreateReversePolishNotation, ExtraOperationFound) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    ExceptionCollection ExceptionCollection;
    ErrorChekingExeption ErrorChekingExeption;
    ExceptionCollection.allExeption();
    string example1 = "3+4*2-";
    ASSERT_THROW(ErrorChekingExeption.errorCheking(example1, ExceptionCollection, CollectionOperations, 4), invalid_argument);
}

TEST(SolveReversePolishNotation, solverWorks) {
    CollectionOperationsComposite CollectionOperations;
    OpeningBracket OpeningBracket;
    ClosingBracket ClosingBracket;
    Multiplication MulOperation;
    Division DivOperation;
    Subtraction SubOperation;
    Addition AddOperation;
    Exponentiation ExpOperation;
    CollectionOperations.addOperation(OpeningBracket);
    CollectionOperations.addOperation(ClosingBracket);
    CollectionOperations.addOperation(MulOperation);
    CollectionOperations.addOperation(DivOperation);
    CollectionOperations.addOperation(SubOperation);
    CollectionOperations.addOperation(AddOperation);
    CollectionOperations.addOperation(ExpOperation);
    SolveReversePolishNotation SolveReversePolishNotation;
    string example1 = "4, 3, +, 2, 20, *, 2, 6, 2, +, 1, -, ^, /, -, ";
    EXPECT_EQ(SolveReversePolishNotation.calculateRPN(CollectionOperations, example1), 6.687500);
}