#include "lib.h"

char * get_file_name(const char * arg) {
    char * file_name = (char *) malloc(sizeof(char) * FILE_SIZE);
    assert(file_name != NULL);
    strcpy(file_name, arg);
    return file_name;
}

template_t * initialize_templates(int argc, const char * argv[]) {
    template_t * templates = (template_t *) malloc(sizeof(template_t)); 
    assert(templates != NULL);
    for (int i = 2, j = 0; i < argc; ++i, ++j) {
        char * tmp = (char *) malloc(sizeof(char) * ARG_SIZE);
        assert(tmp != NULL);
        strcat(tmp, argv[i]);
        char * token = strtok(tmp, "=");
        strcpy(templates->template_keys[j], token);
        token = strtok(NULL, "=");
        strcpy(templates->template_values[j], token);
        free(tmp);
    }
    return templates;
}


FILE * get_changing_file(char * file_name) {
    char * new_file_name = (char *) malloc(sizeof(char) * COMMAND_SIZE);
    assert(new_file_name != NULL);
    strcpy(new_file_name, file_name);
    new_file_name[strlen(new_file_name) - 2] = '\0';
    strcat(new_file_name, "_with_templates.c");
    FILE * file = fopen(new_file_name, "w");
    assert(file != NULL);
    free(new_file_name);
    return file;
}

char * transform_line(char * line, template_t * templates, int * checker) {
    char * transformed_line = (char *) calloc(sizeof(char), LINE_SIZE);
    char * string_part = (char *) calloc(sizeof(char),  LINE_SIZE);
    assert(string_part != NULL);
    assert(transformed_line != NULL);
    char * tmp;
    if (!strncmp(line, "//", strlen("//"))) { // LIKE STRING
        strcpy(transformed_line, line);
        return transformed_line;
    }
    tmp = strstr(line, "/*");
    if (tmp != NULL || *checker) {
        tmp = strstr(line, "*/");
        if (tmp != NULL)  {
            *checker = 0;
        } else {
            *checker = 1;
        }
        strcpy(transformed_line, line);
        return transformed_line; // LIKE STRING   
    }
    tmp = strstr(line, "\"");
    if (tmp != NULL) {
        strcpy(string_part, tmp);
        line[strlen(line) - strlen(tmp)] = '\0';
        //strcpy(transformed_line, line);
        tmp = NULL;
    }
    for (int i = 0; i < KEY_COUNT; ++i) {
        if (strlen(templates->template_keys[i])) {
            tmp = strstr(line, templates->template_keys[i]);
            if (tmp) {
                if (tmp[2] == '=' || tmp[1] == '=' || tmp[1] == ';' || tmp[1] == ',') {
                    continue;
                }
                strncpy(transformed_line, line, strlen(line) - strlen(tmp));
                strcat(transformed_line, templates->template_values[i]);
                strcat(transformed_line, tmp + 1);
                strcpy(line, transformed_line);
                memset(transformed_line, 0, LINE_SIZE);
                --i;
            }
        } else {
            break;
        } 
    }
    strcpy(transformed_line, line);
    if (*string_part) {
        strcat(transformed_line, string_part);
    }
    return transformed_line;
}