//
// Created by Akelk on 08.03.2022.
//

#include "addLastWordsS2ToS1.h"

void addLastWordsS2ToS1(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    char *sCopy = s1;
    int i = 0;
    if (_bag.size > _bag2.size) {
        sCopy = s2;
        for (; i < _bag2.size; i++) {
            sCopy = copy(_bag2.words[i].begin, _bag2.words[i].end, sCopy);
            *sCopy = ' ';
            sCopy++;
        }
        for (; i < _bag.size; i++) {
            sCopy = copy(_bag.words[i].begin, _bag
            .words[i].end, sCopy);
            *sCopy = ' ';
            sCopy++;
        }
    } else if (_bag.size < _bag2.size) {
        for (; i < _bag.size; i++) {
            sCopy = copy(_bag.words[i].begin, _bag.words[i].end, sCopy);
            *sCopy = ' ';
            sCopy++;
        }
        for (; i < _bag2.size; i++) {
            sCopy = copy(_bag2.words[i].begin, _bag2.words[i].end, sCopy);
            *sCopy = ' ';
            sCopy++;
        }
    }

    if (sCopy != s1 || sCopy != s2)
        sCopy--;
    *sCopy = '\0';
}

void test_addLastWordsS2ToS1_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    addLastWordsS2ToS1(s1, s2);
    ASSERT_STRING("", s1);
}

void test_addLastWordsS2ToS1_onlySpaces() {
    char s1[MAX_STRING_SIZE] = "      ";
    char s2[MAX_STRING_SIZE] = "    ";
    addLastWordsS2ToS1(s1, s2);
    ASSERT_STRING("      ", s1);
}

void test_addLastWordsS2ToS1_addToS1() {
    char s1[MAX_STRING_SIZE] = "Hello world";
    char s2[MAX_STRING_SIZE] = "Its me you know";
    addLastWordsS2ToS1(s1, s2);
    ASSERT_STRING("Hello world you know", s1);
}

void test_addLastWordsS2ToS1_addToS2() {
    char s1[MAX_STRING_SIZE] = "Its me you know";
    char s2[MAX_STRING_SIZE] = "Hello world";
    addLastWordsS2ToS1(s1, s2);
    ASSERT_STRING("Hello world you know", s2);
}

void test_addLastWordsS2ToS1 () {
    test_addLastWordsS2ToS1_emptyStrings();
    test_addLastWordsS2ToS1_onlySpaces();
    test_addLastWordsS2ToS1_addToS1();
    test_addLastWordsS2ToS1_addToS2();
}
