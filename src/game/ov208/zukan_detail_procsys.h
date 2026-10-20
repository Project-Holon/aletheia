#ifndef GAME_OV208_ZUKAN_DETAIL_PROCSYS_H
#define GAME_OV208_ZUKAN_DETAIL_PROCSYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_procsys.c, prototypes copied from their definitions. */

struct Ov208Fsm;

#include "../types.h"

struct Ov208Fsm *ZUKAN_DETAIL_PROCSYS_AllocNode(void *owner, int val, u32 heap);
void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p);
int ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(struct Ov208Fsm *p,int ctx);
void ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(char *p, int ctx, int buttonId);
void ZUKAN_DETAIL_PROCSYS_CallOwnerHook(char *p, int ctx);
void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Fsm *p, u32 size, u32 heap);
void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *p);
/* END mkheaders: generated region */

#endif
