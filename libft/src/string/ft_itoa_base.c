/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:55:23 by kaye              #+#    #+#             */
/*   Updated: 2020/11/25 22:35:17 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_conv_dh_itoa(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

char			*ft_itoa_base(int n, int base)
{
	size_t			len;
	char			*str;
	unsigned int	n_tmp;

	n_tmp = (n < 0) ? -(unsigned int)n : n;
	len = (n < 0) ? ft_intlen_base(n_tmp, base) + 1 :
					ft_intlen_base(n_tmp, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh_itoa(n_tmp % base);
		n_tmp /= base;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
