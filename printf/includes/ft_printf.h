/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:54:43 by dtassel           #+#    #+#             */
/*   Updated: 2022/06/09 11:40:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_ptunsigned(unsigned int n);
int		ft_ptnbr(int n);
int		ft_ptstr(char *str);
int		ft_ptchar(int c);
int		ft_pt_ptr(unsigned long adr);
int		ft_pthexal(unsigned int num);
int		ft_pthexat(unsigned int num);

#endif
