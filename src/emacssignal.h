#ifdef POSIX_SIGNALS

#define SIGMASKTYPE sigset_t
#define SIGEMPTYMASK (signal_empty_mask)
#define SIGFULLMASK (signal_full_mask)
extern sigset_t signal_empty_mask, signal_full_mask;

/* POSIX pretty much destroys any possibility of writing sigmask as a
   macro in standard C.  We always define our own version because the
   predefined macro in Glibc 2.1 is only provided for compatility for old
   programs that use int as signal mask type.  */
#undef sigmask
#ifdef __GNUC__
#define sigmask(SIG)				\
  ({						\
    sigset_t _mask;				\
    sigemptyset (&_mask);			\
    sigaddset (&_mask, SIG);			\
    _mask;					\
  })
#else /* ! defined (__GNUC__) */
extern sigset_t sys_sigmask ();
#define sigmask(SIG) (sys_sigmask(SIG))
#endif /* ! defined (__GNUC__) */

#undef sigpause
#define sigpause(MASK)   sigsuspend(&(MASK))
#define sigblock(SIG)    sys_sigblock(SIG)
#define sigunblock(SIG)  sys_sigunblock(SIG)
#ifndef sigsetmask
#define sigsetmask(SIG)  sys_sigsetmask(SIG)
#endif
#define sighold(SIG)     ONLY_USED_IN_BSD_4_1
#define sigrelse(SIG)    ONLY_USED_IN_BSD_4_1

typedef void (*signal_handler_t) ();
signal_handler_t sys_signal (int signal_number, signal_handler_t action);
int sys_sigpause (sigset_t new_mask);
sigset_t sys_sigblock (sigset_t new_mask);
sigset_t sys_sigunblock (sigset_t new_mask);
sigset_t sys_sigsetmask (sigset_t new_mask);

#define sys_sigdel(MASK,SIG) sigdelset(&MASK,SIG)
#endif /* POSIX_SIGNALS */

#ifndef SIGMASKTYPE
#define SIGMASKTYPE int
#endif

#ifndef SIGEMPTYMASK
#define SIGEMPTYMASK 0
#endif

#ifndef SIGFULLMASK
#define SIGFULLMASK 0xffffffff
#endif

#ifndef sigmask
#define sigmask(no) (1L << ((no) - 1))
#endif

#ifndef sigunblock
#define sigunblock(SIG) \
{ SIGMASKTYPE omask = sigblock (SIGFULLMASK); sigsetmask (omask & ~SIG); }
#endif

#ifndef sys_sigdel
#define sys_sigdel(MASK,SIG) MASK &= ~(1 << SIG)
#endif
