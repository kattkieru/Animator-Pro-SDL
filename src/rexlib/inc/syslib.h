#ifndef SYSLIB_H
#define SYSLIB_H

#ifndef STDTYPES_H
	#include "stdtypes.h"
#endif

#ifndef REXLIB_H
	#include "rexlib.h"
#endif

#ifndef FILEMODE_H
	#include "filemode.h"
#endif

struct _syslib_error_check_ {
	char xx[sizeof(int) == 4]; /* we use 4 byte 32 bit ints */
};

/* items found in library _a_a_syslib not declared in included headers */

// No longer needed in modern times?
// void *malloc(int);		/* ANSI uninitialized memory */
// void *zalloc(int);		/* allocate cleared memory (non - ansi) */
// void free(void *pt);	 /* free what above allocated */
// void *memset(void *s,int c,unsigned length);	/* ANSI memset function */
// void *memcpy(void *dst,const void *src,unsigned length); /* ANSI memcpy function */
// int memcmp(void *s1,void *s2,int length); /* ANSI memcmp function */
// char *strcpy(char *d, const char *s);		/* ANSI string copy */
// int strlen(char *s);				/* ANSI strlen */
// int strcmp(char *s1,char *s2);		/* ANSI string compare */

/* Modern host-side implementations of legacy PJ unbuffered file I/O */
Jfile pj_open(char *path, int mode);
Jfile pj_create(char *path, int mode);
Errcode pj_close(Jfile f);
Errcode pj_closez(Jfile *jf);
long pj_read(Jfile f, void *buf, long size);
long pj_write(Jfile f, void *buf, long size);
long pj_seek(Jfile f, long offset, int mode);
long pj_tell(Jfile f);
Errcode pj_readoset(Jfile f, void *buf, long offset, size_t size);

#endif /* SYSLIB_H */
