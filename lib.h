#ifndef __MY_GTK_H__
#define __MY_GTK_H__

#include <gtk/gtk.h>

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

typedef void	callback_window_delete_event(GtkWidget* window,
					     GdkEvent* event,
					     gpointer data);
typedef void	callback_window_destroy_event(GtkWidget* window,
					      gpointer data);

typedef struct	s_window_arg
{
	GtkWindowType			win_type;
	char*				win_title;
	unsigned int			win_width;
	unsigned int			win_height;
	gboolean			win_show;
	gboolean			win_resizable;
	GtkWindowPosition		win_position;
	gboolean			win_decorated;
	void*				win_delete_event_data;
	callback_window_delete_event*	win_delete_event_event;
	void*				win_destroy_data;
	callback_window_destroy_event*	win_destroy_event;
	gboolean			win_quit_on_exit;
}	t_window_arg;

void		get_default_window_args(t_window_arg* args);
GtkWidget*	get_new_window(t_window_arg* args);

typedef enum	s_box_orientation
{
	E_MY_GTK_BOX_V,
	E_MY_GTK_BOX_H
}	t_box_orientation;

typedef struct	s_box_arg
{
	t_box_orientation	box_orientation;
	gboolean		box_homogeneous;
	int			box_spacing;
	gboolean		box_show;
	t_parent		box_parent;
}	t_box_arg;

void		get_default_box_args(t_box_arg* args,
				     t_box_orientation orientation,
				     GtkWidget* parent, t_parent_type type);
GtkWidget*	get_new_box(t_box_arg* args);

typedef void	callback_button_clicked(GtkWidget* button, gpointer data);
typedef void	callback_button_enter(GtkWidget* button, gpointer data);
typedef void	callback_button_leave(GtkWidget* button, gpointer data);

typedef struct	s_button_arg
{
	char*				but_label;
	void*				but_clicked_data;
	callback_button_clicked*	but_clicked_event;
	void*				but_enter_data;
	callback_button_enter*		but_enter_event;
	void*				but_leave_data;
	callback_button_leave*		but_leave_event;
	gboolean			but_show;
	t_parent			but_parent;
}	t_button_arg;

void		get_default_button_args(t_button_arg* args, GtkWidget* parent,
					t_parent_type type);
GtkWidget*	get_new_button(t_button_arg* args);

typedef struct	s_notebook_arg
{
	gboolean	not_show;
	t_parent	not_parent;
}	t_notebook_arg;

void		get_default_notebook_args(t_notebook_arg* args,
					  GtkWidget* parent,
					  t_parent_type type);
GtkWidget*	get_new_notebook(t_notebook_arg* args);

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

typedef void	callback_activate(GtkEntry* entry, gpointer data);

typedef struct	s_entry_arg
{
	gboolean		ent_show;
	t_parent		ent_parent;

}	t_entry_arg;

void		get_default_entry_args(t_entry_arg* args, GtkWidget* parent,
				       t_parent_type type);
GtkWidget*	get_new_entry(t_entry_arg* args);
void		entry_connect_activate_signal(GtkWidget* entry,
					      callback_activate* cb,
					      void* data);


typedef struct	s_chatarea
{
	t_box_arg		ca_box_args;
	t_textview_arg		ca_tv_args;
	t_entry_arg		ca_ent_args;
	GtkWidget*		ca_vbox;
	GtkWidget*		ca_entry;
	GtkWidget*		ca_textarea;
	GtkWidget*		ca_scroll;
	t_parent		ca_parent;
}	t_chatarea;

void		init_simple_chatarea(t_chatarea* args, GtkWidget* parent,
				     t_parent_type type);
void		get_simple_chatarea(t_chatarea* args);

#endif
