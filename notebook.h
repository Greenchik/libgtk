#ifndef __NOTEBOOK_H__
#define __NOTEBOOK_H__

typedef struct	s_notebook_arg
{
	gboolean	not_show;
	t_parent	not_parent;
}	t_notebook_arg;

void		get_default_notebook_args(t_notebook_arg* args,
					  GtkWidget* parent,
					  t_parent_type type);
GtkWidget*	get_new_notebook(t_notebook_arg* args);

#endif
