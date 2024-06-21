#include <stdio.h>
#include <unistd.h>
#include "temp_function.h"
#define SIZE 10

int main(int argc, char *argv[])
{
    bolt info[SIZE];
    FILE *fptr;
    int rez = 0;
    char *file_name;
    int count, thread_diameter, bolt_length, thick_parts, thick_part_nut, flag_head, flag_nut;
    opterr = 0; // отключить вывод сообщений об ошибках
    if (argc == 1)
        print_info();
    // Работа с аргументами командной строки
    while ((rez = getopt(argc, argv, "hf:m:l:s:t:w:n:")) != -1)
    {
        switch (rez)
        {
            case 'h':
                print_help();
                break;
            case 'f':
                file_name = optarg;
                printf("File name is %s.\n", file_name);
                break;
            case 'm':
                thread_diameter = atoi(optarg);
                //printf("Thread diameter is M%d.\n", thread_diameter);
                break;
            case 'l':
                bolt_length = atoi(optarg);
                //printf("Bolt length is %d.\n", bolt_length);
                break;
            case 's':
                thick_parts = atoi(optarg);
                //printf("Thickness of parts is %d.\n", thickness_parts);
                break;
            case 't':
                thick_part_nut = atoi(optarg);
                //printf("Thickness of one part from the nut side is %d.\n", thickness_part_nut);
                break;
            case 'w':
                flag_head = atoi(optarg);
                //printf("Washer under the bolt head is %d.\n", flag_head);
                break;
            case 'n':
                flag_nut = atoi(optarg);
                //printf("Washer under the nut is %d.\n", flag_nut);
                break;
            case '?':
                printf("Error found !\n");
                break;
        }
    }
    print_input_data(thread_diameter, bolt_length, thick_parts,
                     thick_part_nut, flag_head, flag_nut);
    //open_file(&fptr, file_name);
    //count = read_data_file(&fptr, info);
    //printf("%d\n", count);
    //print(info, count);

    return 0;
}
