//
// Created by Akelk on 07.03.2022.
//

#include "reverseString.h"

void reverseString(char *s) {
    WordDescriptor word;
    if (getWord(s, &word) == 0)
        return;
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    char *copyS = s;
    while (getWordReverse(endBuffer - 1, _stringBuffer - 1, &word)) {
        copyS = copy(word.begin, word.end, copyS);
        *copyS = ' ';
        copyS++;
        *endBuffer = word.begin;
    }
    if (copyS != s)
        copyS--;
    *copyS = '\0';
}

void test_reverseString_emptyString() {
    char s[] = "";
    reverseString(s);
    ASSERT_STRING("", s);
}

void test_reverseString_onlySpaces() {
    char s[] = "    ";
    reverseString(s);
    ASSERT_STRING("    ", s);
}

void test_reverseString_commonCase() {
    char s[] = "Bye Hello";
    reverseString(s);
    ASSERT_STRING("Hello Bye", s);
}

void test_reverseString() {
    test_reverseString_emptyString();
    test_reverseString_onlySpaces();
    test_reverseString_commonCase();
}