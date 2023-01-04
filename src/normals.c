/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:02:04 by ikarjala          #+#    #+#             */
/*   Updated: 2022/12/06 19:17:31 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#if 0
static inline t_vec	plane_normal(t_ray *ray, t_obj *obj)
{
	return (obj->rot);
}

static inline t_vec	cone_normal(t_ray *ray, t_obj *obj)
{
	double	m;
	t_vec	n;
	t_vec	p;

	m = obj->t * vec_dot(ray->dir, obj->rot) +
	vec_dot(vec_sub(ray->orig, obj->pos), obj->rot);
	p = vec_sum(ray->orig, vec_scale(ray->dir, obj->t));
	n = vec_scale(vec_scale(obj->rot, m), (1 + obj->r * obj->r));
	n = vec_norm(vec_sub(vec_sub(p, obj->pos), n));
	if (vec_dot(ray->dir, n) > EPS)
		n = vec_scale(n, -1);
	return (n);
}

static inline t_vec	cylinder_normal(t_vec dir, t_vec hit_p, t_obj *obj)
{
	double	m;
	t_vec	n;
	t_vec	p;

	m = obj->t * vec_dot(ray->dir, obj->rot) +
	vec_dot(vec_sub(ray->orig, obj->pos), obj->rot);
	p = vec_sum(ray->orig, vec_scale(ray->dir, obj->t));
	n = vec_norm(vec_sub(vec_sub(p, obj->pos), vec_scale(obj->rot, m)));
	if (vec_dot(ray->dir, n) > EPS)
		n = vec_scale(n, -1);
	return (n);
}
#endif

/* Return the normal vector of ray intersection point on an sphere's surface.
 * N = Normalize(P - O)
 * where P = ray hit point, O = object origin
*/
static inline t_vec	sphere_normal(t_vec dir, t_vec hit_p, t_obj *obj)
{
	t_vec	n;

	n = vec_norm (vec_sub (hit_p, obj->pos));
	if (vec_dot (dir, n) > EPS)
		return (vec_scale (n, -1));
	return (n);
}

t_vec	get_object_normal(t_vec dir, t_vec hit_point, t_obj *obj)
{
	typedef t_vec (*t_nf)(t_vec, t_vec, t_obj *);
	const t_nf	jmp[] = {
		sphere_normal
		//cylinder_normal,
		//cone_normal
		//plane_normal
	};

	return (jmp [sphere](dir, hit_point, obj));
}