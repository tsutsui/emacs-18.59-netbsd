CFLAGS= -g
# For Xenix.  Needed for movemail
#  LOADLIBES= -lx
# For Mips.  Needed for who knows what.
#  CFLAGS = -g -systype bsd43

EXECUTABLES = test-distrib etags ctags wakeup make-docfile \
   digest-doc sorted-doc movemail cvtmail fakemail yow env \
   server emacsclient

all: ${EXECUTABLES}

clean:
	-rm -f ${EXECUTABLES} core

distclean:
	-rm -f ${EXECUTABLES} *~ \#* DOC* core

# This justs verifies that the non-ASCII characters
# in the file `testfile' have no been clobbered by
# whatever means were used to copy and distribute Emacs.
# If they were clobbered, all the .elc files were clobbered too.
test-distrib: test-distrib.c
	$(CC) -o test-distrib test-distrib.c
	./test-distrib

etags: etags.c
	$(CC) -o etags ${CFLAGS} ${LDFLAGS} -DETAGS etags.c $(LOADLIBES)

ctags: etags.c
	$(CC) -o ctags ${CFLAGS} ${LDFLAGS} -DCTAGS etags.c $(LOADLIBES)

wakeup: wakeup.c
	$(CC) -o wakeup ${CFLAGS} ${LDFLAGS} wakeup.c $(LOADLIBES)

make-docfile: make-docfile.c
	$(CC) -o make-docfile ${CFLAGS} ${LDFLAGS} make-docfile.c $(LOADLIBES)

digest-doc: digest-doc.c
	$(CC) -o digest-doc ${CFLAGS} ${LDFLAGS} digest-doc.c $(LOADLIBES)

sorted-doc: sorted-doc.c
	$(CC) -o sorted-doc ${CFLAGS} ${LDFLAGS} sorted-doc.c $(LOADLIBES)

#
movemail: movemail.c ../src/config.h
	$(CC) -o movemail ${CFLAGS} ${LDFLAGS} movemail.c $(LOADLIBES)

cvtmail: cvtmail.c
	$(CC) -o cvtmail ${CFLAGS} ${LDFLAGS} cvtmail.c $(LOADLIBES)

fakemail: fakemail.c ../src/config.h
	$(CC) -o fakemail ${CFLAGS} ${LDFLAGS} fakemail.c $(LOADLIBES)

yow: yow.c ../src/paths.h
	$(CC) -o yow ${CFLAGS} ${LDFLAGS} yow.c $(LOADLIBES)

# this is silly -- just use emacs to edit this file!
# (in any case this program doesn't preserve alphabetical ordering,
#  which is why I'm removing it)
#addyow: addyow.c
#	$(CC) -o addyow ${CFLAGS} addyow.c

env: env.c ../src/config.h
	$(CC) -o env -DEMACS ${CFLAGS} ${LDFLAGS} env.c $(LOADLIBES)

server: server.c ../src/config.h
	$(CC) -o server ${CFLAGS} ${LDFLAGS} server.c $(LOADLIBES)

emacsclient: emacsclient.c ../src/config.h
	$(CC) -o emacsclient ${CFLAGS} ${LDFLAGS} emacsclient.c $(LOADLIBES)

# This one is NOT included in EXECUTABLES.
# See ../src/ymakefile.
emacstool: emacstool.c
	$(CC) -o emacstool ${CFLAGS} ${LDFLAGS} emacstool.c -lsuntool -lsunwindow -lpixrect $(LOADLIBES)

nemacstool: emacstool.c
	$(CC) -o nemacstool ${CFLAGS} ${LDFLAGS} -DJLE emacstool.c -lsuntool -lmle -lsunwindow -lpixrect $(LOADLIBES)	# For SUN Japanese Language Environment

xvetool: emacstool.c
	$(CC) -o xvetool ${CFLAGS} ${LDFLAGS} -DXVIEW         emacstool.c -lxview -lolgx -lX -I$(OPENWINHOME)/include -L$(OPENWINHOME)/lib $(LOADLIBES)

xveterm: emacstool.c
	$(CC) -o xveterm ${CFLAGS} ${LDFLAGS} -DXVIEW -DTTERM emacstool.c -lxview -lolgx -lX -I$(OPENWINHOME)/include -L$(OPENWINHOME)/lib $(LOADLIBES)


