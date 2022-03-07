//
// Created by Akelk on 26.02.2022.
//

#ifndef INC_5E_STRING_STRING__H
#define INC_5E_STRING_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
 __FILE__ , __FUNCTION__ , __LINE__ )

# define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

// хранит начало и конец каждого слова исходной строки
typedef struct BagOfWords {
    WordDescriptor words [ MAX_N_WORDS_IN_STRING ];
    size_t size ;
} BagOfWords ;

static char _stringBuffer [MAX_STRING_SIZE + 1];

BagOfWords _bag ;

BagOfWords _bag2 ;

// Возвращает количество символов в строке, не считая символ конца строки.
size_t strlen_(const char *begin);

// Возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между begin и end.
// Если символ не найден возвращается значение end.
char *find(char *begin, char *end, int ch);

// Возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа.
char *findNonSpace(char *begin);

// Возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.
char *findSpace(char *begin);

// Возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend
// (адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

// Функция возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs);

// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

// Возвращает указатель на конец строки.
char *getEndOfString(char *begin);

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line);

// Вернёт значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

// получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s);

void wordDescriptorToString(WordDescriptor word, char *destination);

#endif //INC_5E_STRING_STRING__H