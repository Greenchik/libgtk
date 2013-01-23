#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct	s_button_arg
{
	char*		but_label;
	cb_button*	but_activate_event;
	cb_button*	but_clicked_event;
	cb_button*	but_enter_event;
	cb_button*	but_leave_event;
	cb_button*	but_pressed_event;
	cb_button*	but_released_event;
	void*		but_activate_data;
	void*		but_clicked_data;
	void*		but_enter_data;
	void*		but_leave_data;
	void*		but_pressed_data;
	void*		but_released_data;
	gboolean	but_show;
	t_parent	but_parent;
}	t_button_arg;

void		get_default_button_args(t_button_arg* args, GtkWidget* parent,
					t_parent_type type);
GtkWidget*	get_new_button(t_button_arg* args);

#endif
