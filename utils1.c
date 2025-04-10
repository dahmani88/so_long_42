/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:24:16 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/10 16:49:35 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char **line, t_game *g)
{
	int		i;
	char	**nline;

	i = 0;
	while (line[i] && line[i][0] == '1')
		i++;
	nline = malloc(sizeof(char *) * (i + 1));
	if (!nline)
		free_and_exit(NULL, "allocation failed", g);
	i = 0;
	while (line[i])
	{
		if (line[i][0] != '1')
			break ;
		nline[i] = ft_strdup(line[i]);
		free(line[i]);
		i++;
	}
	nline[i] = NULL;
	while (line[i])
		free(line[i++]);
	free(line);
	return (nline);
}

void	get_win_size(char **lines, int *x, int *y)
{
	*x = ft_strlen(lines[0]);
	while (lines[*y])
		(*y)++;
	*y *= 64;
	*x *= 64;
}

void	free_struct(t_game *game)
{
	if (game->a0_img)
		mlx_destroy_image(game->mlx, game->a0_img);
	if (game->a1_img)
		mlx_destroy_image(game->mlx, game->a1_img);
	if (game->c_img)
		mlx_destroy_image(game->mlx, game->c_img);
	if (game->e_img)
		mlx_destroy_image(game->mlx, game->e_img);
	if (game->p_img)
		mlx_destroy_image(game->mlx, game->p_img);
	if (game->map)
		free_and_not_exit(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game)
		free(game);
	game = NULL;
}

void	images(t_game *game)
{
	int (h), w;
	w = game->w_s;
	h = game->w_s;
	game->p_img = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &w, &h);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w, &h);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "images/coins.xpm", &w, &h);
	game->a0_img = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &w, &h);
	game->a1_img = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w, &h);
	if (!game->p_img || !game->a0_img || !game->a1_img
		|| !game->e_img || !game->c_img)
	{
		free_and_exit(NULL, "Image loading failed\n", game);
	}
}
