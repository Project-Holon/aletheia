#ifndef GAME_ARM9_OS_CONTEXT_H
#define GAME_ARM9_OS_CONTEXT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_context.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../types.h"

void OS_InitContext(OSContext *context, u32 newpc, u32 newsp);
BOOL OS_SaveContext(OSContext *context);
void OS_LoadContext(OSContext *context);
/* END mkheaders: generated region */

#endif
