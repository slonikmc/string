//
// Created by Akelk on 07.03.2022.
//

#include "isEqualWordsInTwoStrings.h"
#include "assert.h"

bool isEqualWordsInTwoStrings(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for (int i = _bag.size - 1; i >= 0; i--)
        for (int j = _bag2.size - 1; j >= 0; j--)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0)
                return true;
    return false;
}

void test_isEqualWordsInTwoStrings_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    assert(isEqualWordsInTwoStrings(s1, s2) == false);
}

void test_isEqualWordsInTwoStrings_onlySpaces() {
    char s1[] = "              ";
    char s2[] = "      ";
    assert(isEqualWordsInTwoStrings(s1, s2) == false);
}

void test_isEqualWordsInTwoStrings_haveSameWords() {
    char s1[] = "Hello Hello World Hello";
    char s2[] = "Fish Potato Hello Hi hello";
    assert(isEqualWordsInTwoStrings(s1, s2) == true);
}

void test_isEqualWordsInTwoStrings_dontHaveSameWords() {
    char s1[] = "Hello Hello World Hello";
    char s2[] = "Fish Potato itsCanBeHelloButNot Hi";
    assert(isEqualWordsInTwoStrings(s1, s2) == false);
}

void test_isEqualWordsInTwoStrings() {
    test_isEqualWordsInTwoStrings_emptyStrings();
    test_isEqualWordsInTwoStrings_onlySpaces();
    test_isEqualWordsInTwoStrings_dontHaveSameWords();
    test_isEqualWordsInTwoStrings_haveSameWords();
}