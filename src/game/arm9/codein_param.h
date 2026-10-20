#ifndef GAME_ARM9_CODEIN_PARAM_H
#define GAME_ARM9_CODEIN_PARAM_H

struct CodeinParam *CODEIN_PARAM_Create(u32 heapId, u32 mode, u32 initialPage, u32 maxLength, u32 *values);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of codein_param.c, prototypes copied from their definitions. */

struct CodeinParam;

#include "../types.h"

struct CodeinParam *CODEIN_PARAM_Create(u32 heapId, u32 mode, u32 initialPage, u32 maxLength, u32 *values);
void CODEIN_PARAM_Delete(struct CodeinParam *param);
/* END mkheaders: generated region */

#endif
