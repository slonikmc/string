//
// Created by Akelk on 01.03.2022.
//

#include "numberTurnIntoSpaces.h"
#include "../string_.h"
#include <ctype.h>

void numberTurnIntoSpaces(char *s) {
    char *beginBuffer = _stringBuffer;
    char *endBuffer = copy(s, s + strlen_(s), _stringBuffer);

    while (beginBuffer < endBuffer) {
        if (!isdigit(*beginBuffer)) {
            *s = *beginBuffer;
            s++;
        } else {
            int nSpaces = *beginBuffer - '0';
            for (int i = 0; i < nSpaces; i++) {
                *s = ' ';
                s++;
            }
        }
        beginBuffer++;
    }
    *s = '\0';
}


void test_numberTurnIntoSpaces_noSymbols() {
    char str[] = "";
    numberTurnIntoSpaces(str);
    ASSERT_STRING("", str);
}

void test_numberTurnIntoSpaces_oneSpace() {
    char str[] = " ";
    numberTurnIntoSpaces(str);
    ASSERT_STRING(" ", str);
}

void test_numberTurnIntoSpaces_twoSpaces() {
    char str[] = "  ";
    numberTurnIntoSpaces(str);
    ASSERT_STRING("  ", str);
}

void test_numberTurnIntoSpaces_onlyDigits() {
    char str[] = "12";
    numberTurnIntoSpaces(str);
    ASSERT_STRING("   ", str);
}

void test_numberTurnIntoSpaces_onlyLetters() {
    char str[] = "Hello";
    numberTurnIntoSpaces(str);
    ASSERT_STRING("Hello", str);
}

void test_numberTurnIntoSpaces_commonCase() {
    char str[] = "H1el2lo";
    numberTurnIntoSpaces(str);
    ASSERT_STRING("H el  lo", str);
}

void test_numberTurnIntoSpaces() {
    test_numberTurnIntoSpaces_noSymbols();
    test_numberTurnIntoSpaces_oneSpace();
    test_numberTurnIntoSpaces_twoSpaces();
    test_numberTurnIntoSpaces_onlyDigits();
    test_numberTurnIntoSpaces_onlyLetters();
    test_numberTurnIntoSpaces_commonCase();
}
