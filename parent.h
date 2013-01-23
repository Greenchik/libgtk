#ifndef __PARENT_H__
#define __PARENT_H__

typedef enum	s_parent_type
{
	E_MY_GTK_PARENT_CONTAINER,
	E_MY_GTK_PARENT_BOX,
	E_MY_GTK_PARENT_NONE
}	t_parent_type;

typedef struct	s_parent
{
	t_parent_type	par_type;
	GtkWidget*	par_parent;
	gboolean	par_expand;
	gboolean	par_fill;
	unsigned int	par_padding;
}	t_parent;

void		set_default_parent(t_parent* parent, GtkWidget* _parent,
				   t_parent_type type);
void		set_parent_parent(t_parent* parent, GtkWidget* _parent);
void		set_parent_expand(t_parent* parent, gboolean expand);
void		set_parent_fill(t_parent* parent, gboolean fill);
void		set_parent_padding(t_parent* parent, unsigned int padding);
void		connect_parent(t_parent* parent, GtkWidget* child);

#endif
