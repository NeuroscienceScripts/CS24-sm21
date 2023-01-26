//
// Example header file, contains all declarations so files that use Example know
// what functions are available
//

#ifndef UNTITLED_EXAMPLE_H
#define UNTITLED_EXAMPLE_H

class Example{
private:
    int number1;
    int number2;
public:
    Example(int first, int second){number1=first; number2=second; }
    Example(int first){number1=first; number2=10; }
    void setNumber(int newNumber, int whichNumber);
    int getNumber(int whichNumber){return whichNumber==1 ? number1 : number2; }
};

#endif //UNTITLED_EXAMPLE_H
