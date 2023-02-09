/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:39:59 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/09 09:40:02 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

/* ************************************************************************** */
/* INCLUDES																	  */
/* ************************************************************************** */

# include <stdio.h>

# include "global.h"
# include "cmd.h"

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

// PRINTER_CMD
void	printer_cmd(t_list *l_cmd);
void	printer_structure(t_list *l_cmd);

// PRINTER_SCMD
void	printer_scmd(t_c_scmd *scmd);
void	printer_other(int type);
void	printer_scmd_pipeline(t_list *l_scmd_pipeline, bool newline);

// PRINTER_TOKEN
void	printer_token(t_list *l_token);

#endif
