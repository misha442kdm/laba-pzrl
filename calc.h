#ifndef CALC_H
#define CALC_H


int calculate(int left_operand, char operator, int right_operand, int *error);


char *decrypt_results(int *results, int size, int key);

#endif 
