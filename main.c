#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/digitsToEnd.h"
#include "string/tasks/numberTurnIntoSpaces.h"
#include "string/tasks/nOfPalindromeWords.h"
#include "string/tasks/isLexicallyOrderedSentence.h"
#include "string/tasks/alternatingWordsSentence.h"
#include "string/tasks/reverseString.h"
#include "string/tasks/getWordBeforeFirstWordWithA.h"
#include "string/tasks/getLastInString1FromString2.h"
#include "string/tasks/isEqualWordsInTwoStrings.h"
#include "string/tasks/wordsMadeOfIdenticalLetters.h"
#include "string/tasks/getStringWithoutLastWord.h"
#include "string/tasks/getLastWordFromS1EqualS2.h"
#include "string/tasks/deletePalindromeWords.h"

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
    test_getLastInString1FromString2();
    test_isEqualWordsInString();
    test_wordsMadeOfIdenticalLetters();
    test_getStringWithoutLastWord();
    test_getLastWordFromS1EqualS2();
    test_deletePalindromeWords();

    return 0;
}