//
// Created by Akelk on 07.03.2022.
//

#include "getLastInString1FromString2.h"

WordDescriptor getLastInString1FromString2(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word;
    for (int i = _bag.size - 1; i >= 0; i--)
        for (int j = _bag2.size - 1; j >= 0; j--)
            if (areWordsEqual(_bag.words[i], _bag2.words[j])) {
                word = _bag.words[i];
                return word;
            }

    return (WordDescriptor) {0, 0};
}

void test_getLastInString1FromString2_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = getLastInString1FromString2(s1, s2);
    char string[MAX_STRING_SIZE];
    wordDescriptorToString(word, string);
    ASSERT_STRING ("", string);
}

void test_getLastInString1FromString2_onlySpaces() {
    char s1[] = "   ";
    char s2[] = "       ";
    WordDescriptor word = getLastInString1FromString2(s1, s2);
    char string[MAX_STRING_SIZE];
    wordDescriptorToString(word, string);
    ASSERT_STRING ("", string);
}

void test_getLastInString1FromString2_commonCase() {
    char s1[] = "First Second Last";
    char s2[] = "Second Last First ABOBA";
    WordDescriptor word = getLastInString1FromString2(s1, s2);
    char string[MAX_STRING_SIZE];
    wordDescriptorToString(word, string);
    ASSERT_STRING ("Last", string);
}

void test_getLastInString1FromString2() {
    test_getLastInString1FromString2_emptyStrings();
    test_getLastInString1FromString2_onlySpaces();
    test_getLastInString1FromString2_commonCase();
}