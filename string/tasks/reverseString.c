//
// Created by Akelk on 07.03.2022.
//

#include "reverseString.h"

void reverseString(char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    WordDescriptor word;
    while (getWordReverse(endBuffer - 1, _stringBuffer - 1, &word)) {
        s = copy(word.begin, word.end, s);
        *s = ' ';
        s++;
        endBuffer = findNonSpaceReverse(endBuffer - 1, _stringBuffer - 1);
    }
    s--;
    *s = '\0';
}

void test_reverseString_emptyString() {
    char s[] = "";
    reverseString(s);
    ASSERT_STRING("", s);
}

void test_reverseString_onlySpaces() {
    char s[] = "    ";
    reverseString(s);
    ASSERT_STRING("", s);
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