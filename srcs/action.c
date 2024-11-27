/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:17:11 by david             #+#    #+#             */
/*   Updated: 2022/11/10 08:13:29 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_map_up(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	if (data->map[i - 1][j] == 'M')
		ft_die(data);
	else if (data->map[i - 1][j] == 'C')
		data->collector--;
	data->map[i - 1][j] = 'P';
	data->movement++;
	ft_printf("%i\n", data->movement);
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
	ft_printf("%i\n", data->movement);
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
	ft_printf("%i\n", data->movement);
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
	ft_printf("%i\n", data->movement);
}

void	ft_die(t_data *data)
{
	printf("You are dead !\nRetry !\n");
	ft_exit(data, NULL);
}
