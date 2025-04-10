/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:44 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/10 16:08:23 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isgood(char **str)
{
	int (i), j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	improve_map(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'E')
		if (ft_isgood(g->map))
			exit((free_struct(g), get_next_line(-1), 0));
	if (g->p_x == g->e_x && g->p_y == g->e_y)
		g->map[g->p_y][g->p_x] = 'E';
	else
		g->map[g->p_y][g->p_x] = '0';
	g->p_y = y;
	g->p_x = x;
	g->map[g->p_y][g->p_x] = 'P';
	g->moves++;
	write(1, "\rNumber of movements : ", 22);
	ft_putnbr(g->moves);
}

int	move_player(int key, t_game *g)
{
	int (new_pos_x), new_pos_y;
	new_pos_x = g->p_x;
	new_pos_y = g->p_y;
	if (key == 65307)
	{
		free_struct(g);
		exit((get_next_line(-1), 0));
	}
	else if (key == 65361)
		new_pos_x--;
	else if (key == 65362)
		new_pos_y--;
	else if (key == 65363)
		new_pos_x++;
	else if (key == 65364)
		new_pos_y++;
	else
		return (0);
	if (g->map[new_pos_y][new_pos_x] != '1')
	{
		improve_map(g, new_pos_x, new_pos_y);
		put_map_to_win(g);
	}
	return (0);
}
