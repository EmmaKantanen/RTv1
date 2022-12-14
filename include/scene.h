/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:57:29 by ikarjala          #+#    #+#             */
/*   Updated: 2022/12/01 17:44:30 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "render.h"

typedef struct s_light
{
	t_vec	pos;
	double	intensity;
}	t_light;

typedef struct s_object
{
	int		id;
	t_vec	pos;
	t_vec	rot;
	double	r;
	double	gloss;
	double	specular;
	t_rgbf	color;
}	t_obj; // TODO: inheritance

typedef struct s_cam
{
	t_vec	pos;
	t_vec	rot;
	// TODO: union (euler / forward) instead of rot
}	t_cam;

typedef struct s_ray
{
	t_vec	orig;
	t_vec	dir;
}	t_ray;

typedef struct s_scene_context {
	t_cam	cam;
	t_light	light;
	t_obj	obj[1];
	double	ambient;
}	t_scene;

enum e_object_type {
	sphere = 0,
	cylinder = 1,
	cone = 2,
	plane = 3
};

#endif
