/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:48:28 by david             #+#    #+#             */
/*   Updated: 2022/11/14 13:44:49 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_path(char **map, int i, int j)
{
	int	p;

	p = 0;
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'P')
	{
		map[i - 1][j] = 'P';
		p = 1;
	}
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'P')
	{
		map[i + 1][j] = 'P';
		p = 1;
	}
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'P')
	{
		map[i][j - 1] = 'P';
		p = 1;
	}
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'P')
	{
		map[i][j + 1] = 'P';
		p = 1;
	}
	return (p);
}

void	path(t_data *data)
{
	int				p;
	int				i;
	unsigned int	j;

	p = 1;
	while (p != 0)
	{
		i = 1;
		p = 0;
		while (i < data->win_h)
		{
			j = 0;
			while (++j < ft_strlen(data->map[i]))
			{
				if (data->map[i][j] == 'P')
				{
					if (check_path(data->map, i, j) != 0)
						p = 1;
				}
			}
			i++;
		}
	}
}

int	ft_check_path(t_data *data, char **argv)
{
	int		i;
	int		c;
	int		e;

	i = 0;
	c = 0;
	e = 0;
	path(data);
	while (data->map[i])
	{
		if (ft_strchr(data->map[i], 'C') != NULL)
			c++;
		if (ft_strchr(data->map[i], 'E') != NULL)
			e++;
		i++;
	}
	if (c != 0 || e != 0)
		ft_exit(data, "Error\nInvalid Map");
	i = 0;
	while (data->map[i])
		free (data->map[i++]);
	free (data->map);
	init_data(data);
	init_map(data, argv);
	return (0);
}
