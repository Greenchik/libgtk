#ifndef __ENTRY_H__
#define __ENTRY_H__

typedef struct	s_entry_arg
{
	gboolean	ent_show;
	t_parent	ent_parent;
	cb_entry*	ent_activate_event;
	void*		ent_activate_data;

}	t_entry_arg;

void		get_default_entry_args(t_entry_arg* args, GtkWidget* parent,
				       t_parent_type type);
GtkWidget*	get_new_entry(t_entry_arg* args);

#endif
