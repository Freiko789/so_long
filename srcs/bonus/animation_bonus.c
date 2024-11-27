/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:26:02 by dtassel           #+#    #+#             */
/*   Updated: 2022/11/14 11:46:45 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_string(t_data **data)
{
	char	*mv;
	char	*cl;

	mv = ft_itoa((*data)->movement);
	cl = ft_itoa((*data)->collector);
	mlx_string_put((*data)->mlx, (*data)->win, 10, 0, 0x000000,
		"Moves :");
	mlx_string_put((*data)->mlx, (*data)->win, 9, 1, 0xffffff,
		"Moves :");
	mlx_string_put((*data)->mlx, (*data)->win, 100, 0, 0x00000000, mv);
	mlx_string_put((*data)->mlx, (*data)->win, 99, 1, 0xffffff, mv);
	mlx_string_put((*data)->mlx, (*data)->win, 10, 20, 0x00000000,
		"Collector :");
	mlx_string_put((*data)->mlx, (*data)->win, 9, 21, 0xffffff,
		"Collector :");
	mlx_string_put((*data)->mlx, (*data)->win, 130, 20, 0x00000000,
		cl);
	mlx_string_put((*data)->mlx, (*data)->win, 129, 21, 0xffffff,
		cl);
	free (mv);
	free (cl);
}

void	ft_animation_monster(int x, int y, t_data **data)
{
	if ((*data)->t_img.m == 1)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.monster, x, y);
	else
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.monster2, x, y);
	if ((*data)->t_img.i == 100)
		(*data)->t_img.m = 1;
	else if ((*data)->t_img.i == 200)
	{
		(*data)->t_img.m = 0;
		(*data)->t_img.i = 0;
	}
	(*data)->t_img.i++;
}

void	ft_animation_player(int x, int y, t_data **data)
{
	if ((*data)->t_img.p == 1)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.player_r, x, y);
	else if ((*data)->t_img.p == 0)
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.player_l, x, y);
}
