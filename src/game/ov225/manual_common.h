#ifndef GAME_OV225_MANUAL_COMMON_H
#define GAME_OV225_MANUAL_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_common.c, prototypes copied from their definitions. */

#include "../types.h"

void *MANUAL_COMMON_CreateData(void *owner,u16 heap);
void MANUAL_COMMON_DeleteData(char *data);
void MANUAL_COMMON_DrawData(char *data);
void MANUAL_COMMON_SetScreenId(char *data,unsigned id);
void MANUAL_COMMON_InitDisplay(void *unused);
void MANUAL_COMMON_DataNoop(void *unused);
/* END mkheaders: generated region */

#endif
