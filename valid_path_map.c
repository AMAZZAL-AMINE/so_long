#include "so_long.h"

char **check_path(char *file,char **map) {
    int count = 0;
    int index = 0;
    char **map_two = map;
    while (map_two[count]) {
        index = 0;
        while (map_two[count][index]) {
            if (map_two[count][index] == 'P') {
                if ((map_two[count + 1][index] == '0') || (map_two[count + 1][index] == 'C')) {
                    map_two[count + 1][index] = 'P';
                }
                if ((map_two[count - 1][index] == '0') || (map_two[count - 1][index] == 'C')) {
                    map_two[count - 1][index] = 'P';
                }
                if ((map_two[count][index + 1] == '0') || (map_two[count][index + 1] == 'C')) {
                    map_two[count][index + 1] = 'P';
                }
                if ((map_two[count][index - 1] == '0') || (map_two[count][index - 1] == 'C')) {
                    map_two[count][index - 1] = 'P';
                }
            }
            index++;
        }
        count++;
    }

    return map_two;
}

void cc(char **str, char *file) {
    int b = 0;
    int index = 0;
    char **s = check_path(file, str);
    while (s[b]) {
		printf("%s\n", s[b]);
		b++;
	}
}