/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:16:15 by david             #+#    #+#             */
/*   Updated: 2022/11/14 14:43:40 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	ft_exit_mouse(t_data *data)
{
	ft_exit(data, NULL);
	return (0);
}

void	ft_exit(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
		perror(str);
	if (data->map != NULL)
	{
		while (data->map[i])
			i++;
		while (i >= 0)
			free(data->map[i--]);
		free (data->map);
	}
	exit(0);
}

void	init_data(t_data *data)
{
	data->win_h = 0;
	data->win_w = 0;
	data->img_w = 0;
	data->img_h = 0;
	data->collector = 0;
	data->movement = 0;
	data->t_img.p = 1;
	data->i = 0;
	data->movement_m = 0;
	data->t_img.c = NULL;
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->t_img.ground = NULL;
	data->t_img.wall = NULL;
	data->t_img.collector = NULL;
	data->t_img.monster = NULL;
	data->t_img.monster2 = NULL;
	data->t_img.player_r = NULL;
	data->t_img.player_l = NULL;
	data->t_img.exit_open = NULL;
	data->t_img.m = 0;
}

void	init_img(t_data *data)
{
	data->t_img.ground = mlx_xpm_file_to_image(data->mlx,
			"./sprites/ground.xpm", &data->img_w, &data->img_h);
	data->t_img.wall = mlx_xpm_file_to_image(data->mlx,
			"./sprites/wall.xpm", &data->img_w, &data->img_h);
	data->t_img.player_r = mlx_xpm_file_to_image(data->mlx,
			"./sprites/player.xpm", &data->img_w, &data->img_h);
	data->t_img.player_l = mlx_xpm_file_to_image(data->mlx,
			"./sprites/player2.xpm", &data->img_w, &data->img_h);
	data->t_img.monster = mlx_xpm_file_to_image(data->mlx,
			"./sprites/knightf.xpm", &data->img_w, &data->img_h);
	data->t_img.monster2 = mlx_xpm_file_to_image(data->mlx,
			"./sprites/knightf1.xpm", &data->img_w, &data->img_h);
	data->t_img.collector = mlx_xpm_file_to_image(data->mlx,
			"./sprites/collector.xpm", &data->img_w, &data->img_h);
	data->t_img.exit = mlx_xpm_file_to_image(data->mlx,
			"./sprites/closed door.xpm", &data->img_w, &data->img_h);
	data->t_img.exit_open = mlx_xpm_file_to_image(data->mlx,
			"./sprites/opened door.xpm", &data->img_w, &data->img_h);
	if (data->t_img.ground == NULL || data->t_img.wall == NULL
		|| data->t_img.player_l == NULL || data->t_img.player_r == NULL
		|| data->t_img.monster == NULL || data->t_img.monster2 == NULL
		|| data->t_img.collector == NULL || data->t_img.exit == NULL
		|| data->t_img.exit_open == NULL)
		ft_exit(data, "Error sprite\n");
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	check_arg(data, argc, argv);
	init_data(data);
	init_map(data, argv);
	check_map(data, argv);
	ft_count_collect(data);
	data->mlx = mlx_init();
	if (data->mlx == 0)
		ft_exit(data, "Error\n");
	data->win = mlx_new_window(data->mlx, data->win_w * 50,
			data->win_h * 50, "so_long");
	if (data->win == 0)
		ft_exit(data, "Error\n");
	init_img(data);
	mlx_key_hook(data->win, player_mv, data);
	mlx_hook(data->win, 17, 1L << 17, ft_exit_mouse, data);
	mlx_loop_hook(data->mlx, put_map, &data);
	mlx_loop(data->mlx);
	return (0);
}
