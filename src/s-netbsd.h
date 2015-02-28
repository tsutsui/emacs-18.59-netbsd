/* Definitions file for GNU emacs running on NetBSD.  */

#include "s-bsd4-4.h"

/*
 *     Define symbols to identify the version of Unix this is.
 *     BSD and BSD4_3 are defined in s-bsd4-3.h.  There are some
 *     differences between 386BSD and BSD 4.3 so we need an extra
 *     symbol to identify it (the J stands for Jolitz).
 */

#undef SYSTEM_TYPE
#define SYSTEM_TYPE "netbsd"

#undef KERNEL_FILE
#define KERNEL_FILE "/netbsd"

#define INTERRUPT_INPUT
#define SIGNALS_VIA_CHARACTERS

/* NetBSD uses GNU C.  */

#define C_COMPILER gcc

/* NetBSD stores the termcap database in /usr/share/misc rather than
   /etc. We use the system termcap library to avoid putting a #ifdef
   in termcap.c or forcing the user to use the TERMCAP environment
   variable.  */

#define LIBS_TERMCAP -ltermcap

/* NetBSD is nominally a POSIX.1 OS and has setsid.  */

#define HAVE_SETSID
#define HAVE_CLOCK
#define HAVE_PTYS

#define NEED_TERMIOS
#define HAVE_TERMIOS
//#define HAVE_TCATTR

#define HAVE_TIMEVAL
#define HAVE_SELECT
#define HAVE_SOCKETS

#define HAVE_DUP2
#define HAVE_GETTIMEOFDAY
#define HAVE_RENAME
#define HAVE_RANDOM
#define HAVE_CLOSEDIR
#define HAVE_GETPAGESIZE
#define HAVE_VFORK
#define HAVE_SYS_SIGLIST
#define SYS_SIGLIST_DECLARED
#define HAVE_GETWD
#define HAVE_SYS_WAIT_H

#define SYSV_STREAMS

#define POSIX
#define POSIX_SIGNALS
#define TERMINFO
#define BSTRING

#define UNEXEC unexelf.o
#define UNEXEC_USE_MAP_PRIVATE

#define HAVE_TEXT_START
#define START_FILES pre-crt0.o /usr/lib/crt0.o /usr/lib/crti.o /usr/lib/crtbegin.o
#define LIBS_DEBUG
#define LIBS_SYSTEM -lgcc -lc -lgcc /usr/lib/crtend.o /usr/lib/crtn.o

#define LIB_X11_LIB -L/usr/X11R7/lib -Wl,-R/usr/X11R7/lib -lX11

/* For mem-limits.h.  */
#define BSD4_2

/* expand max filesize to 32 Meg */
#define VALBITS 26
#define GCTYPEBITS 5

/* Special hacks needed to make Emacs run on this system.  */
#ifdef emacs
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#endif

#undef LD_SWITCH_SYSTEM
#define LD_SWITCH_SYSTEM -L/usr/lib -L/usr/X11R7/lib -Wl,-R/usr/X11R7/lib
#define C_SWITCH_SYSTEM -I/usr/X11R7/include
#define C_DEBUG_SWITCH -O -g
#define C_OPTIMIZE_SWITCH -Wall -g -O -fno-strict-aliasing
