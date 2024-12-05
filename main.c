#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Недостаточно аргументов.\n");
        return 1;
    }

    int results_count = 0;
    int *results = (int *)malloc((argc / 3) * sizeof(int)); 
    if (!results) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return 1;
    }

    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-k") == 0) break; 
        if (i + 2 >= argc) {
            fprintf(stderr, "Некорректные аргументы.\n");
            free(results);
            return 1;
        }

        int left_operand = atoi(argv[i]);
        char operator = argv[i + 1][0];
        int right_operand = atoi(argv[i + 2]);

        int error;
        int result = calculate(left_operand, operator, right_operand, &error);
        if (error) {
            fprintf(stderr, "Ошибка в выражении: %d %c %d\n", left_operand, operator, right_operand);
            free(results);
            return 1;
        }

        results[results_count++] = result;
        printf("Ответ №%d: %d\n", results_count, result);
        i += 3;
    }

    if (strcmp(argv[i], "-k") != 0 || i + 1 >= argc) {
        fprintf(stderr, "Ключ дешифрования отсутствует или некорректен.\n");
        free(results);
        return 1;
    }

    int key = atoi(argv[i + 1]);
    char *decrypted_string = decrypt_results(results, results_count, key);
    if (!decrypted_string) {
        free(results);
        return 1;
    }

    printf("Результирующая строка: %s\n", decrypted_string);

    free(results);
    free(decrypted_string);
    return 0;
}
