//
// Created by Akelk on 08.03.2022.
//

#include "isAllAlphasOfWordInString.h"
#include "assert.h"

#define nCharSymbols 255

bool isAllAlphasOfWordInString(WordDescriptor word, char *s) {
    if (*s == '\0' || word.begin == word.end)
        return false;
    bool charSymbolsFromString[nCharSymbols] = {false};
    while (*s != '\0') {
        charSymbolsFromString[*s] = true;
        s++;
    }
    char *begin = word.begin;
    while (begin < word.end) {
        if (charSymbolsFromString[*begin] == false)
            return false;
        begin++;
    }

    return true;
}

void test_isAllAlphasOfWordInString_emptyWordAndString() {
    char word[] = "";
    WordDescriptor word_ = {word, getEndOfString(word)};
    char s[] = "";
    assert(!isAllAlphasOfWordInString(word_, s));
}

void test_isAllAlphasOfWordInString_emptyString() {
    char word[] = "hello";
    WordDescriptor word_ = {word, getEndOfString(word)};
    char s[] = "";
    assert(!isAllAlphasOfWordInString(word_, s));
}

void test_isAllAlphasOfWordInString_emptyWord() {
    char word[] = "";
    WordDescriptor word_ = {word, getEndOfString(word)};
    char s[] = "ell ooooooppp hell hello oll";
    assert(!isAllAlphasOfWordInString(word_, s));
}
void test_isAllAlphasOfWordInString_notAllAlphasFromWordInString() {
    char word[] = "helloqq";
    WordDescriptor word_ = {word, getEndOfString(word)};
    char s[] = "ell ooooooppp hell hello oll";
    assert(!isAllAlphasOfWordInString(word_, s));
}
void test_isAllAlphasOfWordInString_allAlphasOfWordInString() {
    char word[] = "hello";
    WordDescriptor word_ = {word, getEndOfString(word)};
    char s[] = "ell ooooooppp hell hello oll";
    assert(isAllAlphasOfWordInString(word_, s));
}

void test_isAllAlphasOfWordInString() {
    test_isAllAlphasOfWordInString_emptyWordAndString();
    test_isAllAlphasOfWordInString_emptyWord();
    test_isAllAlphasOfWordInString_emptyString();
    test_isAllAlphasOfWordInString_notAllAlphasFromWordInString();
    test_isAllAlphasOfWordInString_allAlphasOfWordInString();
}
