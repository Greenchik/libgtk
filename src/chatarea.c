#include "lib.h"

void	init_simple_chatarea(t_chatarea* args, GtkWidget* parent,
			     t_parent_type type)
{
	get_default_box_args(&args->ca_box_args, E_MY_GTK_BOX_V, parent,
			     type);
	args->ca_vbox = get_new_box(&args->ca_box_args);
	get_default_textview_args(&args->ca_tv_args, args->ca_vbox,
				  E_MY_GTK_PARENT_BOX);
	args->ca_tv_args.tv_parent.par_expand = TRUE;
	args->ca_tv_args.tv_parent.par_fill = TRUE;
	get_default_entry_args(&args->ca_ent_args, args->ca_vbox,
			       E_MY_GTK_PARENT_BOX);
	args->ca_ent_args.ent_parent.par_fill = TRUE;
}

void	get_simple_chatarea(t_chatarea* args)
{
	args->ca_textarea = get_new_textview_scrolled(&args->ca_tv_args,
						      &args->ca_scroll);
	args->ca_entry = get_new_entry(&args->ca_ent_args);
}
