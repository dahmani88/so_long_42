/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:49:08 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/09 17:40:37 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_chr(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] != '1' && str[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fil(char **lines, int y, int x)
{
	if (lines[y][x] == '1')
		return ;
	lines[y][x] = '1';
	flood_fil(lines, y - 1, x);
	flood_fil(lines, y, x - 1);
	flood_fil(lines, y + 1, x);
	flood_fil(lines, y, x + 1);
}

void	free_and_not_exit(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		lines[i] = NULL;
		i++;
	}
	free(lines);
	lines = NULL;
}

void	check_route(char **line, int y, int x, t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	while (line[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		free_and_exit(line, "allocation failed", game);
	i = 0;
	while (line[i])
	{
		copy[i] = ft_strdup(line[i]);
		i++;
	}
	copy[i] = NULL;
	flood_fil(copy, y, x);
	if (!ft_chr(copy))
	{
		free_and_not_exit(copy);
		free_and_exit(line, "invalid game\n", game);
	}
	free_and_not_exit(copy);
}
