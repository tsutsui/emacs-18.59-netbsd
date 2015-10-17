/* Hooks by which low level terminal operations
   can be made to call other routines.
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


extern void (*move_cursor_hook) (int, int);
extern void (*raw_move_cursor_hook) (int, int);

extern void (*clear_to_end_hook) (void);
extern void (*clear_screen_hook) (void);
extern void (*clear_end_of_line_hook) (int);

extern void (*ins_del_lines_hook) (int, int);

extern void (*change_line_highlight_hook) (int, int, int);
extern void (*reassert_line_highlight_hook) (int, int);

extern void (*insert_chars_hook) (char *, int);
extern void (*output_chars_hook) (char *, int);
extern void (*delete_chars_hook) (int);

extern void (*ring_bell_hook) (void);

extern void (*reset_terminal_modes_hook) (void);
extern void (*set_terminal_modes_hook) (void);
extern void (*update_begin_hook) (void);
extern void (*update_end_hook) (void);
extern void (*set_terminal_window_hook) (int);

extern int (*read_socket_hook) (int, char *, int);
extern void (*fix_screen_hook) (void);
extern void (*calculate_costs_hook) (int, int *, int *);

/* If nonzero, send all terminal output characters to this stream also.  */

extern FILE *termscript;

