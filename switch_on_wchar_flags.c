/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_on_wchar_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:00:08 by ozharko           #+#    #+#             */
/*   Updated: 2018/02/01 16:00:10 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*how_much_spases_s(wchar_t *res, t_pars *strct, size_t *width)
{
	char		*str;
	size_t		length;
	size_t		key1;

	key1 = (size_t)ft_atoi(strct->pars_key[1]);
	length = ft_strlen_wchar_t(res);
	str = NULL;
	if (length < key1)
		*width = key1 - length;
	else
		*width = 0;
	str = ft_space(ft_strnew(*width + 1), *width);
	return ((wchar_t *)str);
}

wchar_t	*sp_utf_s(wchar_t *res, t_pars *strct, size_t *width, unsigned size)
{
	wchar_t		*str;
	size_t		length;
	size_t		key1;

	key1 = (size_t)ft_atoi(strct->pars_key[1]);
	length = ft_strlen_wchar_t(res);
	str = NULL;
	length = length * size;
	if (length < key1)
		*width = key1 - length;
	else
		*width = 0;
	str = ft_space_wchar_t(ft_strnew_wchar_t(*width + 1), *width);
	return ((wchar_t *)str);
}

wchar_t	*ft_add_prec_s_wchar_t(wchar_t *res, t_pars *strct)
{
	int		num;
	size_t	i;
	wchar_t *tmp;

	i = 0;
	num = strct->precition;
	if (num > 0)
	{
		tmp = res;
		res = ft_strsub_wchar_t(tmp, 0, num);
		free(tmp);
	}
	if (res == NULL)
		res = ft_strdup_wchar_t(L"");
	return (res);
}

int		test_wchar_fun(unsigned int v, int size, t_pars *stc_p)
{
	ft_bzero(stc_p->mask, 4);
	ft_bzero(stc_p->o, 4);
	stc_p->octet = 0;
	stc_p->mask[0] = 0;
	stc_p->mask[1] = 49280;
	stc_p->mask[2] = 14712960;
	stc_p->mask[3] = 4034953344;
	stc_p->v = v;
	if (size == 1)
		p1(stc_p);
	else if (size == 2)
		p2(stc_p);
	else if (size == 3)
		p3(stc_p);
	else if (size == 4)
		p4(stc_p);
	return (0);
}

int		ft_count_bits(unsigned int bit)
{
	unsigned int	i;

	i = 0;
	while (bit != 0)
	{
		bit = bit >> 1;
		i++;
	}
	return (i);
}
