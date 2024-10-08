#ifndef LIB
#define LIB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 32
#define EXPRESSION_SIZE 32
#define RPN_EXPRESSION_SIZE 256 // Mark 2: Changed from 32 to 256
#define WORD_SIZE 8
#define LOW_PRECEDENCE 1
#define HIGH_PRECEDENCE 2

typedef struct rpn_t {
    char stack_of_opearators[STACK_SIZE][WORD_SIZE];
    int top;
    char expression[RPN_EXPRESSION_SIZE];
} rpn_t;

void reverse(char str[], int length);
char* itoa(int num);
rpn_t * init_rpn_exp();
int is_number(char * str);
int get_precedence(char * operator);
char * push(rpn_t * rpn_expression, char * operator);
char * peek(rpn_t * rpn_expression);
char * pop(rpn_t * rpn_expression);
int is_empty(rpn_t * rpn_expression);
rpn_t * convert_to_rpn(char * expression);
rpn_t * calculate_rpn(rpn_t * rpn_expression_template);

#endif