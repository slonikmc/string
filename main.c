#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/digitsToEnd.h"
#include "string/tasks/numberTurnIntoSpaces.h"
#include "string/tasks/nOfPalindromeWords.h"
#include "string/tasks/isLexicallyOrderedSentence.h"
#include "string/tasks/alternatingWordsSentence.h"
#include "string/tasks/reverseString.h"
#include "string/tasks/getWordBeforeFirstWordWithA.h"

int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_redactStringCriteria();
    test_numberTurnIntoSpaces();
    test_nOfPalindromeWords();
    test_isLexicallyOrderedSentence();
    test_alternatingWordsSentence();
    //test_reverseString();
    testAll_getWordBeforeFirstWordWithA();

    return 0;
}