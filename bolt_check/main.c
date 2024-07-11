#include <stdio.h>
#include <unistd.h>
#include "temp_function.h"
#define SIZE 8 // число строк в файле

int connect_package[6];
// Перечень длин болтов из ГОСТ
int bolt_length[] = {22, 25, 28, 30, 32, 35, 38, 40, 45, 50, 55,
                     60, 65, 70, 75, 80, 85, 90, 95, 100, 105,
                     110, 115, 120, 125, 130, 140, 150, 160, 170,
                     180, 190, 200, 220, 240, 260, 280, 300};
int flag_g;

int main(int argc, char *argv[])
{
    bolt *info = malloc(SIZE * sizeof(bolt));
    if (!info)
        printf("Error while allocating memory!\n");
    FILE *fptr;
    int rez, flag = 0;
    int result1_2, result3;
    char *file_name;
    int count;
    opterr = 0; // отключить вывод сообщений об ошибках
    if (argc == 1)
    {
        print_info();
        flag = 1;
    }

    // Работа с аргументами командной строки
    while ((rez = getopt(argc, argv, "hf:m:l:s:t:w:n:")) != -1)
    {
        switch (rez)
        {
            case 'h':
                print_help();
                flag = 1;
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
                bolt_length_check_7798();
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

    if (flag != 1)
        print_input_data(connect_package);
    open_file(&fptr, file_name);
    count = read_data_file(&fptr, info);
    fclose(fptr);
    result1_2 = bolt_check_thread(info, count, connect_package);
    result3 = bolt_tip_check(info, count, connect_package);
    print_result_check(result1_2, result3);
    free(info);
    return 0;
}
