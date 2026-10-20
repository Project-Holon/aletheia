#ifndef GAME_ARM9_MSL_CONSOLE_IO_H
#define GAME_ARM9_MSL_CONSOLE_IO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_console_io.c, prototypes copied from their definitions. */

struct DestructorChain;

#include "../types.h"

void MSL_CONSOLE_IO_NoopFinalizer(void);
int MSL_CONSOLE_IO_RegisterDestructor(int destructor);
void MSL_CONSOLE_IO_WriteChar(void *string);
void MSL_CONSOLE_IO_WriteString(void *string);
int MSL_CONSOLE_IO_ReadChar(void);
u32 MSL_CONSOLE_IO_ReadConsole(u32 handle, char *dest, u32 *count);
int MSL_CONSOLE_IO_WriteConsole(int handle, u8 *buffer, u32 *count);
int MSL_CONSOLE_IO_CloseConsole(int handle);
void MSL_CONSOLE_IO_RunInitHandlers(void);
void __register_global_object(u32 object, u32 destructor, struct DestructorChain *chain);
/* END mkheaders: generated region */

#endif
