//
// Created by Akelk on 07.03.2022.
//

#include "getWordBeforeFirstWordWithA.h"
#include "../string_.h"
#include "assert.h"

bool isA(WordDescriptor word) {
    while (word.begin != word.end) {
        if (*word.begin == 'a' || *word.begin == 'A')
            return true;
        word.begin++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s,
                                       char **beginWordBefore, char **endWordBefore) {
    WordDescriptor lastWord;
    char *begin = s;
    if (!getWord(begin, &lastWord))
        return EMPTY_STRING;
    if (isA(lastWord))
        return FIRST_WORD_WITH_A;
    begin = lastWord.end;
    WordDescriptor word;
    while (getWord(begin, &word)) {
        if (isA(word)) {
            *beginWordBefore = lastWord.begin;
            *endWordBefore = lastWord.end;
            return WORD_FOUND;
        }
        lastWord = word;
        begin = word.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *beginWordBefore, *endWordBefore;
    if (getWordBeforeFirstWordWithA(s, &beginWordBefore, &endWordBefore) == WORD_FOUND) {
        char *word = copy(beginWordBefore, endWordBefore, _stringBuffer);
        *word = '\0';
        printf("%s", word);
    }
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);
    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);
    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING ("BC", got);
    char s4[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}



