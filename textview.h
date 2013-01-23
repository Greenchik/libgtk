#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__

typedef struct	s_textview_arg
{
	gboolean	tv_show;
	gboolean	tv_editable;
	gboolean	tv_cursor_visible;
	GtkTextBuffer*	tv_buffer;
	t_parent	tv_parent;
}	t_textview_arg;

void		get_default_textview_args(t_textview_arg* args,
					  GtkWidget* parent,
					  t_parent_type type);
GtkWidget*	get_new_textview(t_textview_arg* args);
GtkWidget*	get_new_textview_scrolled(t_textview_arg* args, GtkWidget** scroll);
void		textview_append_text(GtkWidget* textview, char* line);

#endif
