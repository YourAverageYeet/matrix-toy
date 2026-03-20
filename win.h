#ifndef     WIN_H_INCLUDED
#define     WIN_H_INCLUDED

#include "fl/window.h"

void cb_mat_apply(Fl_Return_Button*, Matrix33*);

void cb_mat_view_reset(Fl_Button*, bool*);

void cb_keyed_mode(Fl_Light_Button*, void*);

#endif  //  WIN_H_INCLUDED
