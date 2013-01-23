#ifndef __CHATAREA_H__
#define __CHATAREA_H__

typedef struct	s_chatarea
{
	t_box_arg		ca_box_args;
	t_textview_arg		ca_tv_args;
	t_treeview_arg		ca_trv_args;
	t_box_arg		ca_topbox_args;
	t_box_arg		ca_botbox_args;
	t_entry_arg		ca_ent_args;
	t_button_arg		ca_but_args;
	GtkWidget*		ca_vbox;
	GtkWidget*		ca_entry;
	GtkWidget*		ca_textarea;
	GtkWidget*		ca_scroll;
	GtkWidget*		ca_botbox;
	GtkWidget*		ca_topbox;
	GtkWidget*		ca_button;
	GtkWidget*		ca_submit;
	GtkListStore*		ca_liststore;
	GtkWidget*		ca_treeview;
	t_parent		ca_parent;
}	t_chatarea;

void		init_simple_chatarea(t_chatarea* args, GtkWidget* parent,
				     t_parent_type type);
void		get_simple_chatarea(t_chatarea* args);


#endif
