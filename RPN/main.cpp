#include "src/input_output.h"
#include "src/OperationInterface.h"
#include "src/CreateReversePolishNotation.h"
#include "src/SolverReversePolishNotation.h"
#include "src/exception.h"

int main() {
    DataFromFile DataFromFile;
    DataFromFile.chooseFileName("C:/ProgectCpp/LosiaProject/ReversePolishNotation/RPN/files/example.txt");

    KeyboardInputData KeyboardInputData;

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
    SolveReversePolishNotation SolveReversePolishNotation;

    ExceptionCollection ExceptionCollection;
    ErrorChekingExeption ErrorChekingExeption;
    ExceptionCollection.allExeption();
    string example1 = KeyboardInputData.enterData();
    string example2 = DataFromFile.enterData();
    cout << example1 << endl;
    cout << example2 << endl;

    for (size_t i = 0; i <= ExceptionCollection.howMuchExeption(); i++){
        try {
            ErrorChekingExeption.errorCheking(example1, ExceptionCollection, CollectionOperations, i);
            ErrorChekingExeption.errorCheking(example2, ExceptionCollection, CollectionOperations, i);
        }
        catch(invalid_argument(e)) {
            cout << "ERROR! \"" << e.what() << " " << endl;
            return 0;
        }
    }

    WriteOnTheFile WriteOnTheFile("C:/ProgectCpp/LosiaProject/ReversePolishNotation/RPN/files/answer.txt");
    WriteOnTheScreen WriteOnTheScreen;
    PrintSolver PrintSolver;
    PrintSolver.setWriter(WriteOnTheScreen);
    PrintSolver.printSolver(CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example1));
    PrintSolver.printSolver(to_string(SolveReversePolishNotation.calculateRPN(CollectionOperations, CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example1))));
    PrintSolver.printSolver(CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example2));
    PrintSolver.printSolver(to_string(SolveReversePolishNotation.calculateRPN(CollectionOperations, CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example2))));

    PrintSolver.setWriter(WriteOnTheFile);
    PrintSolver.printSolver(CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example1));
    PrintSolver.printSolver(to_string(SolveReversePolishNotation.calculateRPN(CollectionOperations, CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example1))));
    PrintSolver.printSolver(CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example2));
    PrintSolver.printSolver(to_string(SolveReversePolishNotation.calculateRPN(CollectionOperations, CreateReversePolishNotation.createReversePolishNotation(CollectionOperations, example2))));

    return 0;
}