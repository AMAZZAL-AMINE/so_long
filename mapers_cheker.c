#include "so_long.h"

bool check_the_parrent_path(char **map) {
    return true;
}
bool check_path_player(char **map) {
    int count = 0;
    int index = 0;

    while (map[count]) {
        index = 0;
        while (map[count][index]) {
            if (map[count][index] == 'P') {
                if (map[count - 1][index] == '1' && map[count + 1][index] == '1' && map[count][index + 1] == '1' && map[count][index - 1] == '1') {
                    printf("\033[31mBruh, player Not found way):\033[0m\n");
                    exit(1);
                }
            }
            index++;
        }
        count++;
    }
    return true;
}

bool check_path_coing(char **map) {
    int count = 0;
    int index = 0;

    while (map[count]) {
        index = 0;
        while (map[count][index]) {
            if (map[count][index] == 'C') {
                if (map[count - 1][index] == '1' && map[count + 1][index] == '1' && map[count][index + 1] == '1' && map[count][index - 1] == '1') {
                    printf("\033[31mThers No way to COIN ):\033[0m\n");
                    exit(1);
                }
            }
            index++;
        }
        count++;
    }
    return true;
}

bool check_path_door(char **map) {
    int count = 0;
    int index = 0;

    while (map[count]) {
        index = 0;
        while (map[count][index]) {
            if (map[count][index] == 'E') {
                if (map[count - 1][index] == '1' && map[count + 1][index] == '1' && map[count][index + 1] == '1' && map[count][index - 1] == '1') {
                    printf("\033[31mThers No way to DOOR ):\033[0m\n");
                    exit(1);
                }
            }
            index++;
        }
        count++;
    }
    return true;
}

bool check_lines_map(char **map) {
    int count = 0;
    int index = 0;

    while (map[count]) {
        index = 0;
        if (map[count + 1] != '\0') {
            if (ft_strlen(map[count]) != ft_strlen(map[count + 1])) {
                printf("\033[31mEach Line in map shold be same ):\033[0m\n");
                exit(1);
            }
        }else {
            if (ft_strlen(map[count]) != ft_strlen(map[count - 1])) {
                printf("\033[31mEach Line in map shold be same ):\033[0m\n");
                exit(1);
            }
        }
        count++;
    }
    return true;
}

bool check_for_imposter_in_map(char **map) {
    int count = 0;
    int index = 0;

    while (map[count]) {
        while (map[count][index]) {
            if (map[count][index] != '1' && map[count][index] != '0' && map[count][index] != 'P' && map[count][index] != 'C' && map[count][index] != 'E') {
                printf("\033[31mBruh, you have imposter in Map At Line : %d::%d ):\033[0m\n", count + 1, index + 1);
                exit(1);
            }
            index++;
        }
        index = 0;
        count++;
    }
    return true;
}

//norm => 5 function end here

bool check_for_door(char **map) {
    int count = 0;
    int index = 0;
    int check = 0;
    while (map[count]) {
        index = 0;
        while (map[count][index]) {
            if (map[count][index] == 'E') {
                check++;
            }
            index++;
        }
        count++;
    }

    if (check != 1 ) {
        if (check == 0)
            printf("\033[31mBruh,  U do not have door ):\033[0m\n");
        else 
            printf("\033[31mBruh, you have Duplacted Door ):\033[0m\n");
        exit(1);
    }
    return true;
}

bool check_for_player(char **map) {
    int count = 0;
    int index = 0;
    int check = 0;
    while (map[count]) {
        index = 0;
        while (map[count][index]) {
            if (map[count][index] == 'P') {
                check++;
            }
            index++;
        }
        count++;
    }

    if (check != 1 ) {
        if (check == 0)
            printf("\033[31mBruh,  Select Your player ):\033[0m\n");
        else 
            printf("\033[31mBruh, you have Multi player ):\033[0m\n");
        exit(1);
    }
    return true;
}