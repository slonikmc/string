//
// Created by Akelk on 07.03.2022.
//

#include "isEqualWordsInTwoStrings.h"
#include "assert.h"

bool isEqualWordsInString(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;
    return false;
}

void test_isEqualWordsInString_emptyString() {
    char s[] = "";
    assert(isEqualWordsInString(s) == false);
}

void test_isEqualWordsInString_onlySpaces() {
    char s[] = "              ";
    assert(isEqualWordsInString(s) == false);
}

void test_isEqualWordsInString_haveSameWords() {
    char s[] = "Hello Hihi World Hello";
    assert(isEqualWordsInString(s) == true);
}

void test_isEqualWordsInString_dontHaveSameWords() {
    char s[] = "Hello Hi Bonjur Privet";
    assert(isEqualWordsInString(s) == false);
}

void test_isEqualWordsInString() {
    test_isEqualWordsInString_emptyString();
    test_isEqualWordsInString_onlySpaces();
    test_isEqualWordsInString_dontHaveSameWords();
    test_isEqualWordsInString_haveSameWords();
}