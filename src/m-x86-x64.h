/* m- file for x86_64.
   Copyright (C) 1987 Free Software Foundation, Inc.

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


/* The following three symbols give information on
 the size of various data types.  */

#define SHORTBITS 16		/* Number of bits in a short */

#define INTBITS 32		/* Number of bits in an int */

#define LONGBITS 64		/* Number of bits in a long */

/* Define LONG_LISP_OBJECT if you define LISP_OBJECT as long. */

#define LONG_LISP_OBJECT

/* Define the number of bits compose Lisp_Object. The default is 32. */

#define LISP_OBJECT_BITS 64

#define PNTR_COMPARISON_TYPE unsigned long

/*
 * Undefine some constants defined in s-*.h so that lisp.h
 * picks up appropriate one.
 */
#undef VALBITS
#undef GCTYPEBITS
#undef ULIMIT_BREAK_VALUE
#undef DATA_SEG_BITS
#undef SEGMENT_MASK

/* x86_64 is not big-endian: lowest numbered byte is least significant. */

/* #undef BIG_ENDIAN */

/* Define NO_ARG_ARRAY if you cannot take the address of the first of a
 * group of arguments and treat it as an array of the arguments.  */

#define NO_ARG_ARRAY

/* Define how to take a char and sign-extend into an int.
   On machines where char is signed, this is a no-op.  */

#define SIGN_EXTEND_CHAR(c) (c)

/* Use type int rather than a union, to represent Lisp_Object */

#define NO_UNION_TYPE

/* Define CANNOT_DUMP on machines where unexec does not work.
   Then the function dump-emacs will not be defined
   and temacs will do (load "loadup") automatically unless told otherwise.  */

/* #define CANNOT_DUMP */

/* Define VIRT_ADDR_VARIES if the virtual addresses of
   pure and impure space as loaded can vary, and even their
   relative order cannot be relied on.

   Otherwise Emacs assumes that text space precedes data space,
   numerically.  */

/* #define VIRT_ADDR_VARIES */

#define HAVE_ALLOCA

/* If compiling with GCC, let GCC implement alloca.  */
#if defined(__GNUC__) && !defined(alloca)
#define alloca(n) __builtin_alloca(n)
#endif
