/* Definitions file for GNU Emacs running on Linux
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

/* $Id: s-linux.h,v 1.1.2.3 1999/11/05 08:17:23 friedman Exp $ */
/* This config.h written for Linux 2.0 ELF, gcc 2.7, libc 5.2, and X11R6 */

/*
 *	Define symbols to identify the version of Unix this is.
 *	Define all the symbols that apply correctly.
 */

#define USG				/* System III, System V, etc */
#define USG5

/* SYSTEM_TYPE should indicate the kind of system you are using.
 It sets the Lisp variable system-type.  */

#define SYSTEM_TYPE "linux"

/* nomultiplejobs should be defined if your system's shell
 does not have "job control" (the ability to stop a program,
 run some other program, then continue the first one).  */

/* #define NOMULTIPLEJOBS */

/* This requires SIGIO to work properly; Linux 2.0 has it. */
#define INTERRUPT_INPUT

/* Letter to use in finding device name of first pty,
  if system supports pty's.  'p' means it is /dev/ptyp0  */

#define FIRST_PTY_LETTER 'p'

/*
 *	Define HAVE_TERMIO if the system provides sysV-style ioctls
 *	for terminal control.
 */

#define HAVE_TERMIO

/*
 *	Define HAVE_TIMEVAL if the system supports the BSD style clock values.
 *	Look in <sys/time.h> for a timeval structure.
 */

#define HAVE_TIMEVAL

/*
 *	Define HAVE_SELECT if the system supports the `select' system call.
 */

#define HAVE_SELECT

/*
 *	Define HAVE_PTYS if the system supports pty devices.
 */

#define HAVE_PTYS

/* Define HAVE_SOCKETS if system supports 4.2-compatible sockets.  */

#define HAVE_SOCKETS

/*
 *	Define NONSYSTEM_DIR_LIBRARY to make Emacs emulate
 *      The 4.2 opendir, etc., library functions.
 */

/* #define NONSYSTEM_DIR_LIBRARY */

/* Define this symbol if your system has the functions bcopy, etc. */

#define BSTRING

/* subprocesses should be defined if you want to
 have code for asynchronous subprocesses
 (as used in M-x compile and M-x shell).
 This is supposed to work now on system V release 2.  */

#define subprocesses

/* If your system uses COFF (Common Object File Format) then define the
   preprocessor symbol "COFF". */

/* #define COFF */

/* define MAIL_USE_FLOCK if the mailer uses flock
   to interlock access to /usr/spool/mail/$USER.
   The alternative is that a lock file named
   /usr/spool/mail/$USER.lock.  */

/* #define MAIL_USE_FLOCK */

/* Define CLASH_DETECTION if you want lock files to be written
   so that Emacs can tell instantly when you try to modify
   a file that someone else has modified in his Emacs.  */

#define CLASH_DETECTION

/* Define SHORTNAMES if the C compiler can distinguish only
   short names.  It means that the stuff in ../shortnames
   must be run to convert the long names to short ones.  */

/* #define SHORTNAMES */

/* extend max filesize to 32 Meg */
#define VALBITS 26
#define GCTYPEBITS 5


/* Special hacks needed to make Emacs run on this system.  */

/* On USG systems the system calls are interruptable by signals
 that the user program has elected to catch.  Thus the system call
 must be retried in these cases.  To handle this without massive
 changes in the source code, we remap the standard system call names
 to names for our own functions in sysdep.c that do the system call
 with retries. */

#define open sys_open
#define close sys_close
#define read sys_read
#define write sys_write

#define INTERRUPTABLE_OPEN
#define INTERRUPTABLE_CLOSE
#define INTERRUPTABLE_IO

/* let's see, what have we got here */

#define HAVE_TCATTR		/* fixes ^z problems */
#define HAVE_SETSID		/* fixes shell problems */
#define HAVE_DUP2		/* is builtin */
#define HAVE_GETTIMEOFDAY	/* is builtin */
#define HAVE_RENAME		/* is builtin */
#define HAVE_RANDOM		/* is builtin */
#define HAVE_CLOSEDIR		/* we have a closedir */
#define HAVE_GETPAGESIZE	/* we now have getpagesize (0.96) */
#define HAVE_VFORK		/* we now have vfork (0.96) */
#define HAVE_SYS_SIGLIST	/* we have a (non-standard) sys_siglist */
#define SYS_SIGLIST_DECLARED
#define HAVE_GETWD		/* cure conflict with getcwd? */

#define NO_SIOCTL_H		/* don't have sioctl.h */
#define SYSV_SYSTEM_DIR		/* use dirent.h */
#define USG_SYS_TIME		/* use sys/time.h, not time.h */

#define POSIX			/* affects only getpagesize.h */
#define POSIX_SIGNALS		/* uses sigaction from sys_signal */

#ifdef HAVE_PTMX

/* This change means that we don't loop through allocate_pty too many
   times in the (rare) event of a failure. */

#undef FIRST_PTY_LETTER
#define FIRST_PTY_LETTER 'z'

/* This sets the name of the master side of the PTY. */

#define PTY_NAME_SPRINTF strcpy (pty_name, "/dev/ptmx");

/* This is the same definition as in usg5-4.h, but with sigblock/sigunblock
   rather than sighold/sigrelse, which appear to be BSD4.1 specific and won't
   work if POSIX_SIGNALS is defined.  It may also be appropriate for SVR4.x
   (x<2) but I'm not sure.   fnf@cygnus.com */
/* This sets the name of the slave side of the PTY.  On SysVr4,
   grantpt(3) forks a subprocess, so keep sigchld_handler() from
   intercepting that death.  If any child but grantpt's should die
   within, it should be caught after sigrelse(2). */

#undef PTY_TTY_NAME_SPRINTF
#define PTY_TTY_NAME_SPRINTF			\
  {						\
    char *ptsname (), *ptyname;			\
						\
    sigblock (sigmask (SIGCLD));		\
    if (grantpt (fd) == -1)			\
      { close (fd); return -1; }		\
    sigunblock (sigmask (SIGCLD));		\
    if (unlockpt (fd) == -1)			\
      { close (fd); return -1; }		\
    if (!(ptyname = ptsname (fd)))		\
      { close (fd); return -1; }		\
    strncpy (pty_name, ptyname, sizeof (pty_name)); \
    pty_name[sizeof (pty_name) - 1] = 0;	\
  }

#endif /* HAVE_PTMX */

/* Unless this is defined, XFlush crashes emacs because of fd duping
   performed in x11term.c (x_init_1). */
#define SYSV_STREAMS

/* note: system malloc does not work with shared libs
   This was reported with earlier versions of linux (libc 4).
   Still true?
 */
#if 0				/* choose for yourself */
#define SYSTEM_MALLOC		/* produces smaller binary */
#endif

/* misc. kludges for linux */
#if !(defined (__GLIBC__) && (__GLIBC__ >= 2))
#define MAXNAMLEN NAME_MAX	/* missing SYSV-ism */
#endif

#define SIGSYS SIGUNUSED	/* rename to harmless work-alike */
#define VSWTCH VSWTC		/* mis-spelling in termios.h? */

/* we have non-standard standard I/O (iostream) ... */
#ifdef emacs
#include <stdio.h>  /* Get the definition of _IO_STDIO_H.  */
#if defined(_IO_STDIO_H) || defined(_STDIO_USES_IOSTREAM)
/* new C libio names */
#define PENDING_OUTPUT_COUNT(FILE) \
  ((FILE)->_IO_write_ptr - (FILE)->_IO_write_base)
#else /* !_IO_STDIO_H */
/* old C++ iostream names */
#define PENDING_OUTPUT_COUNT(FILE) \
  ((FILE)->_pptr - (FILE)->_pbase)
#endif /* !_IO_STDIO_H */
#endif /* emacs */

/* This is for debugging; otherwise, gdb cannot access numerous structure
   members like XXdisplay->fd, etc. */
#define XLIB_ILLEGAL_ACCESS

#ifdef __ELF__
#define UNEXEC unexelf.o
#define UNEXEC_USE_MAP_PRIVATE
#define DATA_SEG_BITS 0x08000000
#endif

#define C_COMPILER gcc
#define C_DEBUG_SWITCH -g
#define C_OPTIMIZE_SWITCH -O3 -malign-loops=2 -malign-jumps=2 -malign-functions=2
#define OLDXMENU_OPTIONS CFLAGS=-O2 EXTRA=insque.o
#define START_FILES pre-crt0.o /usr/lib/crt1.o /usr/lib/crti.o
#define LIBS_DEBUG		/* override in config.h to include -lg */
#define LIBS_TERMCAP -lncurses
#define LIBS_SYSTEM -lc /usr/lib/crtn.o

/* s-linux.h ends here */
