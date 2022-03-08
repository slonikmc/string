//bool wordsMadeOfIdenticalLetters(char *s) {
// Created by Akelk on 08.03.2022.
//

#include "isEqualWordsInTwoStrings.h"
#include "wordsMadeOfIdenticalLetters.h"
#include "stdlib.h"
#include "assert.h"

int cmp_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool wordsMadeOfIdenticalLetters(char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer = '\0';
    getBagOfWords(&_bag, _stringBuffer);
    for (int i = 0; i < _bag.size; i++) {
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), cmp_char);
    }

    return isEqualWordsInString(_stringBuffer);
}

void test_wordsMadeOfIdenticalLetters_emptyString() {
    char s[] = "";
    assert(wordsMadeOfIdenticalLetters(s) == false);
}

void test_wordsMadeOfIdenticalLetters_onlySpaces() {
    char s[] = "              ";
    assert(wordsMadeOfIdenticalLetters(s) == false);
}

void test_wordsMadeOfIdenticalLetters_onlyOneWord() {
    char s[] = "ABOBA";
    assert(wordsMadeOfIdenticalLetters(s) == false);
}

void test_wordsMadeOfIdenticalLetters_noWordsWithAllSameLetters() {
    char s[] = "ABOBA BABAA ABOBO ABOBABA";
    assert(wordsMadeOfIdenticalLetters(s) == false);
}

void test_wordsMadeOfIdenticalLetters_haveWordsWithSameLetters() {
    char s[] = "ABOBA BOBAA";
    assert(wordsMadeOfIdenticalLetters(s) == true);
}

void test_wordsMadeOfIdenticalLetters() {
    test_wordsMadeOfIdenticalLetters_emptyString();
    test_wordsMadeOfIdenticalLetters_onlySpaces();
    test_wordsMadeOfIdenticalLetters_onlyOneWord();
    test_wordsMadeOfIdenticalLetters_noWordsWithAllSameLetters();
    test_wordsMadeOfIdenticalLetters_haveWordsWithSameLetters();
}