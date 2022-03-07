//
// Created by Akelk on 07.03.2022.
//

#ifndef INC_5E_STRING_GETWORDBEFOREFIRSTWORDWITHA_H
#define INC_5E_STRING_GETWORDBEFOREFIRSTWORDWITHA_H

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore);

void testAll_getWordBeforeFirstWordWithA();

#endif //INC_5E_STRING_GETWORDBEFOREFIRSTWORDWITHA_H
