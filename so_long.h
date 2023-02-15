#ifndef  SO_LONG_H
# define SO_LONG_H

    #include "mlx.h"
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include "so_long.h"
    #include <stdbool.h>
    #include "gnl/get_next_line.h"
    //function for reading file
    int exit_game();
    void finished_game();
    void error_int_map();
    //cheking map
    // char **check_for_valid_path_map(char **map);

    bool check_path_player(char **map);
    bool check_path_coing(char **map);
    bool check_path_door(char **map);
    bool check_lines_map(char **map);
    bool check_for_imposter_in_map(char **map);
    bool check_for_door(char **map);
    bool check_for_player(char **map);
    bool check_the_parrent_path(char **map);
    char **check_path(char *file, char **s);
    char **trans_to_2d_dim(char *file);

    void cc(char **str, char *file);

#endif