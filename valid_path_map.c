#include "so_long.h"

int count_y(char **str)
{
    int count = 0;
    while (str[count])
    {
        count++;
    }
    return count;
}

int count_x(char **str)
{
    int count = 0;
    while (str[0][count])
    {
        count++;
    }
    return count;
}

char *from_2d_to_1d(char *file)
{
    char **old_map = trans_to_2d_dim(file);
    char *new_map = malloc((count_y(old_map) * count_x(old_map)) * sizeof(char *));
    int count = 0;
    int index = 0;
    int c = 0;
    while (old_map[count])
    {
        index = 0;
        while (old_map[count][index])
        {
            new_map[c] = old_map[count][index];
            index++;
            c++;
        }
        new_map[c++] = '\n';
        count++;
    }
    new_map[c] = 0;
    return new_map;
}

char **check_path(char *file)
{
    char **s = trans_to_2d_dim(file);
    return s;
}

void cc(char **str, char *file)
{
    char *map = from_2d_to_1d(file);
    int count = 0;
    int save = 0;
    int line_le;
    int *position = malloc(800);
    int positiocoint = 0;
    while (map[line_le]) {
        if (map[line_le] == '\n') {
            break;
        }
        line_le++;
    }

    while (map[count]) {
        if (map[count] == 'P') {
            if (map[count + 1] == '0' || map[count + 1] == 'C') {
                map[count + 1] = 'P';
                position[positiocoint] = count+1;
                positiocoint++;
            }else if (map[count - 1] == '0' || map[count - 1] == 'C') {
                map[count - 1] = 'P';
                position[positiocoint] = count-1;
                positiocoint++;
            }
        }
        count++;
    }

    printf("%d\n", position[0]);
    printf("%s\n", map);
}
