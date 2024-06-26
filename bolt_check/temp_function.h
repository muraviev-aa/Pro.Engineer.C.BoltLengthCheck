#ifndef BOLT_CHECK_TEMP_FUNCTION_H
#define BOLT_CHECK_TEMP_FUNCTION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#define STR_LINE puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
#define ARR_SIZE_LENGTH 35 // число чисел в массиве длин болтов

typedef struct
{
    unsigned int bolt_name;
    double washer_thickness;
    double nut_height;
    unsigned int thread_length;
    double thread_pitch;
    double chamfer;
} bolt;

typedef struct
{
    int arr_length[ARR_SIZE_LENGTH];
} bolt_length;

// Массив под входные данные
extern int connect_package[6];

void print_info(void);
void print_help(void);
void print_input_data(int *arr);
int open_file(FILE **fptr, char *name_file);
void print(bolt *arr, int size_struct);
void add_record(bolt info[], int number, unsigned int bolt_name, double washer_thickness,
                double nut_height, unsigned int thread_length, double thread_pitch, double chamfer);
int read_data_file(FILE **fptr, bolt info[]);
void bolt_diam_check(int diam);
int bolt_check_thread(bolt info[], int number, int *arr);
int bolt_tip_check(bolt info[], int number, int *arr);
void print_result_check(int res1_2, int res3);

#endif //BOLT_CHECK_TEMP_FUNCTION_H
