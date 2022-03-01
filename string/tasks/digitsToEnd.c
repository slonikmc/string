//
// Created by Akelk on 01.03.2022.
//

#include "digitsToEnd.h"
#include "../string_.h"
#include <ctype.h>

void digitsToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer - 1, endStringBuffer, word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void redactStringCriteria(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitsToEnd(word);
        beginSearch = word.end;
    }
}

void test_redactStringCriteria_commonCase() {
    char str[] = "1Hello23";
    redactStringCriteria(str);
    ASSERT_STRING("Hello123", str);
}

void test_redactStringCriteria_digitsInBegin() {
    char str[] = "123Hello";
    redactStringCriteria(str);
    ASSERT_STRING("Hello123", str);
}

void test_redactStringCriteria_digitsInEnd() {
    char str[] = "Hello123";
    redactStringCriteria(str);
    ASSERT_STRING("Hello123", str);
}

void test_redactStringCriteria_onlyAlphas() {
    char str[] = "Hello";
    redactStringCriteria(str);
    ASSERT_STRING("Hello", str);
}

void test_redactStringCriteria_onlyDigits() {
    char str[] = "123";
    redactStringCriteria(str);
    ASSERT_STRING("123", str);
}

void test_redactStringCriteria_onlySpaces() {
    char str[] = "   ";
    redactStringCriteria(str);
    ASSERT_STRING("   ", str);
}

void test_redactStringCriteria_emptyString() {
    char str[] = "";
    redactStringCriteria(str);
    ASSERT_STRING("", str);
}

void test_redactStringCriteria() {
    test_redactStringCriteria_commonCase();
    test_redactStringCriteria_digitsInBegin();
    test_redactStringCriteria_digitsInEnd();
    test_redactStringCriteria_onlyAlphas();
    test_redactStringCriteria_onlyDigits();
    test_redactStringCriteria_onlySpaces();
    test_redactStringCriteria_emptyString();
}
