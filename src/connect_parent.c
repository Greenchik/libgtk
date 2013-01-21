#include "lib.h"

void	connect_parent(t_parent* parent, GtkWidget* child)
{
	if (parent->par_type == E_MY_GTK_PARENT_CONTAINER)
		gtk_container_add(GTK_CONTAINER(parent->par_parent), child);
	else if (parent->par_type == E_MY_GTK_PARENT_BOX)
	{
		gtk_box_pack_start(GTK_BOX(parent->par_parent), child,
				  parent->par_expand, parent->par_fill,
				  parent->par_padding);
	}
}
