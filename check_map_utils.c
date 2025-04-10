/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:58:37 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/10 17:40:44 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	help(char *str, int check)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	if (check)
	{
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != '1')
				return (0);
			i++;
		}
	}
	else
		if (str[0] != '1' || str[ft_strlen(str) - 2] != '1')
			return (0);
	return (1);
}

int	count_lines(int fd, char **lines)
{
	int		count;
	char	*line;

	count = 0;
	if (lines)
	{
		while (lines[count])
			count++;
	}
	else
	{
		line = get_next_line(fd);
		while (line)
		{
			count++;
			free(line);
			line = get_next_line(fd);
		}
	}
	return (count);
}

void	free_and_exit(char **map, char *error_message, t_game *g)
{
	int	i;

	get_next_line(-1);
	if (map != NULL)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		map = NULL;
	}
	if (g != NULL)
		free_struct(g);
	if (error_message != NULL)
	{
		write(1, "Error\n", 6);
		exit((write(1, error_message, ft_strlen(error_message)), 0));
	}
}

char	**check_edges(char *name, int *numlines, t_game *g)
{
	char	**map;

	int (fd), i = 0, j = -1;
	fd = check_open(name, g);
	*numlines = count_lines(fd, NULL);
	close(fd);
	if (numlines == 0)
		free_and_exit(NULL, "empty file\n", g);
	fd = check_open(name, g);
	map = malloc(sizeof(char *) * (*numlines + 1));
	if (!map)
		free_and_exit(NULL, "malloc failed\n", g);
	while (++j <= *numlines)
		map[j] = NULL;
	while (i < *numlines)
	{
		map[i] = get_next_line(fd);
		if (!map[i] || !help(map[i], (i == 0 || i == *numlines - 1)))
			free_and_exit(map, "edges error\n", g);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
