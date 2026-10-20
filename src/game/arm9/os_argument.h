#ifndef GAME_ARM9_OS_ARGUMENT_H
#define GAME_ARM9_OS_ARGUMENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_argument.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../types.h"

void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize);
int OS_EncodeDeliverArg(void);
int OS_DecodeDeliverArg(void);
void OS_SetDeliverArgStateInvalid(void);
u64 OS_GetTitleIdFromDeliverArg(void);
BOOL OS_IsValidDeliverArg(void);
/* END mkheaders: generated region */

#endif
