#include "lib.h"

void	set_default_parent(t_parent* parent, GtkWidget* _parent,
			   t_parent_type type)
{
	parent->par_type = type;
	parent->par_parent = _parent;
	parent->par_expand = FALSE;
	parent->par_fill = FALSE;
	parent->par_padding = 0;
}

void	set_parent_parent(t_parent* parent, GtkWidget* _parent)
{
	parent->par_parent = _parent;
}

void	set_parent_expand(t_parent* parent, gboolean expand)
{
	parent->par_expand = expand;
}

void	set_parent_fill(t_parent* parent, gboolean fill)
{
	parent->par_fill = fill;
}

void	set_parent_padding(t_parent* parent, unsigned int padding)
{
	parent->par_padding = padding;
}
