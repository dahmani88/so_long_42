/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:22:34 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/09 17:42:09 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->a0_img = NULL;
	game->a1_img = NULL;
	game->c_img = NULL;
	game->e_img = NULL;
	game->e_x = 0;
	game->e_y = 0;
	game->map = NULL;
	game->mlx = NULL;
	game->moves = 0;
	game->p_img = NULL;
	game->p_x = 0;
	game->p_y = 0;
	game->w_s = 64;
	game->win = NULL;
}

int	main(int ac, char **av)
{
	t_game	*game;
	char	**lines;

	int (x), y = 0;
	x = 0;
	if (ac != 2)
		free_and_exit(NULL, "invlide input, use ./so_long map.ber", NULL);
	check_name(av[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		free_and_exit(NULL, "allocation error\n", NULL);
	init_game(game);
	lines = check_map(av[1], game);
	game->map = get_map(lines, game);
	game->mlx = mlx_init();
	get_win_size(game->map, &x, &y);
	game->win = mlx_new_window(game->mlx, x, y, "SO_LONG BY ME ...");
	images(game);
	put_map_to_win(game);
	mlx_hook(game->win, 2, 1L << 0, move_player, game);
	mlx_loop(game->mlx);
	return (0);
}
