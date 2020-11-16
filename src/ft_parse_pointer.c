/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:18 by kaye              #+#    #+#             */
/*   Updated: 2020/11/16 21:18:25 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_parse_pointer(void *p)
{
    char *ls;

    ft_putstr("0x");
    ls = ft_ulltoa_base((unsigned long long)p, 16, 0);
    ft_putstr(ls);
    free(ls);
}