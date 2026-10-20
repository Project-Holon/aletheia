#ifndef GAME_SDK_STDARG_H
#define GAME_SDK_STDARG_H

/*
 * Variable argument lists.
 *
 * The MSL ARM form: va_list is a char pointer into the argument words that
 * the caller pushed. va_start rounds the address of the last named parameter
 * down to a word and steps over it. va_arg advances by the argument size
 * rounded up to whole words. This form relies on the ARM calling convention,
 * where the named parameters and the anonymous ones form one word array.
 * Other targets use the compiler's own <stdarg.h>.
 */
#ifdef __MWERKS__

typedef char *va_list;

#define __va_size(t) ((sizeof(t) + 3) & ~3u)
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))
#define va_end(v)

#else

#include <stdarg.h>

#endif

#endif
