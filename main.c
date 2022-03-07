#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/digitsToEnd.h"
#include "string/tasks/numberTurnIntoSpaces.h"
#include "string/tasks/nOfPalindromeWords.h"
#include "string/tasks/isLexicallyOrderedSentence.h"

int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_redactStringCriteria();
    test_numberTurnIntoSpaces();
    test_nOfPalindromeWords();
    test_isLexicallyOrderedSentence();

    return 0;
}