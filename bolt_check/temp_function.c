#include <stdio.h>
#include "temp_function.h"

// Открыть файл
int open_file(FILE **fptr, char *name_file)
{
    if ((*fptr = fopen(name_file, "r")) == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    return 0;
}

// Функция печати данных из массива структур по индексу
void print(bolt *arr, int size_struct)
{
    for (int i = 0; i < size_struct; i++)
        printf("%d %.1f %.1f %d %.1f %.1f \n",
               arr[i].bolt_name,
               arr[i].washer_thickness,
               arr[i].nut_height,
               arr[i].thread_length,
               arr[i].thread_pitch,
               arr[i].chamfer);
}

// Добавление записей
void add_record(bolt info[], int number, unsigned int bolt_name, double washer_thickness,
                double nut_height, unsigned int thread_length, double thread_pitch, double chamfer)
{
    info[number].bolt_name = bolt_name;
    info[number].washer_thickness = washer_thickness;
    info[number].nut_height = nut_height;
    info[number].thread_length = thread_length;
    info[number].thread_pitch = thread_pitch;
    info[number].chamfer = chamfer;
}

// Считываем данные из файла
int read_data_file(FILE **fptr, bolt info[])
{
    unsigned int bolt_name, thread_length;
    double washer_thickness, nut_height, thread_pitch, chamfer;
    int count = 0;
    while (fscanf(*fptr, "%d;%lf;%lf;%d;%lf;%lf", &bolt_name, &washer_thickness, &nut_height,
                            &thread_length, &thread_pitch, &chamfer) > 0)
    {
        add_record(info, count, bolt_name, washer_thickness, nut_height, thread_length, thread_pitch, chamfer);
        count++;
    }
    return count;
}
