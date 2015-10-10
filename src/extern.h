/* Interfaces to system-dependent kernel and library entries.
   Copyright (C) 1985, 1986, 1987, 1988, 1990 Free Software Foundation, Inc.

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

struct buffer;
struct save_signal;
struct stat;
struct window;

/* alloc.c */
extern void display_malloc_warning (void);
extern void malloc_warning (char *);
extern void memory_full (void);

/* callproc.c */
extern void child_setup (int, int, int, char **, char **);

/* cmds.c */
extern int forward_point (int);
extern int self_insert_internal (char, int);

/* dispnew.c */
extern void bell (void);
extern void cancel_line (int);
extern void cancel_my_columns (struct window *);
extern void change_screen_size (int, int, int, int, int);
extern void clear_screen_records (void);
extern int direct_output_forward_char (int);
extern int direct_output_for_insert (int);
extern void do_pending_window_change (void);
extern void preserve_other_columns (struct window *);
extern void quit_error_check (void);
extern void redisplay (void);
extern int update_screen (int, int);

/* doprnt.c */
extern int doprnt (char *, int, char *, int, char **);

/* editfns.c */
extern int clip_to_bounds (int, int, int);

/* filelock.c */
extern void unlock_all_files (void);
extern void unlock_buffer (struct buffer *);

/* filemode.c */
void filemodestring (struct stat *, char *);

/* indent.c */
int current_column (void);

/* insdel.c */
extern void InsStr (char *);
extern void del_range (int, int);
extern void insert (unsigned char *, int);
extern void insert_before_markers (unsigned char *, int);
extern void insert_char (unsigned char);
extern void make_gap (int);
extern void modify_region (int, int);
extern void move_gap (int);
extern void prepare_to_modify_buffer (void);

/* keyboard.c */
extern int input_pending;
extern int kbd_count;
extern void clear_input_pending (void);
extern void clear_waiting_for_input (void);
extern void consume_available_input (void);
extern int detect_input_pending (void);
extern void interrupt_signal (void);
extern void gobble_input (void);
extern void quit_throw_to_read_command_char (void);
extern int read_command_char (int);
extern void record_auto_save (void);
extern void set_waiting_for_input (long *);
extern void start_polling (void);
extern void stop_polling (void);

/* keymap.c */
extern char *push_key_description (unsigned int, char *);

/* minibuf.c */
extern int scmp (char *, char *, int);

/* print.c */
extern void write_string (char *, int);

/* process.c */
extern void close_process_descs (void);

/* scroll.c */
extern void CalcIDCosts (char *, char *, char *, char *, char *, char *);
extern void CalcLID (int, int, int, int, int *, int *);
extern void scrolling_1 (int, int, int, int *, int *, int *, int);
extern int scrolling_max_lines_saved (int, int, int *, int *, int *);
extern int scroll_cost (int, int, int);

/* search.c */
extern int find_next_newline (int, int);

/* sysdep.c */
extern void child_setup_tty (int);
extern void discard_tty_input (void);
#ifdef subprocesses
extern void flush_pending_output (int);
#endif
extern void get_screen_size (int *, int *);
extern char *get_system_name(void);
extern void init_baud_rate (void);
extern void init_sys_modes (void);
extern void read_input_waiting (void);
extern void request_sigio (void);
extern void reset_sys_modes (void);
extern void restore_signal_handlers (struct save_signal *);
extern void save_signal_handlers (struct save_signal *);
extern void setpgrp_of_tty (int);
extern void setup_pty (int);
extern void set_exclusive_use (int);
extern void stuff_char (char);
extern int sys_suspend (void);
extern int tabs_safe_p (void);
extern void unrequest_sigio (void);
extern void wait_for_termination (int);
#ifndef subprocesses
extern void wait_without_blocking (void);
#endif

/* syntax.c */
extern int scan_words (int, int);

/* term.c */
extern void calculate_costs (void);
extern void clear_screen (void);
extern void change_line_highlight (int, int, int);
extern void clear_end_of_line (int);
extern void delete_chars (int);
extern void insert_chars (char *, int);
extern void ins_del_lines (int, int);
extern void move_cursor (int, int);
extern void output_chars (char *, int);
extern int per_line_cost (char *);
extern void reassert_line_highlight (int, int);
extern void reset_terminal_modes (void);
extern void ring_bell (void);
extern void set_terminal_modes (void);
extern void set_terminal_window (int);
extern int string_cost (char *);
extern void term_init (char *);
extern void update_begin (void);
extern void update_end (void);

/* undo.c */
extern void record_change (int, int);
extern void record_delete (int, int);

/* unexe*.c */
extern void unexec (char *, char *, unsigned int, unsigned int, unsigned int);

/* xdisp.c */
extern void message ();
extern void message1 (char *);
extern void redisplay_preserve_echo_area (void);
