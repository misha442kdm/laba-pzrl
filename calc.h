#ifndef CALC_H
#define CALC_H

// Функция для вычисления результата арифметического выражения
int calculate(int left_operand, char operator, int right_operand, int *error);

// Функция для дешифрования результата
char *decrypt_results(int *results, int size, int key);

#endif // CALC_H
