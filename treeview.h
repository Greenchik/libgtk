#ifndef __TREEVIEW_H__
#define __TREEVIEW_H__

typedef struct	s_treeview_arg
{
	GtkListStore*	trv_data;
	gboolean	trv_show;
	t_parent	trv_parent;
	int		padding_in_box;
}	t_treeview_arg;

void		get_default_treeview_args(t_treeview_arg* args,
					  GtkWidget* parent,
					  t_parent_type type);
GtkWidget*	get_new_treeview(t_treeview_arg* args);
GtkWidget*	get_new_treeview_column(t_treeview_arg* args);
void		treeview_append_row(GtkWidget* treeview, char* line,
				    int is_allocated);


#endif
