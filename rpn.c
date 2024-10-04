#include "lib.h"

int main() {
    char * infix_expression = (char *) calloc(sizeof(char), EXPRESSION_SIZE);
    assert(infix_expression != NULL);
    printf("Enter expression: ");
    fgets(infix_expression, EXPRESSION_SIZE - 2, stdin);
    infix_expression[strlen(infix_expression) - 1] = '\0';
    rpn_t * rpn_expression = convert_to_rpn(infix_expression);
    printf("RPN version: %s\n", rpn_expression->expression);
    free(rpn_expression);
    free(infix_expression);
    return 0;
}