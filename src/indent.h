/* Definitions for interface to indent.c
   Copyright (C) 1985, 1986 Free Software Foundation, Inc.

This file is part of GNU Emacs.

GNU Emacs is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 1, or (at your option)
any later version.

GNU Emacs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Emacs; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */


struct position
  {
    Lisp_Object_Int bufpos;
    int hpos;
    int vpos;
    Lisp_Object_Int prevhpos;
    int contin;
  };

struct position *compute_motion (Lisp_Object_Int, int, int, Lisp_Object_Int, Lisp_Object_Int, Lisp_Object_Int, Lisp_Object_Int, Lisp_Object_Int, int);
void invalidate_current_column (void);
int position_indentation (int);
int pos_tab_offset (struct window *, int);
struct position *vmotion (int, int, int, int, Lisp_Object);
