#include "string/string_.h"
#include <assert.h>

void test_find_commonCase() {
    char *testWord = "Hello";
    char *res = find(testWord, testWord + 5, 'l');
    assert(*res == *(testWord + 2));
}

void test_find_symbolNotFound() {
    char *testWord = "Hehho";
    char *res = find(testWord, testWord + 5, 'l');
    assert(*res == *(testWord + 5));
}

void test_find() {
    test_find_commonCase();
    test_find_symbolNotFound();
}

void test_findNonSpace_commonCase() {
    char *testWord = "   Hello";
    char *res = findNonSpace(testWord);
    assert(*res == *(testWord + 3));
}

void test_findNonSpace_symbolNotFound() {
    char *testWord = "     ";
    char *res = findNonSpace(testWord);
    assert(*res == *(testWord + 5));
}

void test_findNonSpace() {
    test_findNonSpace_commonCase();
    test_findNonSpace_symbolNotFound();
}

void test_findSpace_commonCase() {
    char *testWord = "Hello   ";
    char *res = findSpace(testWord);
    assert(*res == *(testWord + 5));
}

void test_findSpace_symbolNotFound() {
    char *testWord = "Hello";
    char *res = findSpace(testWord);
    assert(*res == *(testWord + 5));
}

void test_findSpace() {
    test_findSpace_commonCase();
    test_findSpace_symbolNotFound();
}

void test_findNonSpaceReverse_commonCase() {
    char *testWord = "Hello    ";
    char *res = findNonSpaceReverse(testWord + 7, testWord);
    assert(*res == *(testWord + 4));
}

void test_findNonSpaceReverse_symbolNotFound() {
    char *testWord = "          ";
    char *res = findNonSpaceReverse(testWord + 7, testWord + 1);
    assert(*res == *(testWord + 1));
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_commonCase();
    test_findNonSpaceReverse_symbolNotFound();
}

void test_findSpaceReverse_commonCase() {
    char *testWord = "Hello  Hello ";
    char *res = findSpaceReverse(testWord + 10, testWord);
    assert(*res == *(testWord + 6));
}

void test_findSpaceReverse_symbolNotFound() {
    char *testWord = "HelloHello";
    char *res = findSpaceReverse(testWord + 7, testWord + 0);
    assert(*res == *(testWord));
}

void test_findSpaceReverse() {
    test_findSpaceReverse_commonCase();
    test_findSpaceReverse_symbolNotFound();
}
void test() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}

int main() {
    test();

    return 0;
}
