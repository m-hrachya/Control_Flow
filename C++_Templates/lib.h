#ifndef LIB
#define LIB

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#define FILE_SIZE 32
#define LINE_SIZE 128
#define KEY_COUNT 64
#define VALUE_COUNT 64
#define KEY_SIZE 8
#define VALUE_SIZE 16
#define ARG_SIZE 64
#define COMMAND_SIZE 32
#define DELIMETER " "

typedef struct template_t {
    char template_keys[KEY_COUNT][KEY_SIZE];
    char template_values[VALUE_COUNT][VALUE_SIZE];
} template_t;

char * get_file_name(const char * arg);
FILE * get_changing_file(char * file_name);
template_t * initialize_templates(int argc, const char * argv[]);
char * transform_line(char * line, template_t * templates, int * checker);

#endif