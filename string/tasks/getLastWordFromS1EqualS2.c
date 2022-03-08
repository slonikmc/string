//
// Created by Akelk on 08.03.2022.
//

#include "getLastWordFromS1EqualS2.h"

WordDescriptor getLastWordFromS1EqualS2(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word;
    for (int i = _bag.size - 1; i >= 0; i--)
        for (int j = _bag2.size - 1; j >= 0; j--)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                word = _bag.words[i];
                return word;
            }

    return (WordDescriptor) {0, 0};
}

void test_getLastWordFromS1EqualS2_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = getLastWordFromS1EqualS2(s1, s2);
    char str[MAX_STRING_SIZE];
    wordDescriptorToString(word, str);
    ASSERT_STRING ("", str);
}

void test_getLastWordFromS1EqualS2_onlySpaces() {
    char s1[] = "          ";
    char s2[] = "          ";
    WordDescriptor word = getLastWordFromS1EqualS2(s1, s2);
    char str[MAX_STRING_SIZE];
    wordDescriptorToString(word, str);
    ASSERT_STRING ("", str);
}

void test_getLastWordFromS1EqualS2_oneWordsEqual() {
    char s1[] = "Hello";
    char s2[] = "Hello";
    WordDescriptor word = getLastWordFromS1EqualS2(s1, s2);
    char str[MAX_STRING_SIZE];
    wordDescriptorToString(word, str);
    ASSERT_STRING ("Hello", str);
}

void test_getLastWordFromS1EqualS2_noHaveEqualWords() {
    char s1[] = "Hello Hi Bonjur Privet";
    char s2[] = "Bye Zdraste Kuku";
    WordDescriptor word = getLastWordFromS1EqualS2(s1, s2);
    char str[MAX_STRING_SIZE];
    wordDescriptorToString(word, str);
    ASSERT_STRING ("", str);
}

void test_getLastWordFromS1EqualS2_commonCase() {
    char s1[] = "Hello Hi Bonjur Privet";
    char s2[] = "Hi Nu Privet";
    WordDescriptor word = getLastWordFromS1EqualS2(s1, s2);
    char str[MAX_STRING_SIZE];
    wordDescriptorToString(word, str);
    ASSERT_STRING ("Privet", str);
}

void test_getLastWordFromS1EqualS2() {
    test_getLastWordFromS1EqualS2_emptyStrings();
    test_getLastWordFromS1EqualS2_onlySpaces();
    test_getLastWordFromS1EqualS2_oneWordsEqual();
    test_getLastWordFromS1EqualS2_noHaveEqualWords();
    test_getLastWordFromS1EqualS2_commonCase();
}
