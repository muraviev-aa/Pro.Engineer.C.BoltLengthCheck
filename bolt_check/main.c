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
    int count;
    opterr = 0; // отключить вывод сообщений об ошибках
    if (argc == 1)
        print_info();
    // Работа с аргументами командной строки
    while ((rez = getopt(argc, argv, "hf:m:l:s:t:")) != -1)
    {
        switch (rez)
        {
            case 'h':
                print_help();
                break;
            case 'f':
                file_name = optarg;
                printf("found argument \"f = %s\".\n", file_name);
                break;
            case 'm':
                printf("found argument \"m = %s\".\n", optarg);
                break;
            case 'l':
                printf("found argument \"l = %s\".\n", optarg);
                break;
            case 's':
                printf("found argument \"s = %s\".\n", optarg);
                break;
            case 't':
                printf("found argument \"t = %s\".\n", optarg);
                break;
            case '?':
                printf("Error found !\n");
                break;
        }
    }
    open_file(&fptr, file_name);
    count = read_data_file(&fptr, info);
    printf("%d\n", count);
    print(info, count);

    return 0;
}
