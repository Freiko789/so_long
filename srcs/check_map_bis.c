/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:49:20 by dtassel           #+#    #+#             */
/*   Updated: 2022/11/12 14:27:28 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_one_player(t_data *data)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
				p++;
			if (data->map[i][j] == 'E')
				e++;
			if (data->map[i][j] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c == 0)
		ft_exit(data, "Error\nInvalid map");
}

void	ft_check_one(int i, int j, t_data *data)
{
	if (data->map[i][j - 1] != '1')
		ft_exit(data, "Error\nInvalid map");
	if (data->map[i][0] != '1')
		ft_exit(data, "Error\nInvalid map");
}

void	ft_check_len(size_t j, t_data *data)
{
	if (j != ft_strlen(data->map[0]))
		ft_exit(data, "Error\nInvalid map");
	if (ft_strlen(data->map[0]) > 38)
		ft_exit(data, "Error\nMap too big");
}

void	ft_check_close(int i, t_data *data)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1')
			ft_exit(data, "Error\nInvalid map");
		j++;
	}
}

void	ft_check(int i, int j, t_data *data)
{
	if (data->map[i][j] != '1' && data->map[i][j] != 'C'
			&& data->map[i][j] != 'E' && data->map[i][j] != '0'
				&& data->map[i][j] != 'P')
	{
		ft_exit(data, "Error\nInvalid map");
	}
}
