//
// Created by Akelk on 08.03.2022.
//

#include "getStringWithoutLastWord.h"

void getStringWithoutLastWord(char *s) {
    WordDescriptor lastWord;
    getWordReverse(getEndOfString(s) - 1, s - 1, &lastWord);
    char *begin = s;
    char *sCopy = s;
    WordDescriptor word;
    while (getWord(begin, &word)) {
        if (areWordsEqual(word, lastWord) != 0) {
            sCopy = copy(word.begin, word.end, sCopy);
            *sCopy = ' ';
            sCopy++;
        }
        begin = word.end;
    }

    if (sCopy != s)
        sCopy--;
    *sCopy = '\0';
}

void test_getStringWithoutLastWord_emptyString() {
    char s[] = "";
    getStringWithoutLastWord(s);
    ASSERT_STRING("", s);
}

void test_getStringWithoutLastWord_onlySpaces() {
    char s[] = "        ";
    getStringWithoutLastWord(s);
    ASSERT_STRING("", s);
}

void test_getStringWithoutLastWord_onlyOneWord() {
    char s[] = "man";
    getStringWithoutLastWord(s);
    ASSERT_STRING("", s);
}

void test_getStringWithoutLastWord_commonCase() {
    char s[] = "Hello man hello Man man man";
    getStringWithoutLastWord(s);
    ASSERT_STRING("Hello hello Man", s);
}

void test_getStringWithoutLastWord() {
    test_getStringWithoutLastWord_emptyString();
    test_getStringWithoutLastWord_onlySpaces();
    test_getStringWithoutLastWord_onlyOneWord();
    test_getStringWithoutLastWord_commonCase();
}

