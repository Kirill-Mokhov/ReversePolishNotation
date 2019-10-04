#ifndef REVERSEPOLISHNOTATION_INPUT_OUTPUT_H
#define REVERSEPOLISHNOTATION_INPUT_OUTPUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class InterfaceDataEntry {
public:
    virtual string enterData() = 0;
};

class KeyboardInputData : public InterfaceDataEntry {
public:
    string enterData() override ;
};

class DataFromFile : public InterfaceDataEntry {
    string nameFile;
public:
    void chooseFileName(string nameFile);
    string enterData() override ;
};

class InterfacePrintAnswer {
public:
    virtual void printSolver(string answer) = 0;//, string example_nameFile
};

class PrintSolver {
    InterfacePrintAnswer *Writer;
public:
    void setWriter(InterfacePrintAnswer &Writer);
    void printSolver(string answer);//, string example_nameFile
};

class WriteOnTheScreen : public InterfacePrintAnswer {
public:
    void printSolver(string answer) override ;//, string example
};

class WriteOnTheFile : public InterfacePrintAnswer {
private:
    string nameFile;
public:
    WriteOnTheFile(string nameFile);
    void printSolver(string answer) override ;//,string nameFile
    void setFile(string nameFile);
};

#endif //REVERSEPOLISHNOTATION_INPUT_OUTPUT_H