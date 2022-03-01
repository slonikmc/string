//
// Created by Akelk on 01.03.2022.
//

#include "numberTurnIntoSpaces.h"
#include "../string_.h"
#include <ctype.h>

void numberTurnIntoSpaces(char *s) {
    char *readPtr = s;
    char dst[MAX_STRING_SIZE];
    char *recPtr = dst;
    while (*readPtr != '\0') {
        if (!isdigit(*readPtr)) {
            *recPtr = *readPtr;
            recPtr++;
        } else {
            int nSpaces = *readPtr - '0';
            while (nSpaces > 0) {
                *recPtr = ' ';
                recPtr++;
                nSpaces--;
            }
        }
        readPtr++;
    }
    copy(dst, recPtr, s);
    // Expected : "H el lo "
    // Got: "H el  loЁ¤a"
}

void test_numberTurnIntoSpaces_commonCase() {
    char str[] = "H1el2lo";
    numberTurnIntoSpaces(str);
    ASSERT_STRING("H el lo", str);
}

void test_numberTurnIntoSpaces() {
    test_numberTurnIntoSpaces_commonCase();
}
