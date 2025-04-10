/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:09:32 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/10 21:43:41 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x, y);
}

void	put_map_to_win(t_game *g)
{
	int (j), i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] && g->map[i][j] != '\n')
		{
			printf ("%c, ", g->map[i][j]);
			if (g->map[i][j] == '1')
				put_img(g, g->a1_img, j * g->w_s, i * g->w_s);
			else if (g->map[i][j] == '0')
				put_img(g, g->a0_img, j * g->w_s, i * g->w_s);
			else if (g->map[i][j] == 'P')
				put_img(g, g->p_img, j * g->w_s, i * g->w_s);
			else if (g->map[i][j] == 'E')
				put_img(g, g->e_img, j * g->w_s, i * g->w_s);
			else if (g->map[i][j] == 'C')
				put_img(g, g->c_img, j * g->w_s, i * g->w_s);
			j++;
		}
		i++;
	}
}
