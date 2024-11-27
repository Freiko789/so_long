/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:44:57 by dtassel           #+#    #+#             */
/*   Updated: 2022/11/14 11:46:50 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_map_up(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	if (data->map[i - 1][j] == 'M')
		ft_die(data);
	else if (data->map[i - 1][j] == 'C')
			data->collector--;
	data->map[i - 1][j] = 'P';
	data->movement++;
}

void	update_map_down(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	if (data->map[i + 1][j] == 'M')
		ft_die(data);
	else if (data->map[i + 1][j] == 'C')
			data->collector--;
	i++;
	data->map[i][j] = 'P';
	data->movement++;
}

void	update_map_left(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	if (data->map[i][j - 1] == 'M')
		ft_die(data);
	else if (data->map[i][j - 1] == 'C')
		data->collector--;
	data->map[i][j - 1] = 'P';
	data->movement++;
	data->t_img.p = 0;
}

void	update_map_right(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	if (data->map[i][j + 1] == 'M')
		ft_die(data);
	else if (data->map[i][j + 1] == 'C')
			data->collector--;
	data->map[i][j + 1] = 'P';
	data->movement++;
	data->t_img.p = 1;
}

void	ft_die(t_data *data)
{
	ft_printf("You are dead !\nRetry !\n");
	ft_exit(data, NULL);
}
