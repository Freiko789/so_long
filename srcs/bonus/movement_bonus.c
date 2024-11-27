/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:59:43 by dtassel           #+#    #+#             */
/*   Updated: 2022/11/14 11:45:50 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	mv_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i - 1][j] != '1')
			{
				if (data->map[i - 1][j] == 'E' && data->collector != 0)
					break ;
				else if (data->map[i - 1][j] == 'E' && data->collector == 0)
				{
					ft_printf ("You have win !\nWith %d movements\n",
						data->movement);
					ft_exit(data, NULL);
				}
				update_map_up(data, i, j);
			}
			j++;
		}
	i++;
	}
}

void	mv_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j - 1] != '1')
			{
				if (data->map[i][j - 1] == 'E' && data->collector != 0)
					break ;
				else if (data->map[i][j - 1] == 'E' && data->collector == 0)
				{
					ft_printf ("You have win !\nWith %d movements\n",
						data->movement);
					ft_exit(data, NULL);
				}
				update_map_left(data, i, j);
			}
			j++;
		}
	i++;
	}
}

void	mv_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i + 1][j] != '1')
			{
				if (data->map[i + 1][j] == 'E' && data->collector != 0)
					break ;
				else if (data->map[i + 1][j] == 'E' && data->collector == 0)
				{
					ft_printf ("You have win !\nWith %d movements\n",
						data->movement);
					ft_exit(data, NULL);
				}
				update_map_down(data, i++, j);
			}
			j++;
		}
	i++;
	}
}

void	mv_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j + 1] != '1')
			{
				if (data->map[i][j + 1] == 'E' && data->collector != 0)
					break ;
				else if (data->map[i][j + 1] == 'E' && data->collector == 0)
				{
					ft_printf ("You have win !\nWith %d movements\n",
						data->movement);
					ft_exit(data, NULL);
				}
				update_map_right(data, i, j++);
			}
			j++;
		}
	i++;
	}
}

int	player_mv(int keycode, t_data *data)
{
	if (keycode == 13)
		mv_up(data);
	else if (keycode == 0)
		mv_left(data);
	else if (keycode == 1)
		mv_down(data);
	else if (keycode == 2)
		mv_right(data);
	else if (keycode == 53)
		ft_exit(data, NULL);
	return (0);
}
