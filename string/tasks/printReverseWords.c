//
// Created by Akelk on 08.03.2022.
//

#include "printReverseWords.h"
#include "../string_.h"

void printWordsReverse(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = _bag.size - 1; i >= 0; i--) {
        char *endBuffer = copy(_bag.words[i].begin, _bag.words[i].end, _stringBuffer);
        *endBuffer = '\0';
        printf("%s\n", _stringBuffer);
    }
}

void test_printWordsReverse() {
    char s[] = "bye hello";
    printWordsReverse(s);
}