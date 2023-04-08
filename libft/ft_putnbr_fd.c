/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:56:43 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/25 17:54:34 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrpos(int nb, int fd)
{
	int		p;
	int		cnt;
	int		dig[10];
	char	a;

	cnt = 0;
	while (nb > 0)
	{
		dig[cnt] = nb % 10;
		nb = nb / 10;
		cnt++;
	}
	p = cnt - 1;
	while (p >= 0)
	{
		a = dig[p] + '0';
		write(fd, &a, 1);
		p--;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		write(fd, "0", 1);
	else if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
		ft_putnbrpos(nb, fd);
	}
	else if (nb > 0)
		ft_putnbrpos(nb, fd);
}
