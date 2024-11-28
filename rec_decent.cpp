#include "rec_decent.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

const char* string = "2^(2*4)";
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
    int val_first = GetPower();
    while (string[position] == '*' || string[position] == '/'){
        int oper = string[position];
        position++;
        int val_second = GetPower();
        if (oper == '*')
            val_first *= val_second;
        else if (oper == '/')
            val_first /= val_second;
        else
            pow(val_first, val_second);
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

int GetPower(){
    int val_first = GetP();
    if (string[position] == '^'){
        position++;
        int val_second = GetP();
        return pow(val_first, val_second);
    }

    return val_first;
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