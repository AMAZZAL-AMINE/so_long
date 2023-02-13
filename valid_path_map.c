#include "so_long.h"


/*  
    1111111111111111111111
    1    C    C  1P      1
    1     C   1C  1C     1
    1 C    1    C C      1
    1      1  C   E1     1
    1111111111111111111111
    p => +

*/

/*
    1111111111 1000C00101 10E000C111 1111111111
    0123456789 0123456789 0123456789 0123456789
*/

char **check_path(char **map) {
    int count = 0;
    int index = 0;
    char **map_two = map;
    while (map_two[count]) {
        index = 0;
        while (map_two[count][index]) {
            if (map_two[count][index] == 'P') {
                if ((map_two[count + 1][index] == '0') || (map_two[count + 1][index] == 'C') || (map_two[count + 1][index] == 'E')) {
                    map_two[count + 1][index] = 'P';
                }else if ((map_two[count - 1][index] == '0') || (map_two[count - 1][index] == 'C') ||( map_two[count - 1][index] == 'E')) {
                    map_two[count - 1][index] = 'P';
                }else if ((map_two[count][index + 1] == '0') || (map_two[count][index + 1] == 'C') || (map_two[count][index + 1] == 'E')) {
                    map_two[count][index + 1] = 'P';
                }else if ((map_two[count][index - 1] == '0') || (map_two[count][index - 1] == 'C' || map_two[count][index - 1] == 'E')) {
                    map_two[count][index - 1] = 'P';
                }
            }
            index++;
        }
        count++;
    }
    return map_two;
}