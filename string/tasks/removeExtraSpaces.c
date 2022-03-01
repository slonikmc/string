//
// Created by Akelk on 01.03.2022.
//

#include "removeExtraSpaces.h"
#include <ctype.h>
#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *curSymbol = s;
    char *lastSymbol = curSymbol;
    while (*curSymbol != '\0') {
        if (!isspace(lastSymbol) || !isspace(*curSymbol)) {
            *s = *curSymbol;
            s++;
        }
        lastSymbol = *curSymbol;
        curSymbol++;
    }
    *s = '\0';
}

void test_removeExtraSpaces_commonCase() {
    char str[] = "Hello   Hello Hello   ";
    removeExtraSpaces(str);
    ASSERT_STRING("Hello Hello Hello ", str);
}

void test_removeExtraSpaces_onlyGraphs() {
    char str[] = "Hello";
    removeExtraSpaces(str);
    ASSERT_STRING("Hello", str);
}

void test_removeExtraSpaces_onlySpaces() {
    char str[] = "         ";
    removeExtraSpaces(str);
    ASSERT_STRING(" ", str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_commonCase();
    test_removeExtraSpaces_onlyGraphs();
    test_removeExtraSpaces_onlySpaces();
}