#ifndef GAME_ARM9_GIMMICK_H
#define GAME_ARM9_GIMMICK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gimmick.c, prototypes copied from their definitions. */

struct GimmickWork;
struct SaveControl;

#include "../types.h"

u32 GIMMICK_WORK_GetSize(void);
void GIMMICK_WORK_Init(struct GimmickWork *gimmick);
void GIMMICK_WORK_Reset(struct GimmickWork *gimmick);
s32 *GIMMICK_WORK_InitWithId(struct GimmickWork *gimmick, s32 id);
s32 *GIMMICK_WORK_GetWork(struct GimmickWork *gimmick, u32 id);
u8 *GIMMICK_WORK_GetSubWork(struct GimmickWork *gimmick, u32 id);
s32 GIMMICK_WORK_GetId(struct GimmickWork *gimmick);
void GIMMICK_WORK_Save(const struct GimmickWork *src, struct SaveControl *save);
void GIMMICK_WORK_Load(struct SaveControl *save, struct GimmickWork *dest);
/* END mkheaders: generated region */

#endif
