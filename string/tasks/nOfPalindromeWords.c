//
// Created by Akelk on 05.03.2022.
//

#include "nOfPalindromeWords.h"
#include "../string_.h"
#include <assert.h>

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


size_t nOfPalindromeWords(char *s) {
    char *begin = s;
    char *end = getEndOfString(s);
    size_t nPalindromes = 0;
    char *iComma = find(begin, end, ',');
    while (*begin != *end) {
        begin = findNonSpace(begin);
        nPalindromes += isPalindrome(begin, iComma);
        begin = iComma + 1;
        iComma = find(begin, end, ',');
    }

    return nPalindromes;
}

void test_nOfPalindromeWords_emptyString() {
    char *str = "";
    assert(nOfPalindromeWords(str) == 0);
    printf("test_nOfPalindromeWords_emptyString - OK\n");
}

void test_nOfPalindromeWords_emptyWords() {
    char *str = "     ,  , ,      ";
    assert(nOfPalindromeWords(str) == 0);
    printf("test_nOfPalindromeWords_emptyWords - OK\n");
}

void test_nOfPalindromeWords_noSpaces() {
    char *str = "abba,all,error,bob";
    assert(nOfPalindromeWords(str) == 2);
    printf("test_nOfPalindromeWords_noSpaces - OK\n");
}

void test_nOfPalindromeWords_commonCase() {
    char *str = "   abba,all, error, bob";
    assert(nOfPalindromeWords(str) == 2);
    printf("test_nOfPalindromeWords_commonCase - OK\n");
}

void test_nOfPalindromeWords() {
    test_nOfPalindromeWords_emptyString();
    test_nOfPalindromeWords_emptyWords();
    test_nOfPalindromeWords_noSpaces();
    test_nOfPalindromeWords_commonCase();
}