#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include <stdbool.h>

struct s_check_key
{
	int key;
	char **map;
	bool is_finished;
	int line_of_map;
} check_key;

struct s_mlx_data
{
	void *mlx;
	void *win;
	void *wall;
	void *space;
	void *player;
	void *coin;
	void *close_door;
	void *open_door;
} mlx_data;

bool check_map(char **map)
{
	int count = 0;
	int i = 0;
	int check = 0;

	while (map[count])
	{
		i = 0;
		if (count == 0)
		{
			// check first line
			while (map[0][i])
			{
				if (map[0][i] != '1')
					return (false);
				i++;
			}
		}
		else if (map[count + 1] == 0)
		{
			// check last line
			while (map[count][i])
			{
				if (map[count][i] != '1')
					return (false);
				i++;
			}
		}
		else 
		{
			// check middle lines
			while (map[count][i])
			{
				if (map[count][0] != '1')
					return (false);
				else if (map[count][i + 1] == 0)
				{
					if (map[count][i] != '1')
						return (false);
				}
				i++;
			}
		}
		count++;
	}

	return (true);
}

bool check_for_coins() {
	int count = 0;
	int index = 0;
	int chekr = 0;
	char **map = check_key.map;
	while (map[count]) {
		index = 0;
		while (map[count][index]) {
			if (map[count][index] == 'C') {
				return 1;
			}
			index++;
		}
		count++;
	}

	return 0;
}

void draw_map(void *mlx, void *win, void *wall, void *space, void *player, void *coin, void *close_door, void *open_door)
{
	int a = 0;
	int b = 0;
	while (check_key.map[a])
	{
		b = 0;
		while (check_key.map[a][b])
		{
			if (check_key.map[a][b] == '1')
				mlx_put_image_to_window(mlx, win, wall, b * 50, a * 50);
			else if (check_key.map[a][b] == '0')
				mlx_put_image_to_window(mlx, win, space, b * 50, a * 50);
			else if (check_key.map[a][b] == 'C')
			{
				mlx_put_image_to_window(mlx, win, space, b * 50, a * 50);
				mlx_put_image_to_window(mlx, win, coin, b * 50, a * 50);
			}
			if (check_key.map[a][b] == 'E') {
				if (check_for_coins() == 0) {
					check_key.is_finished = true;
					mlx_put_image_to_window(mlx, win, space, b * 50, a * 50);
					mlx_put_image_to_window(mlx, win, open_door, b * 50, a * 50);
				}else {
					mlx_put_image_to_window(mlx, win, space, b * 50, a * 50);
					mlx_put_image_to_window(mlx, win, close_door, b * 50, a * 50);
				}
			}
			if (check_key.map[a][b] == 'P')
			{
				mlx_put_image_to_window(mlx, win, space, b * 50, a * 50);
				mlx_put_image_to_window(mlx, win, player, b * 50, a * 50);
			}
			b++;
		}
		a++;
	}
}

void player_move(int keycode)
{
	int count = 0;
	int index = 0;
	static int countmoves;
	while (check_key.map[count]) {
		index = 0;
		while (check_key.map[count][index]) {
			if (check_key.map[count][index] == 'P') {
				if (check_key.key == 126) {
					if (check_key.map[count - 1][index] == '0' || check_key.map[count - 1][index] == 'C') {
						check_key.map[count - 1][index] = 'P'; 
						check_key.map[count][index] = '0';
						return;
					}else if (check_key.map[count - 1][index] == 'E') {
						if (check_key.is_finished == true) {
							finished_game();
						}
					}
				}else if (check_key.key == 125) { //down
					if (check_key.map[count + 1][index] == '0' || check_key.map[count + 1][index] == 'C') {
						check_key.map[count + 1][index] = 'P';
						check_key.map[count][index] = '0';
						return;
					}else if (check_key.map[count + 1][index] == 'E') {
						if (check_key.is_finished == true) {
							finished_game();
						}
					}
				}else if (check_key.key == 123) { //left <-
					if (check_key.map[count][index - 1] == '0' || check_key.map[count][index - 1] == 'C') {
						check_key.map[count][index - 1] = 'P';
						check_key.map[count][index] = '0';
						return;
					}else if (check_key.map[count][index - 1] == 'E') {
						if (check_key.is_finished == true) {
							finished_game();
						}
					}
				}else if (check_key.key == 124) { //right ->
					if (check_key.map[count][index + 1] == '0' || check_key.map[count][index + 1] == 'C') {
						check_key.map[count][index + 1] = 'P';
						check_key.map[count][index] = '0';
						return;
					}else if (check_key.map[count][index + 1] == 'E') {
						if (check_key.is_finished == true) {
							finished_game();
						}
					}
				}
			}
			index++;
		}
		count++;
	}
}

int key_press(int keycode, void *param)
{
	check_key.key = keycode;
	if (keycode == 53)
		exit_game();
	player_move(keycode);
	draw_map(mlx_data.mlx, mlx_data.win, mlx_data.wall, mlx_data.space, mlx_data.player, mlx_data.coin, mlx_data.close_door, mlx_data.open_door);
	return (0);
}

int check_line_len(char **line)
{
	int i = 0;
	int len = 0;
	while (line[i])
		i++;
	return (i);
}

char **trans_to_2d_dim(char *file) {
	int	fd;
	int count = 0;
	int i = 0;
	fd = open(file, O_RDONLY);
	char **map;
	char *line;
	while ((line = get_next_line(fd)))
		count++;
	close(fd);
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (count + 1));
	while ((line = get_next_line(fd)))
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	return (map);
}

void map_statu() {
	if (check_map(check_key.map)) {
		printf("\033[32mSUCCESS\033[0m\n");
	}else {
		printf("\033[31mERROR\033[0m\n");
		exit(1);
	}
}

int main()
{
	check_key.map = trans_to_2d_dim("maps/map.ber");

	check_path_player(check_key.map);
	check_path_coing(check_key.map);
	check_path_door(check_key.map);
	check_lines_map(check_key.map);
	check_for_imposter_in_map(check_key.map);
	check_for_door(check_key.map);
	check_for_player(check_key.map);
	check_the_parrent_path(check_key.map);
	
	int b = 0;
	while (check_path(check_key.map)[b]) {
		printf("%s\n", check_path(check_key.map)[b]);
		b++;
	}
	map_statu();
	int img_width;
	int img_height;
	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, ft_strlen(check_key.map[0]) * 50, check_line_len(check_key.map) * 50, "so_long");
	mlx_data.wall = mlx_xpm_file_to_image(mlx_data.mlx, "img/wall2.xpm", &img_width, &img_height);
	mlx_data.space = mlx_xpm_file_to_image(mlx_data.mlx, "img/space.xpm", &img_width, &img_height);
	mlx_data.player = mlx_xpm_file_to_image(mlx_data.mlx, "img/player.xpm", &img_width, &img_height);
	mlx_data.coin = mlx_xpm_file_to_image(mlx_data.mlx, "img/coin.xpm", &img_width, &img_height);
	mlx_data.close_door = mlx_xpm_file_to_image(mlx_data.mlx, "img/close_door.xpm", &img_width, &img_height);
	mlx_data.open_door = mlx_xpm_file_to_image(mlx_data.mlx, "img/door.xpm", &img_width, &img_height);
	draw_map(mlx_data.mlx , mlx_data.win, mlx_data.wall, mlx_data.space, mlx_data.player, mlx_data.coin, mlx_data.close_door, mlx_data.open_door);
	mlx_key_hook(mlx_data.win, key_press, NULL);
	mlx_hook(mlx_data.win, 17, 0, exit_game, NULL);
	mlx_loop(mlx_data.mlx);
	return (0);
}