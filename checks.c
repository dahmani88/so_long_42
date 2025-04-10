/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:29:49 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/09 17:57:04 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	return (1);
}

void	check_name(char *str)
{
	int	i;
	int	dot_index;

	i = 0;
	dot_index = -1;
	while (str[i])
	{
		if (str[i] == '.')
			dot_index = i;
		i++;
	}
	if (dot_index <= 0 || str[dot_index - 1] == '/'
		|| !ft_strcmp(&str[dot_index], ".ber"))
		exit((write(1, "Error\ninvalid name\n", 20), 0));
}

int	check_open(char *str, t_game *g)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		free_and_exit(NULL, "Error\nno exist file\n", g);
	return (fd);
}

char	**check_map(char *str, t_game *game)
{
	char	**lines;

	int (numlines);
	lines = check_edges(str, &numlines, game);
	check_map_characters(lines, game);
	check_route(lines, game->p_y, game->p_y, game);
	return (lines);
}
