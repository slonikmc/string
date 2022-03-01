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

static void test_removeNonLetters_commonCase() {
    char str[] = "H e l  67  ";
    removeNonLetters(str);
    ASSERT_STRING("Hel67", str);
}

static void test_removeNonLetters_onlyGraphs() {
    char str[] = "Hel67";
    removeNonLetters(str);
    ASSERT_STRING("Hel67", str);
}

static void test_removeNonLetters_onlySpaces() {
    char str[] = "     ";
    removeNonLetters(str);
    ASSERT_STRING("", str);
}

static void test_removeNonLetters_emptyString() {
    char str[] = "";
    removeNonLetters(str);
    ASSERT_STRING("", str);
}

void test_removeNonLetters() {
    test_removeNonLetters_commonCase();
    test_removeNonLetters_onlyGraphs();
    test_removeNonLetters_onlySpaces();
    test_removeNonLetters_emptyString();
}