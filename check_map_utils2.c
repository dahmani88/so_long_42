/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:26:25 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/09 17:54:43 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_len(char **lines, t_game *g)
{
	int (len2), len1, i = 1, c = 0, numlines = count_lines(0, lines);
	i = 0;
	len1 = ft_strlen(lines[0]);
	numlines = count_lines(0, lines);
	while (lines[i])
	{
		len2 = ft_strlen(lines[i]);
		if (lines[i][len2 - 1] != '\n')
			len2 += 1;
		if (lines[i][0] == '\n')
			c = 1;
		if (lines[i][0] != '\n' && c)
			free_and_exit(lines, "invalid map, The map is divided\n", g);
		if (len2 != len1 && lines[i][0] != '\n')
			free_and_exit(lines, "invalid map, len error\n", g);
		i++;
	}
	return (numlines);
}

void	valid(char c, char **map, t_game *g)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return ;
	else
		free_and_exit(map, "invalid map, unknown letter\n", g);
}

void	get_position(t_game *g, int i, int j, int check)
{
	if (check == 1)
	{
		g->p_x = j;
		g->p_y = i;
	}
	else
	{
		g->e_x = j;
		g->e_y = i;
	}
}

void	check_map_characters(char **lines, t_game *g)
{
	int (t), e = 0, p = 0, c = 0, i = -1, j = 0;
	t = check_len(lines, g);
	while (t && lines[++i])
	{
		j = 0;
		while (lines[i][j] && lines[i][j] != '\n')
		{
			valid(lines[i][j], lines, g);
			if (lines[i][j] == 'P')
			{
				p++;
				get_position(g, i, j, 1);
			}
			if (lines[i][j] == 'E')
			{
				e++;
				get_position(g, i, j, 0);
			}
			if (lines[i][j] == 'C')
				c++;
			j++;
		}
	}
	if (c < 1 || p != 1 || e != 1)
		free_and_exit(lines, "invalid map, P & E != 1 | C < 1\n", g);
}
