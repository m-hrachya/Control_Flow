#include "lib.h"

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* itoa(int num) {
    int i = 0;
    int isNegative = 0;
    char* str = (char*)malloc(12 * sizeof(char));

    if (str == NULL) {
        return NULL;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    do {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    } while (num != 0);

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';
    reverse(str, i);

    return str;
}

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
        } else if (!strcmp(token, "(")) {
            push(rpn_expression_template, token);
        } else if(!strcmp(token, ")")) {
            while (!is_empty(rpn_expression_template) && !strcmp(peek(rpn_expression_template), "(")) {
                strcat(rpn_expression_template->expression, pop(rpn_expression_template));
                strcat(rpn_expression_template->expression, " ");
            }
            pop(rpn_expression_template);
        } else { // Mark 1: Bad Expression checked!
            printf("Invalid expression entered! Can't convert to RPN!\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }
    while (!is_empty(rpn_expression_template)) {
        strcat(rpn_expression_template->expression, pop(rpn_expression_template));
        strcat(rpn_expression_template->expression, " ");
    }
    return rpn_expression_template;
}

rpn_t * calculate_rpn(rpn_t * rpn_expression_template) {
    rpn_t * result_template = init_rpn_exp();
    char * token = strtok(rpn_expression_template->expression, " ");
    while (token) {
        if (is_number(token)) {
            push(result_template, token);
        } else {
            int num1 = atoi(pop(result_template));
            int num2 = atoi(pop(result_template));
            int res = 0;
            if (!strcmp(token, "+")) res = num2 + num1;
            else if (!strcmp(token, "-")) res = num2 - num1;
            else if (!strcmp(token, "*")) res = num2 * num1;
            else if (!strcmp(token, "/")) res = num2 / num1;
            char * res_str = itoa(res);
            push(result_template, res_str);
        }
        token = strtok(NULL, " ");
    }
    strcpy(result_template->expression, result_template->stack_of_opearators[0]);
    return result_template;
}