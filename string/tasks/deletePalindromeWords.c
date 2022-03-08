//
// Created by Akelk on 08.03.2022.
//

#include "deletePalindromeWords.h"

bool isPalindrome(char *begin, char *end) {
    if (begin != end) {
        end--;
        while (begin < end) {
            if (*begin != *end)
                return false;
            begin++;
            end--;
        }
        return true;
    }
    return false;
}

void deletePalindromeWords(char *s) {
    char *begin = s;
    char *sCopy = s;
    WordDescriptor word;
    while (getWord(begin, &word)) {
        if (!isPalindrome(word.begin, word.end)) {
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

void test_deletePalindromeWords_emptyString() {
    char s[] = "";
    deletePalindromeWords(s);
    ASSERT_STRING("", s);
}

void test_deletePalindromeWords_onlySpaces() {
    char s[] = "     ";
    deletePalindromeWords(s);
    ASSERT_STRING("", s);
}

void test_deletePalindromeWords_allPalindromes() {
    char s[] = "ababa aaa aaaa aa a";
    deletePalindromeWords(s);
    ASSERT_STRING("", s);
}

void test_deletePalindromeWords_commonCase() {
    char s[] = "abba all aaa aa queue";
    deletePalindromeWords(s);
    ASSERT_STRING("all queue", s);
}

void test_deletePalindromeWords() {
    test_deletePalindromeWords_emptyString();
    test_deletePalindromeWords_onlySpaces();
    test_deletePalindromeWords_allPalindromes();
    test_deletePalindromeWords_commonCase();
}
