//
// Created by Akelk on 07.03.2022.
//

#include "isLexicallyOrderedSentence.h"
#include "assert.h"

bool isLexicallyOrderedSentence(char *s) {
    char *begin = s;
    WordDescriptor word;
    if (!getWord(begin, &word))
        return true;
    WordDescriptor lastWord = word;
    begin = lastWord.end;
    while (getWord(begin, &word)) {
        if (areWordsEqual(lastWord, word) > 0)
            return false;
        lastWord = word;
        begin = word.end;
    }

    return true;
}

void test_isLexicallyOrderedSentence_emptyString() {
    char str[] = "";
    assert(isLexicallyOrderedSentence(str));
}

void test_isLexicallyOrderedSentence_onlySpaces() {
    char str[] = "        ";
    assert(isLexicallyOrderedSentence(str));
}

void test_isLexicallyOrderedSentence_notOrderedSentence() {
    char str[] = "i dont know what i should to write here...";
    assert(!isLexicallyOrderedSentence(str));
}

void test_isLexicallyOrderedSentence_orderedSentence() {
    char str[] = "ahello, bhello      hello!     ";
    assert(isLexicallyOrderedSentence(str));
}

void test_isLexicallyOrderedSentence() {
    test_isLexicallyOrderedSentence_emptyString();
    test_isLexicallyOrderedSentence_onlySpaces();
    test_isLexicallyOrderedSentence_notOrderedSentence();
    test_isLexicallyOrderedSentence_orderedSentence();
}
