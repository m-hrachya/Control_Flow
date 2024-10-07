#include "lib.h"

int main() {
    char * infix_expression = (char *) calloc(sizeof(char), EXPRESSION_SIZE);
    assert(infix_expression != NULL);
    printf("Enter expression: ");
    fgets(infix_expression, EXPRESSION_SIZE - 2, stdin); 
    // Mark 3: Fgets reads until \n is reached, and
    // adds the \n character on the end of the string.
    // I used EXPRESSION_SIZE - 2 because I need to read
    // as many characters so that the array can contain
    // all readed characters + \n + \0. As I know 100% that
    // at the and of the fgets() function call there will be
    // \n in the array before \0, I change it to \0 with the 
    // next instruction. 
    infix_expression[strlen(infix_expression) - 1] = '\0';
    rpn_t * rpn_expression = convert_to_rpn(infix_expression);
    printf("RPN version: %s\n", rpn_expression->expression);
    free(rpn_expression);
    free(infix_expression);
    return 0;
}