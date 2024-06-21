#include <stdio.h>
#include <unistd.h>
#include "temp_function.h"
#define SIZE 10

int connect_package[6];

int main(int argc, char *argv[])
{
    bolt info[SIZE];
    FILE *fptr;
    int rez = 0;
    char *file_name;
    int count;
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
                // Диаметр резьбовой части болта
                bolt_diam_check(connect_package[0] = atoi(optarg));
                break;
            case 'l':
                // Длина болта [мм]
                connect_package[1] = atoi(optarg);
                break;
            case 's':
                // Толщина соединяемых деталей под головкой болта [мм]
                connect_package[2] = atoi(optarg);
                break;
            case 't':
                // Толщина одной детали под гайкой [мм]
                connect_package[3] = atoi(optarg);
                break;
            case 'w':
                // Количество шайб под головкой болта
                connect_package[4] = atoi(optarg);
                break;
            case 'n':
                // Количество шайб под гайкой
                connect_package[5] = atoi(optarg);
                break;
            case '?':
                printf("Error found !\n");
                break;
        }
    }
    print_input_data(connect_package);
    open_file(&fptr, file_name);
    count = read_data_file(&fptr, info);
    bolt_check_thread_part(info, count, connect_package);
    //printf("%d\n", count);
    //print(info, count);

    return 0;
}
