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

char **check_path(char *file, char **s)
{
    //check if the path is valid and the player is rech the dooror collected all the coins
    char *map = from_2d_to_1d(s);
    int count = 0;
    int save = 0;
    int line_le;
    int *position = malloc(800);
    int positiocoint = 0;
    while (map[line_le])
    {
        if (map[line_le] == '\n')
        {
            break;
        }
        line_le++;
    }

    while (map[count])
    {
        if (map[count] == 'P')
        {
            if (map[count + 1] == '0' || map[count + 1] == 'C')
            {
                map[count + 1] = 'P';
                position[positiocoint] = count + 1;
                positiocoint++;
            }
            else if (map[count - 1] == '0' || map[count - 1] == 'C')
            {
                map[count - 1] = 'P';
                position[positiocoint] = count - 1;
                positiocoint++;
            }
            else if (map[count - line_le] == '0' || map[count + line_le + 1] == 'C')
            {
                map[count + line_le] = 'P';
                position[positiocoint] = count + line_le;
                positiocoint++;
            }
            else if (map[count + line_le] == '0' || map[count - line_le + 1] == 'C')
            {
                map[count + line_le] = 'P';
                position[positiocoint] = count + line_le;
                positiocoint++;
            }
        }
        count++;
    }

    count = 0;
    while (map[count])
    {
        if (map[count] == 'P')
        {
            if (map[count + 1] == '0' || map[count + 1] == 'C')
            {
                map[count + 1] = 'P';
                position[positiocoint] = count + 1;
                positiocoint++;
            }
            else if (map[count - 1] == '0' || map[count - 1] == 'C')
            {
                map[count - 1] = 'P';
                position[positiocoint] = count - 1;
                positiocoint++;
            }
            else if (map[count - line_le] == '0' || map[count + line_le + 1] == 'C')
            {
                map[count + line_le] = 'P';
                position[positiocoint] = count + line_le;
                positiocoint++;
            }
            else if (map[count + line_le] == '0' || map[count - line_le + 1] == 'C')
            {
                map[count + line_le] = 'P';
                position[positiocoint] = count + line_le;
                positiocoint++;
            }
        }
        count++;
    }

    count = 0;
    while (map[count])
    {
        if (map[count] == 'P')
        {
            if (map[count + 1] == '0' || map[count + 1] == 'C')
            {
                map[count + 1] = 'P';
                position[positiocoint] = count + 1;
                positiocoint++;
            }
            else if (map[count - 1] == '0' || map[count - 1] == 'C')
            {
                map[count - 1] = 'P';
                position[positiocoint] = count - 1;
                positiocoint++;
            }
            else if (map[count - line_le] == '0' || map[count + line_le + 1] == 'C')
            {
                map[count + line_le] = 'P';
                position[positiocoint] = count + line_le;
                positiocoint++;
            }
            else if (map[count + line_le] == '0' || map[count - line_le + 1] == 'C')
            {
                map[count + line_le] = 'P';
                position[positiocoint] = count + line_le;
                positiocoint++;
            }
        }
        count++;
    }

    return s;
}


void cc(char **str, char *file) {
    int count = 0;
    int index = 0;
    while (str[count]) {
        index = 0;
        while (str[count][index]) {
            if (str[count][index] == 'P') {
                while (str[count + 1][index] == 'C' || str[count + 1][index] == '0')  {
                    str[count + 1][index] = '1';
                    count++;
                }
                while (str[count - 1][index] == 'C' || str[count + 1][index] == '0')  {
                    str[count - 1][index] = '1';
                    count++;
                }
                while (str[count - 1][index] == 'C' || str[count + 1][index] == '0')  {
                    str[count - 1][index] = '1';
                    count++;
                }
            }
        }
    }
}
