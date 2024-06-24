#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

// Вывод информации о приложении
void print_info(void)
{
    STR_LINE;
    puts("\tConsole application \"Checking bolt length\"");
    puts("Developer Muraviev A.A.");
    puts("All rights reserved.");
    puts("For help with the program, use the -h argument.");
    STR_LINE;
    system("pause");
}

// Печать меню HELP
void print_help(void)
{
    STR_LINE;
    puts("\t\t\t\tHELP");
    puts("~~~ List keys:");
    puts("-h\t\t\thelp application;");
    puts("-f: file_name.csv\tfile with dimensions;");
    puts("-m: thread diameter\tindicate thread diameter;");
    puts("-l: bolt length\t\tindicate bolt length;");
    puts("-s: thickness of parts\ttotal thickness of parts on the bolt head side;");
    puts("-t: thickness of part\tthickness of one part from the nut side.");
    puts("-w: washer/head\t\twasher under the bolt head;");
    puts("-n: washer/nut\t\twasher under the nut;");
    STR_LINE;
}

// Печать входных данных
void print_input_data(int *arr)
{
    STR_LINE;
    printf("\t\t\t*** ENTERED DATA ***\n");
    printf("%s%12s%12s%15s%12s%12s\n", "BoltDiam", "BoltLength", "ThickParts",
           "ThickPartNut", "WasherHead", "WasherNut");
    printf("%8d%12d%12d%15d%12d%12d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    STR_LINE;
}

// Проверка 1: резьба в детали (превышение 0.5t крайней к гайке детали)
// Проверка 2: резьба в шайбе (возможность закрутить гайку)
int bolt_check_thread(bolt info[], int number, int *arr)
{
    double thread_result;
    for (int i = 0; i < number; i++)
    {
        if (info[i].bolt_name == arr[0])
        {
            thread_result = arr[4] * info[i].washer_thickness + arr[2] + arr[3] - arr[1] + info[i].thread_length;
            printf("\t\t\t*** GOST DATA ***\n");
            printf("%s%12s%12s%14s%10s\n", "WashThick", "NutHeight", "ThreadLen", "ThreadPitch", "Chamfer");
            printf("%8.1f%12.1f%12d%14.1f%10.1f\n", info[i].washer_thickness, info[i].nut_height,
                   info[i].thread_length, info[i].thread_pitch, info[i].chamfer);
            STR_LINE;
            printf("\t\t\t*** THREAD POSITION ***\n");
            //printf("NEW is %.1f\n", thread_result);
            if (thread_result > 0) // резьба в крайней детали
            {
                printf("Thread in detail %.1f ", fabs(thread_result));
                if (thread_result > 0.5 * arr[3])
                {
                    printf("!!! The thread goes into the part !!!");
                    return 1;
                }
            } else if (thread_result < 0) // резьба в шайбе
            {
                printf("Thread in washer %.1f ", fabs(thread_result));
                if (fabs(thread_result) > arr[5] * info[i].washer_thickness)
                {
                    printf("!!! Do not tighten the nut !!!");
                    return 2;
                }
            } else if (thread_result == 0) // резьба на границе деталей
            {
                printf("Thread at the border of parts");
            }
        }
    }
    return 0;
}

// Проверка 3: проверка длины конца болта (не менее одного полного витка резьбы + фаска)
int bolt_tip_check(bolt info[], int number, int *arr)
{
    double bolt_tip;
    printf("\n");
    STR_LINE;
    printf("\t\t\t*** BOLT TIP ***\n");
    for (int i = 0; i < number; i++)
    {
        if (info[i].bolt_name == arr[0])
        {
            bolt_tip = arr[1] - info[i].washer_thickness * arr[4] - arr[2] - arr[3] -
                       info[i].washer_thickness * arr[5] - 2 * info[i].nut_height;
            printf("Bolt tip is %.1f ", bolt_tip);
            if (bolt_tip <= info[i].thread_pitch + info[i].chamfer)
            {
                printf("!!! Short bolt tip !!!");
                return 1;
            }
        }
    }
    return 0;
}

// Проверка диаметра болта
void bolt_diam_check(int diam)
{
    if (diam != 6 && diam != 8 && diam != 10 && diam != 12 && diam != 16
        && diam != 20 && diam != 24 && diam != 30)
    {
        puts("!!! Incorrect bolt diameter entered !!!\n");
        exit(1);
    }
}

// Печать результатов проверки
void print_result_check(int res1_2, int res3)
{
    printf("\n");
    STR_LINE;
    printf("\t\t\t*** BOLT LENGTH CHECK RESULT ***\n");
    printf("%18s%18s%18s\n", "ThreadRequirement", "TighteningNut", "TipCheck");
    if (res1_2 == 0 && res3 == 0)
        printf("%18s%18s%18s\n", "YES", "YES", "YES");
    else if (res1_2 == 0 && res3 == 1)
        printf("%18s%18s%18s\n", "YES", "YES", "NO");
    else if (res1_2 == 1 && res3 == 0)
        printf("%18s%18s%18s\n", "NO", "YES", "YES");
    else if (res1_2 == 1 && res3 == 1)
        printf("%18s%18s%18s\n", "NO", "YES", "NO");
    else if (res1_2 == 2 && res3 == 0)
        printf("%18s%18s%18s\n", "YES", "NO", "YES");
    else if (res1_2 == 2 && res3 == 1)
        printf("%18s%18s%18s\n", "YES", "NO", "NO");
    STR_LINE;
}