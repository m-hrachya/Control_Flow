#include "lib.h"

int main(int argc, const char * argv[]) {
    if (argc < 3) {
        printf("Invalid arguments!\n");
        exit(EXIT_FAILURE);
    }
    char * file_name = get_file_name(argv[1]);
    FILE * read_file = fopen(file_name, "r"); 
    FILE * write_file = get_changing_file(file_name);
    assert((write_file != NULL));
    free(file_name);
    template_t * templates = initialize_templates(argc, argv); // COUNT - ARGC
    char * line = (char *) malloc(sizeof(char) * LINE_SIZE); 
    assert(line != NULL);
    int checker = 0;
    while (!feof(read_file)) {
        fgets(line, LINE_SIZE, read_file);
        char * transformed_line = transform_line(line, templates, &checker);
        fwrite(transformed_line, strlen(transformed_line), 1, write_file);
        free(transformed_line);
        memset(line, 0, LINE_SIZE);
    }
    printf("Templates are changed successfully!\n");
    free(line);
    free(templates);
    fclose(read_file);
    fclose(write_file);
    return 0;
}