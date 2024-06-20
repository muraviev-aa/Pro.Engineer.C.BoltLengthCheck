#ifndef BOLT_CHECK_TEMP_FUNCTION_H
#define BOLT_CHECK_TEMP_FUNCTION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
    unsigned int bolt_name;
    double washer_thickness;
    double nut_height;
    int thread_length;
    double thread_pitch;
    double chamfer;
} bolt;

#endif //BOLT_CHECK_TEMP_FUNCTION_H
