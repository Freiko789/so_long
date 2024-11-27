/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:23:12 by david             #+#    #+#             */
/*   Updated: 2022/11/14 14:15:34 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(t_data *data, char **argv)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	ft_check_close(i, data);
	while (data->map[i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			ft_check(i, j, data);
		}
		ft_check_len(j, data);
		ft_check_one(i, j, data);
		i++;
	}
	if (i == j)
		ft_exit(data, "Error\n");
	ft_check_close((i - 1), data);
	ft_check_one_player(data);
	ft_check_path(data, argv);
}
