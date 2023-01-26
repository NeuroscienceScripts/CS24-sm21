// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

Stack s; // Declared globally for usage across functions

// Prints an Error Message then Exits
void error() {
    cerr << "ERROR" << endl;
    exit(1);
}

// Checks if char* is an int
bool CheckInt(char* cstr) {
    for(int j = 0; j < strlen(cstr); j++){
        if(!isdigit(cstr[j]))
            return false;
    }
    return true;
}

// Performs arithmetic
void PerformOperation(char* cstr) {

    int temp = s.top();
    s.pop();

    if (strcmp(cstr, "+") == 0)             temp =  s.top() + temp;
    else if (strcmp(cstr, "-") == 0)        temp =  s.top() - temp;
    else if (strcmp(cstr, "*") == 0)        temp =  s.top() * temp;
    else if (strcmp(cstr, "/") == 0)        temp =  s.top() / temp;
    else                                    error();

    s.pop();
    s.push(temp);
}

void EvaluatePostfix(char *expression[], int numTokens) {

    for(int i = 0; i < numTokens; i++) {
        if(CheckInt(expression[i]))         s.push(stoi(expression[i]));
        else                                PerformOperation(expression[i]);
    }
}

#define MAXLEN 100

int main() {
    char input[MAXLEN], *tokens[MAXLEN/2];

    cout << "enter expression: ";
    cin.getline(input, MAXLEN);
    char *ptr = strtok(input, " ");

    int count = 0;
    while (ptr != 0) {
        tokens[count] = ptr;
        ++count;
        ptr = strtok(0, " ");
    }

    EvaluatePostfix(tokens, count);

    int answer = s.top();
    s.pop();

    if (!s.empty())         error();
    else                    cout << answer << endl;

    return 0;
}


