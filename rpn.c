#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 32
#define EXPRESSION_SIZE 32
#define RPN_EXPRESSION_SIZE 32
#define WORD_SIZE 8
#define LOW_PRECEDENCE 1
#define HIGH_PRECEDENCE 2

typedef struct rpn_t {
    char stack_of_opearators[STACK_SIZE][WORD_SIZE];
    int top;
    char expression[RPN_EXPRESSION_SIZE];
} rpn_t;

int is_number(char * str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

rpn_t * init_rpn_exp() {
    rpn_t * rpn_expression_tamplate = (rpn_t *) calloc(sizeof(rpn_t), 1);
    assert(rpn_expression_tamplate != NULL);
    rpn_expression_tamplate->top = -1;
    return rpn_expression_tamplate;
}

int get_precedence(char * operator) {
    if (!strcmp(operator, "+") || !strcmp(operator, "-")) return LOW_PRECEDENCE;
    else return HIGH_PRECEDENCE;
}

char * push(rpn_t * rpn_expression, char * operator) {
    strcpy(rpn_expression->stack_of_opearators[++rpn_expression->top], operator);
    return operator;
}

char * peek(rpn_t * rpn_expression) {
    return rpn_expression->stack_of_opearators[rpn_expression->top];
}

char * pop(rpn_t * rpn_expression) {
    return rpn_expression->stack_of_opearators[(rpn_expression->top)--];
}

int is_empty(rpn_t * rpn_expression) { return rpn_expression->top == -1 ? 1 : 0; }

rpn_t * convert_to_rpn(char * expression) {
    assert(expression != NULL);
    rpn_t * rpn_expression_template = init_rpn_exp();
    char * token = strtok(expression, " ");
    while (token) {
        if (is_number(token)) {
            strcat(rpn_expression_template->expression, token);
            strcat(rpn_expression_template->expression, " ");
        } else if (!strcmp(token, "+") || !strcmp(token, "-") || !strcmp(token, "*") || !strcmp(token, "/")){
            while (!is_empty(rpn_expression_template) && (get_precedence(token) <= get_precedence(peek(rpn_expression_template)))) {
                strcat(rpn_expression_template->expression, pop(rpn_expression_template));
                strcat(rpn_expression_template->expression, " ");
            }
            push(rpn_expression_template, token);
        }
        token = strtok(NULL, " ");
    }
    while (!is_empty(rpn_expression_template)) {
        strcat(rpn_expression_template->expression, pop(rpn_expression_template));
        strcat(rpn_expression_template->expression, " ");
    }
    return rpn_expression_template;
}

int main() {
    char * infix_expression = (char *) calloc(sizeof(char), EXPRESSION_SIZE);
    assert(infix_expression != NULL);
    printf("Enter expression: ");
    fgets(infix_expression, EXPRESSION_SIZE - 2, stdin);
    infix_expression[strlen(infix_expression) - 1] = '\0';
    rpn_t * rpn_expression = convert_to_rpn(infix_expression);
    printf("RPN version: %s\n", rpn_expression->expression);
    free(rpn_expression);
    return 0;
}