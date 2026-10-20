#ifndef GAME_ARM9_OS_EXCEPTION_H
#define GAME_ARM9_OS_EXCEPTION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_exception.c, prototypes copied from their definitions. */

void OS_InitException(void);
void OSi_ExceptionHandler(void);
void OSi_GetAndDisplayContext(void);
void OSi_SetExContext(void);
void OSi_DisplayExContext(void);
/* END mkheaders: generated region */

#endif
