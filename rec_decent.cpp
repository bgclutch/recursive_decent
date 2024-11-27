#include "rec_decent.h"
#include <stdio.h>
#include <assert.h>

const char* string = "25*10*(3*(25-10*2)+1)";
int position = 0;

int RecursiveDecent(){
    return GetG();
}

int GetG(){
    int val = GetE();
    if (string[position] != '\0')
        SyntaxError();
    position++;
    return val;
}

int GetE(){
    int val_first = GetT();
    while (string[position] == '+' || string[position] == '-'){
        int oper = string[position];
        position++;
        int val_second = GetT();
        if (oper == '+')
            val_first += val_second;
        else
            val_first -= val_second;
    }
    return val_first;
}

int GetT(){
    int val_first = GetP();
    while (string[position] == '*' || string[position] == '/'){
        int oper = string[position];
        position++;
        int val_second = GetP();
        if (oper == '*')
            val_first *= val_second;
        else
            val_first /= val_second;
    }
    return val_first;
}

int GetP(){
    if (string[position] == '('){
        position++;
        int val = GetE();
        if (string[position] != ')')
            SyntaxError();
        position++;
        return val;
    }
    else
        return GetN();
}

int GetN(){
    int val = 0;
    int old_position = position;
    while ('0' <= string[position] && string[position] <= '9'){
        val = val * 10 + (string[position] - '0');
        position++;
    }
    if (old_position == position)
        SyntaxError();
    return val;
}


void SyntaxError(){
    assert(0);
}