#include <stdio.h>
#include "calc.h"

// Вычисление результата арифметического выражения
int calculate(int left_operand, char operator, int right_operand, int *error) {
    *error = 0;
    switch (operator) {
        case '+': return left_operand + right_operand;
        case '-': return left_operand - right_operand;
        case '*': return left_operand * right_operand;
        case '%':
            if (right_operand == 0) {
                *error = 1; // Деление на 0
                return 0;
            }
            return left_operand % right_operand;
        default:
            *error = 1; // Некорректный оператор
            return 0;
    }
}

// Дешифрование результатов
char *decrypt_results(int *results, int size, int key) {
    char *decrypted_string = (char *)malloc((size + 1) * sizeof(char));
    if (!decrypted_string) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        decrypted_string[i] = (char)(results[i] - key);
    }
    decrypted_string[size] = '\0'; // Завершающий символ строки
    return decrypted_string;
}
