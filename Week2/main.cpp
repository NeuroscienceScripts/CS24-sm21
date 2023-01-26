#include <iostream>
#include "Example.cpp"  // Can use all functions defined in Example.cpp

using namespace std;

int main() {
    Example sample(3); //Uses the single parameter constructor which sets number2 to 10
    cout << sample.getNumber(2) << std::endl; //prints second number (10)
    return 0;
}

