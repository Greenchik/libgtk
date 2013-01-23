#include "lib.h"

void	init_simple_chatarea(t_chatarea* args, GtkWidget* parent,
			     t_parent_type type)
{
	get_default_box_args(&args->ca_box_args, E_MY_GTK_BOX_V, parent,
			     type);
	get_default_box_args(&args->ca_topbox_args, E_MY_GTK_BOX_H,
			     NULL, E_MY_GTK_PARENT_BOX);
	args->ca_topbox_args.box_parent.par_fill = TRUE;
	args->ca_topbox_args.box_parent.par_expand = TRUE;
	get_default_textview_args(&args->ca_tv_args, NULL,
				  E_MY_GTK_PARENT_BOX);
	get_default_treeview_args(&args->ca_trv_args, NULL,
				  E_MY_GTK_PARENT_BOX);
	args->ca_tv_args.tv_parent.par_expand = TRUE;
	args->ca_tv_args.tv_parent.par_fill = TRUE;
	args->ca_tv_args.tv_parent.par_padding = 100;
	args->ca_trv_args.trv_parent.par_fill = TRUE;
	args->ca_trv_args.trv_parent.par_expand = TRUE;
	//args->ca_trv_args.trv_parent.par_padding = 100;
	get_default_box_args(&args->ca_botbox_args, E_MY_GTK_BOX_H,
			     NULL, E_MY_GTK_PARENT_BOX);
	get_default_entry_args(&args->ca_ent_args, NULL,
			       E_MY_GTK_PARENT_BOX);
	get_default_button_args(&args->ca_but_args, NULL,
				E_MY_GTK_PARENT_BOX);
	args->ca_ent_args.ent_parent.par_fill = TRUE;
	args->ca_ent_args.ent_parent.par_expand = TRUE;
}

void	get_simple_chatarea(t_chatarea* args)
{
	args->ca_vbox = get_new_box(&args->ca_box_args);
	args->ca_topbox_args.box_parent.par_parent = args->ca_vbox;
	args->ca_topbox = get_new_box(&args->ca_topbox_args);
	args->ca_tv_args.tv_parent.par_parent = args->ca_topbox;
	args->ca_textarea = get_new_textview_scrolled(&args->ca_tv_args,
						      &args->ca_scroll);
	args->ca_trv_args.trv_parent.par_parent = args->ca_topbox;
	args->ca_treeview = get_new_treeview(&args->ca_trv_args);
	args->ca_botbox_args.box_parent.par_parent = args->ca_vbox;
	args->ca_botbox = get_new_box(&args->ca_botbox_args);
	args->ca_ent_args.ent_parent.par_parent = args->ca_botbox;
	args->ca_entry = get_new_entry(&args->ca_ent_args);
	args->ca_but_args.but_parent.par_parent = args->ca_botbox;
	args->ca_button = get_new_button(&args->ca_but_args);
}
