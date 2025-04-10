/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:34:49 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/10 17:59:51 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "/path/minilibx-linux/mlx.h" // Change this to suit your library path :/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	int		moves;
	void	*win;
	char	**map;
	void	*p_img;
	void	*a1_img;
	void	*a0_img;
	void	*c_img;
	void	*e_img;
	int		w_s;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
}	t_game;

int		ft_strcmp(char *s1, char *s2);
void	check_name(char *str);
int		check_open(char *str, t_game *g);
char	**check_map(char *str, t_game *game);
void	check_map_characters(char **lines, t_game *g);
void	check_route(char **line, int x, int y, t_game *game);
void	free_and_exit(char **map, char *error_message, t_game *g);
int		count_lines(int fd, char **lines);
char	**check_edges(char *name, int *numlines, t_game *game);
char	**get_map(char **line, t_game *g);
void	free_and_not_exit(char **lines);
void	get_win_size(char **lines, int *x, int *y);
void	images(t_game *game);
void	put_map_to_win(t_game *g);
int		move_player(int key, t_game *g);
void	free_struct(t_game *game);
void	ft_putnbr(int n);

#endif