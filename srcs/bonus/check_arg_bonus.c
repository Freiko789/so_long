/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:08:26 by dtassel           #+#    #+#             */
/*   Updated: 2022/11/14 11:45:27 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_arg(t_data *data, int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("invalid map\n");
		free(data);
		exit(1);
	}
	if (argc != 2)
	{
		perror("Nb args != 2\n");
		free(data);
		exit(1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		perror("Error\nmap has to be .ber !\n");
		free(data);
		exit(1);
	}
}
