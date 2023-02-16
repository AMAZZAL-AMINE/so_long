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

char *from_2d_to_1d(char **s)
{
    char **old_map = s;
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

char **check_path(char **str)
{
    int count = 0;
    int index = 0;
    
    while (str[count]) {
        index = 0;
        while (str[count][index]) {
            if (str[count][index] == 'P') {
                if (str[count + 1][index] == 'C' || str[count + 1][index] == '0')  {
                    str[count + 1][index] = 'P';
                    count++;
                }
                if (str[count - 1][index] == 'C' || str[count - 1][index] == '0')  {
                    str[count - 1][index] = 'P';
                    count--;
                }
                if (str[count][index + 1] == 'C' || str[count][index + 1] == '0')  {
                    str[count][index + 1] = 'P';
                    index++;
                }
                 if (str[count][index - 1] == 'C' || str[count][index - 1] == '0')  {
                    str[count][index - 1] = 'P';
                    index--;
                }
            }
            index++;
        }
        count++;
    }

    return str;
}