/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:58:26 by dtassel           #+#    #+#             */
/*   Updated: 2022/11/13 13:45:44 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_img
{
	void		*player_r;
	void		*player_l;
	void		*monster;
	void		*monster2;
	void		*collector;
	void		*exit;
	void		*exit_open;
	void		*wall;
	void		*ground;
	char		*c;
	int			p;
	int			m;
	int			i;
}	t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				win_w;
	int				win_h;
	int				img_w;
	int				img_h;
	char			**map;
	int				collector;
	int				movement;
	int				movement_m;
	int				i;
	struct s_img	t_img;
}	t_data;

void	check_arg(t_data *data, int argc, char **argv);
void	check_map(t_data *data, char **argv);
void	init_map(t_data *data, char **argv);
int		put_map(t_data **data);
int		player_mv(int keycode, t_data *data);
void	ft_exit(t_data *data, char *str);
void	ft_die(t_data *data);
int		ft_action(t_data *data);
void	update_map_up(t_data *data, int i, int j);
void	update_map_right(t_data *data, int i, int j);
void	update_map_left(t_data *data, int i, int j);
void	update_map_down(t_data *data, int i, int j);
void	ft_count_collect(t_data *data);
void	ft_animation_monster(int x, int y, t_data **data);
void	ft_animation_player(int x, int y, t_data **data);
void	ft_mv_monster(t_data **data);
int		ft_check_path(t_data *data, char **argv);
int		ft_printf(const char *str, ...);
void	put_string(t_data **data);
void	init_data(t_data *data);
void	ft_check_one_player(t_data *data);
void	ft_check_one(int i, int j, t_data *data);
void	ft_check_len(size_t j, t_data *data);
void	ft_check_close(int i, t_data *data);
void	ft_check(int i, int j, t_data *data);

#endif