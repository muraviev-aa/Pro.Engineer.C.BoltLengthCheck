#ifndef BOLT_CHECK_TEMP_FUNCTION_H
#define BOLT_CHECK_TEMP_FUNCTION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#define STR_LINE puts("#########################################################################")

typedef struct
{
    unsigned int bolt_name;
    double washer_thickness;
    double nut_height;
    unsigned int thread_length;
    double thread_pitch;
    double chamfer;
} bolt;

void print_info(void);
void print_help(void);
int open_file(FILE **fptr, char *name_file);
void print(bolt *arr, int size_struct);
void add_record(bolt info[], int number, unsigned int bolt_name, double washer_thickness,
                double nut_height, unsigned int thread_length, double thread_pitch, double chamfer);
int read_data_file(FILE **fptr, bolt info[]);

#endif //BOLT_CHECK_TEMP_FUNCTION_H
