/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmekoudi <gmekoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:01:09 by gmekoudi          #+#    #+#             */
/*   Updated: 2023/09/04 16:31:32 by gmekoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int size, int negatif)
{	
	char	moins;
	char	a;

	moins = 45;
	if (negatif)
		write(1, &moins, 1);
	while (size >= 0)
	{
		a = str[size--];
		write(1, &a, 1);
	}
}

void	ft_putnbr(int nb)
{
	char		digital[10];
	int			i;
	char		a;
	long int	long_nb;

	a = '0';
	long_nb = (long int) nb;
	if (long_nb < 0)
		long_nb *= -1;
	if (long_nb == 0)
	{
		write(1, &a, 1);
		return ;
	}
	i = 0;
	while (long_nb > 0)
	{
		digital[i++] = (char)(long_nb % 10) + 48;
		long_nb = (long_nb - (long_nb % 10)) / 10;
	}
	ft_putstr(digital, i - 1, nb < 0);
}
/*int	main(void)
{
	ft_putnbr(-42);
	return (0);
}*/
