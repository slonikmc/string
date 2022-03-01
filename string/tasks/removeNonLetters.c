//
// Created by Akelk on 01.03.2022.
//

#include "removeNonLetters.h"
#include <ctype.h>
#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_commonCase() {
    char *str = "Hello123";
    removeNonLetters(str);
    ASSERT_STRING("Hello", str);
}