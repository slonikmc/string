//
// Created by Akelk on 05.03.2022.
//

#include "replace.h"
#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

}

void test_replace_commonCase() {
    char str[] = "Da Da Da Net Da Net Net";
    char w1[] = "Net";
    char w2[] = "Da";
    replace(str, w1, w2);
    ASSERT_STRING("Da Da Da Da Da NET Da", str);
}

void test_replace() {
    test_replace_commonCase();
}