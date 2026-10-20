#ifndef GAME_ARM9_MON_SNAPSHOT_SAVEDATA_H
#define GAME_ARM9_MON_SNAPSHOT_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mon_snapshot_savedata.c, prototypes copied from their definitions. */

struct BoxMonSlot;

#include "../types.h"

u32 MON_SNAPSHOT_GetSize(void);
void MON_SNAPSHOT_Clear(void *dest);
u32 MON_SNAPSHOT_IsFilled(const void *slots, u32 index);
u32 MON_SNAPSHOT_GetLevel(const void *slots, u32 index);
u32 MON_SNAPSHOT_HasAbility(const void *slots, u32 index);
u8 MON_SNAPSHOT_GetAbility(const void *slots, u32 index);
u32 MON_SNAPSHOT_GetSpeciesForSlot(const void *unused, u32 a, u32 b);
u32 MON_SNAPSHOT_GetPersonalRnd(const void *slots, u32 index);
void *MON_SNAPSHOT_GetNickname(void *slots, u32 index);
u32 MON_SNAPSHOT_GetOtId(const void *slots, u32 index);
void MON_SNAPSHOT_Fill(struct BoxMonSlot *slots, int index, void *mon);
/* END mkheaders: generated region */

#endif
