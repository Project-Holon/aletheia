#ifndef GAME_ARM9_OS_PRINTF_H
#define GAME_ARM9_OS_PRINTF_H

/* Public functions of os_printf.c, prototypes copied from their definitions. */

int OS_SPrintf(char *dst, const char *fmt, ...);
int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
int OS_VSNPrintf(char *dst, unsigned int len, const char *format, void *vlist);

#endif
