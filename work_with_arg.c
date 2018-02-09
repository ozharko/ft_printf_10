/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:02:04 by ozharko           #+#    #+#             */
/*   Updated: 2018/01/11 08:02:06 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	work_with_arg_p(t_pars *struct_pars, va_list ap, int *length)
{
	char		*result;
	char		*str;
	char		*tmp;
    size_t      width;

    width = 0;
	str = "0x";
	result = type_of_base_x(struct_pars, ap);
	if (struct_pars->pars_key[1] == 0 && struct_pars->precition_on == 1 && struct_pars->precition == 0)
		result = ft_strdup(str);
    else if (struct_pars->pars_key[1] != 0 && struct_pars->precition_on == 0)
    {
        tmp = result;
        if (result[0] == '0' && result[0] == '\0')
            result = ft_strdup(str);
        else
            result = ft_strjoin(str, result);
        free(tmp);
        str = how_much_spases_x(result, struct_pars, &width);
        tmp = result;
		if (struct_pars->flag_minus == 0)
			result = ft_strjoin(str, result);
		else if (struct_pars->flag_minus == '-')
			result = ft_strjoin(result, str);
        free(tmp);
    }
    else if (struct_pars->pars_key[1] != 0 && struct_pars->precition_on == 1)
    {
        if (result[0] == '0' && result[0] == '\0')
            result = ft_strdup(str);
        else
          result = ft_strjoin(str, result);
        str = how_much_spases_x(result, struct_pars, &width);
        tmp = result;
        if (struct_pars->flag_minus == 0)
            result = ft_strjoin(str, result);
        else if (struct_pars->flag_minus == 1)
            result = ft_strjoin(result, str);
        free(tmp);
    }
	else
	{
		tmp = result;
		result = ft_strjoin(str, tmp);
		free(tmp);
	}
	ft_putstr_count(result, length);
	if (result != NULL)
		free(result);
}

char	*w_w_arg_x_if_more(char *res, t_pars *st_p, char **str, size_t width)
{
	if (st_p->precition)
		res = ft_add_prec(res, st_p);
	if (st_p->flag_hash == '#' && st_p->pars_key[4][0] == 'x' &&
		st_p->flag_zero == 0)
		res = str2_free_str1(st_p->zero_small_x, res);
	if (st_p->flag_hash == '#' && st_p->pars_key[4][0] == 'X' &&
		st_p->flag_zero == 0)
		res = str2_free_str1(st_p->zero_big_x, res);
	if (*str != NULL)
		free(*str);
	*str = how_much_spases_x(res, st_p, &width);
	if (st_p->flag_minus)
		res = ft_strjoin(res, *str);
	else if (st_p->flag_zero && st_p->precition == 0 &&
		res[0] != '0')
		res = ft_strjoin(ft_num_zero(*str), res);
	else if (width != 0)
		res = str2_free_str1(*str, res);
	if (st_p->flag_hash == '#' && st_p->pars_key[4][0] == 'x' &&
		st_p->flag_zero)
		res = str2_free_str1(st_p->zero_small_x, res);
	if (st_p->flag_hash == '#' && st_p->pars_key[4][0] == 'X' &&
		st_p->flag_zero)
		res = str2_free_str1(st_p->zero_big_x, res);
	return (res);
}

void	work_with_arg_x(t_pars *struct_pars, va_list ap, int *length)
{
	size_t			width;
	char			*str;
	char			*result;

	result = type_of_base_x(struct_pars, ap);
	str = how_much_spases_x(result, struct_pars, &width);
	if (result[0] != '0')
		result = w_w_arg_x_if_more(result, struct_pars, &str, width);
	if (struct_pars->precition_on == 1 && struct_pars->precition == 0)
	{
		ft_putstr_count(str, length);
		if (str != NULL)
			free(str);
		return ;
	}

	if (result[0] == '0' && result[1] == '\0')
	{
		result = ft_strjoin(str, result);
		ft_putstr_count(result, length);
	}
    else
        ft_putstr_count(result, length);
	free_work_with_arg(result, str);
}

void	work_with_arg_o(t_pars *str_prs, va_list ap, int *length)
{
	size_t			width;
	char			*str;
	char			*result;

	result = type_of_base_o(str_prs, ap);
	if (str_prs->precition)
		result = ft_add_prec(result, str_prs);
	if (str_prs->flag_hash == '#' && result[0] != '0')
		result = ft_strjoin("0", result);
	str = how_much_spases_o(result, str_prs, &width);
	if (str_prs->flag_minus)
		result = ft_strjoin(result, str);
	else if (str_prs->flag_zero && str_prs->precition == 0)
		result = ft_strjoin(ft_num_zero(str), result);
	if (width != 0 && str_prs->flag_zero == 0 && str_prs->flag_minus == 0)
		result = ft_strjoin(str, result);
	if (str_prs->precition_on == 1 && str_prs->precition == 0 &&
		str_prs->flag_hash != '#')
	{
		ft_putstr_count(str, length);
		return ;
	}
	ft_putstr_count(result, length);
	free_work_with_arg(result, str);
}

void	work_with_arg_percent(t_pars *struct_pars, int *length)
{
	char		*result;
	size_t		width;
	char		*str;

	result = (char *)malloc(sizeof(char) * 2);
	result[1] = '\0';
	result[0] = '%';
	str = hw_mch_sp(result, struct_pars, &width);
	if (struct_pars->flag_minus)
		result = ft_strjoin(result, str);
	else if (width != 0)
		result = ft_strjoin(str, result);
	ft_putstr_count(result, length);
	free_work_with_arg(result, str);
}