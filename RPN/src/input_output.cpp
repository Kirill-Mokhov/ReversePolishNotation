#include "input_output.h"
#include "exception.h"
#include <iostream>

using namespace std;

string KeyboardInputData::enterData() {
    string example;
    exception exception;


    cin >> example;
    return example;
}

void DataFromFile::chooseFileName(const string nameFile) {
    this->nameFile = nameFile;
}

string DataFromFile::enterData() {
    string example;
    ifstream yourFile;
    yourFile.open(this->nameFile, ios_base::in);
    if (!yourFile.is_open())
        throw invalid_argument(this->nameFile);
    if (yourFile.is_open()) {
        yourFile >> example;
        yourFile.close();
    }
    return example;
}

void PrintSolver::setWriter(InterfacePrintAnswer &Writer) {
    this->Writer = &Writer;
}

void PrintSolver::printSolver(string answer){
    this->Writer->printSolver(answer);
}

void WriteOnTheScreen::printSolver(string answer) {
    cout << answer << endl;
}

WriteOnTheFile::WriteOnTheFile(string nameFile) {
    this->nameFile = nameFile;
}

void WriteOnTheFile::printSolver(string answer) {
    ofstream outputFile;
    ifstream outputFileForCheck;
    string str;
    outputFile.open(this->nameFile, ios_base::app);
    outputFileForCheck.open(this->nameFile, ios_base::in);
    if (outputFileForCheck.is_open()) {
        outputFile << answer;
        outputFile << endl;
    }
    outputFile.close();
    outputFileForCheck.close();
}

void WriteOnTheFile::setFile(string nameFile) {
    this->nameFile = nameFile;
}