#ifndef BOLT_CHECK_TEMP_FUNCTION_H
#define BOLT_CHECK_TEMP_FUNCTION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#define STR_LINE puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")

typedef struct
{
    unsigned int bolt_name;       // диаметр болта
    double washer_thickness;      // толщина шайбы
    double nut_height;            // высота гайки
    unsigned int thread_length;   // длина резьбы
    double thread_pitch;          // шаг резьбы
    double chamfer;               // фаска
} bolt;

/* Массив под входные данные
 * connect_package[0] - диаметр болта
 * connect_package[1] - длина болта
 * connect_package[2] - толщина детали (деталей) под головкой болта
 * connect_package[3] - толщина детали под гайкой
 * connect_package[4] - количество шайб под головкой болта
 * connect_package[5] - количество шайб под гайкой
*/
extern int connect_package[6];

// Массив под длины болтов
extern int bolt_length[38];

// Флаг ГОСТ
extern int flag_g;

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
void bolt_length_check_7798(void);

#endif //BOLT_CHECK_TEMP_FUNCTION_H
