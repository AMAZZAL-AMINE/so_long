#include "so_long.h"


char **check_for_valid_path_map(char **map) {
    int count = 0;
    int index = 0;
    char **maper = map;

    while (maper[count]) {
        index = 0;
        while (maper[count][index]) {
            if (maper[count][index] == 'P') {
                
            index++;
        }
        count++;
    }
    return maper;
}
