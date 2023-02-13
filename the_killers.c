#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include <stdbool.h>

void finished_game() {
	printf("\033[32mGAME OVER\033[0m\n");
	exit(0);
}

int exit_game() {
	printf("\033[31mEXIT THE GAME\033[0m\n");
	exit(0);
    return (0);
}

void error_int_map() {
    printf("\033[31mMAP ERROR\033[0m\n");
    exit(1);
}