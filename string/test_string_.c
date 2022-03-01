//
// Created by Akelk on 01.03.2022.
//

#include "test_string_.h"
#include "string_.h"
#include <assert.h>
#include <malloc.h>
#include <string.h>

static void test_find_commonCase() {
    char *testWord = "Hello";
    int stringLength = 5;
    int posOfDesiredElem = 2;
    char *res = find(testWord, testWord + stringLength, 'l');
    assert(*res == *(testWord + posOfDesiredElem));
}

static void test_find_symbolNotFound() {
    char *testWord = "Hehho";
    int stringLength = 5;
    char *res = find(testWord, testWord + stringLength, 'l');
    assert(*res == *(testWord + stringLength));
}

static void test_find() {
    test_find_commonCase();
    test_find_symbolNotFound();
}

static void test_findNonSpace_commonCase() {
    char *testWord = "   Hello";
    char *res = findNonSpace(testWord);
    int posOfDesiredElem = 3;
    assert(*res == *(testWord + posOfDesiredElem));
}

static void test_findNonSpace_symbolNotFound() {
    char *testWord = "      ";
    int stringLength = 6;
    char *res = findNonSpace(testWord);
    assert(*res == *(testWord + stringLength));
}

static void test_findNonSpace_allSymbols() {
    char *testWord = "Hello";
    char *res = findNonSpace(testWord);
    assert(*res == *testWord);
}

static void test_findNonSpace() {
    test_findNonSpace_commonCase();
    test_findNonSpace_symbolNotFound();
    test_findNonSpace_allSymbols();
}

static void test_findSpace_commonCase() {
    char *testWord = "Hello   ";
    int posOfDesiredElem = 5;
    char *res = findSpace(testWord);
    assert(*res == *(testWord + posOfDesiredElem));
}

static void test_findSpace_symbolNotFound() {
    char *testWord = "Hello";
    char *res = findSpace(testWord);
    int stringLength = 5;
    assert(*res == *(testWord + stringLength));
}

static void test_findSpace_allSymbols() {
    char *testWord = "Hello";
    int stringLength = 5;
    char *res = findSpace(testWord);
    assert(*res == *(testWord + stringLength));
}

static void test_findSpace() {
    test_findSpace_commonCase();
    test_findSpace_symbolNotFound();
    test_findSpace_allSymbols();
}

static void test_findNonSpaceReverse_commonCase() {
    char *testWord = "Hello     ";
    int stringLength = 10;
    int posOfDesiredElem = 4;
    char *res = findNonSpaceReverse(testWord + stringLength - 1, testWord);
    assert(*res == *(testWord + posOfDesiredElem));
}

static void test_findNonSpaceReverse_symbolNotFound() {
    char *testWord = "          ";
    int stringLength = 10;
    char *res = findNonSpaceReverse(testWord + stringLength - 1, testWord);
    assert(*res == *(testWord));
}

static void test_findNonSpaceReverse_allSymbols() {
    char *testWord = "HelloHello";
    int stringLength = 10;
    char *res = findNonSpaceReverse(testWord + stringLength - 1, testWord);
    assert(*res == *(testWord + stringLength - 1));
}

static void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_commonCase();
    test_findNonSpaceReverse_symbolNotFound();
    test_findNonSpaceReverse_allSymbols();
}

static void test_findSpaceReverse_commonCase() {
    char *testWord = "Hello  Hello ";
    int stringLength = 13;
    int posOfDesiredElem = 6;
    char *res = findSpaceReverse(testWord + stringLength - 1, testWord);
    assert(*res == *(testWord + posOfDesiredElem));
}

static void test_findSpaceReverse_symbolNotFound() {
    char *testWord = "          ";
    int stringLength = 10;
    char *res = findSpaceReverse(testWord + stringLength - 1, testWord);
    assert(*res == *(testWord + stringLength - 1));
}

static void test_findSpaceReverse_allSymbols() {
    char *testWord = "HelloHello";
    int stringLength = 10;
    char *res = findSpaceReverse(testWord + stringLength - 1, testWord);
    assert(*res == *(testWord));
}

static void test_findSpaceReverse() {
    test_findSpaceReverse_commonCase();
    test_findSpaceReverse_symbolNotFound();
    test_findSpaceReverse_allSymbols();
}

static void test_strcmp_strIsEqual() {
    char *str1 = "Hello123";
    char *str2 = "Hello123";
    int res = strcmp(str1, str2);
    assert(res == 0);
}

static void test_strcmp_strIsDifferent() {
    char *str1 = "Hello123";
    char *str2 = "Hello124";
    int res = strcmp(str1, str2);
    assert(res != 0);
}


static void test_strcmp() {
    test_strcmp_strIsEqual();
    test_strcmp_strIsDifferent();
}

static void test_copy_fullCopy() {
    char *str = "Hello123";
    int stringLength = 8;
    char *res = "Hello123";
    char *dst = malloc(sizeof(char) * (stringLength + 1));
    char *endDst = copy(str, str + stringLength, dst);
    *endDst = '\0';
    assert(strcmp(res, dst) == 0);
    free(dst);
}

static void test_copy_copyPiece() {
    char *str = "Hello123";
    int stringLength = 8;
    char *res = "Hell";
    int pieceResLen = 4;
    char *dst = malloc(sizeof(char) * (stringLength + 1));
    char *endDst = copy(str, str + pieceResLen, dst);
    *endDst = '\0';
    assert(strcmp(res, dst) == 0);
    free(dst);
}

static void test_copy() {
    test_copy_fullCopy();
    test_copy_copyPiece();
}

static int isDigit(int symbol) {
    return symbol >= '0' && symbol <= '9';
}

static void test_copyIf_fullCopy() {
    char *str = "12323123";
    int stringLength = 8;
    char *res = "12323123";
    char *dst = malloc(sizeof(char) * (stringLength + 1));
    char *endDst = copyIf(str, str + stringLength, dst, isDigit);
    *endDst = '\0';
    assert(!strcmp(res, dst));

    free(dst);
}

static void test_copyIf_copyPiece() {
    char *str = "Hello123";
    int stringLength = 8;
    char *res = "123";
    char *dst = malloc(sizeof(char) * (stringLength + 1));
    char *endDst = copyIf(str, str + stringLength, dst, isDigit);
    *endDst = '\0';
    assert(!strcmp(res, dst));

    free(dst);
}

static void test_copyIf() {
    test_copyIf_fullCopy();
    test_copyIf_copyPiece();
}

static void test_copyIfReverse_fullCopy() {
    char *str = "12323123";
    int stringLength = 8;
    char *res = "32132321";
    char *dst = malloc(sizeof(char) * (stringLength + 1));
    char *endDst = copyIfReverse(str + stringLength, str - 1, dst, isDigit);
    *endDst = '\0';
    assert(!strcmp(res, dst));

    free(dst);
}

static void test_copyIfReverse_copyPiece() {
    char *str = "Hello123";
    int stringLength = 8;
    char *res = "321";
    char *dst = malloc(sizeof(char) * (stringLength + 1));
    char *endDst = copyIfReverse(str + stringLength, str - 1, dst, isDigit);
    *endDst = '\0';
    assert(!strcmp(res, dst));

    free(dst);
}

static void test_copyIfReverse() {
    test_copyIfReverse_fullCopy();
    test_copyIfReverse_copyPiece();
}

void test() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}



