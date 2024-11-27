/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:19:46 by david             #+#    #+#             */
/*   Updated: 2022/11/14 14:12:16 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_data *data, char **argv)
{
	char	*line;
	char	*map;
	int		fd;

	line = "";
	map = ft_calloc(1, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = ft_strjoin(map, line);
		data->win_w = ft_strlen(line);
		data->win_h++;
		free(line);
	}
	free(line);
	if (map[ft_strlen(map)-1] == '\n')
		data->win_w--;
	data->map = ft_split(map, '\n');
	free(map);
	close(fd);
}

void	ft_count_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				data->collector++;
			}
		j++;
		}
	i++;
	}
}

void	put_img(char c, int x, int y, t_data **data)
{
	if (c == '1')
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.ground, x, y);
	else if (c == 'C')
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.collector, x, y);
	else if (c == 'P')
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.player_r, x, y);
	else if (c == 'E')
	{
		if ((*data)->collector == 0)
			mlx_put_image_to_window((*data)->mlx, (*data)->win,
				(*data)->t_img.exit_open, x, y);
		else
			mlx_put_image_to_window((*data)->mlx, (*data)->win,
				(*data)->t_img.exit, x, y);
	}
	else if (c == 'M')
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			(*data)->t_img.monster, x, y);
}

int	put_map(t_data **data)
{
	int	map_x;
	int	map_y;
	int	x;
	int	y;

	y = 0;
	map_y = 0;
	while ((*data)->map[map_y])
	{
		map_x = 0;
		x = 0;
		while ((*data)->map[map_y][map_x])
		{
			put_img((*data)->map[map_y][map_x], x, y, data);
			map_x++;
			x += (*data)->img_w;
		}
		map_y++;
		y += (*data)->img_h;
	}
	return (0);
}
