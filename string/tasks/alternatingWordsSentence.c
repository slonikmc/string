//
// Created by Akelk on 07.03.2022.
//

#include "alternatingWordsSentence.h"

void alternatingWordsSentence(char *s1, char *s2, char *s) {
    if (*s1 == '\0' && *s2 == '\0') {
        *s = '\0';
        return;
    }
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            s = copy(word1.begin, word1.end, s);
            *s = ' ';
            s++;
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            s = copy(word2.begin, word2.end, s);
            *s = ' ';
            s++;
            beginSearch2 = word2.end;
        }
    }
    s--;
    *s = '\0';
}


void test_alternatingWordsSentence_emptyString() {
    char s1[] = "";
    char s2[] = "";
    char s[MAX_STRING_SIZE];
    alternatingWordsSentence(s1, s2, s);
    ASSERT_STRING("", s);
}

void test_alternatingWordsSentence_onlySpaces() {
    char s1[] = "    ";
    char s2[] = "    ";
    char s[MAX_STRING_SIZE];
    alternatingWordsSentence(s1, s2, s);
    ASSERT_STRING("", s);
}

void test_alternatingWordsSentence_commonCase() {
    char s1[] = "He He";
    char s2[] = "Ha Ha HA HA";
    char s[MAX_STRING_SIZE];
    alternatingWordsSentence(s1, s2, s);
    ASSERT_STRING("He Ha He Ha HA HA", s);
}

void test_alternatingWordsSentence() {
    test_alternatingWordsSentence_emptyString();
    test_alternatingWordsSentence_onlySpaces();
    test_alternatingWordsSentence_commonCase();
}