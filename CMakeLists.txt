cmake_minimum_required(VERSION 3.20)
project(5e_string C)

set(CMAKE_C_STANDARD 11)

add_executable(5e_string main.c)

add_library(str string/string_.h string/string_.c
         string/test_string_.h string/test_string_.c
         string/tasks/removeNonLetters.h string/tasks/removeNonLetters.c                       #task 1
         string/tasks/removeExtraSpaces.h string/tasks/removeExtraSpaces.c                     #task 2
         string/tasks/digitsToEnd.h string/tasks/digitsToEnd.c                                 #task 3
         string/tasks/numberTurnIntoSpaces.h string/tasks/numberTurnIntoSpaces.c               #task 4
         string/tasks/replace.h string/tasks/replace.c                                         #task 5
         string/tasks/isLexicallyOrderedSentence.h string/tasks/isLexicallyOrderedSentence.c   #task 6
         string/tasks/nOfPalindromeWords.h string/tasks/nOfPalindromeWords.c                   #task 8
         string/tasks/alternatingWordsSentence.h string/tasks/alternatingWordsSentence.c       #task 9
         string/tasks/reverseString.h string/tasks/reverseString.c                             #task 10
        )

target_link_libraries(5e_string str)

