#ifndef GAME_OV132_STA_SLOT_H
#define GAME_OV132_STA_SLOT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_slot.c, prototypes copied from their definitions. */

struct StaSlotOwner;
typedef struct StaSlotOwner StaSlotOwner;

#include "../types.h"

u32 STA_SLOT_GetSub(char *p, u32 index, u32 subindex);
void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value);
unsigned char STA_SLOT_GetStateByKey(unsigned char *p, unsigned char key);
void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key);
int STA_SLOT_GetCurrentKey(char *p);
void STA_SLOT_ClearCurrent(unsigned char *p);
void STA_SLOT_PushRecord(StaSlotOwner *p, u32 player, u32 action, u32 result);
unsigned char *STA_SLOT_GetRecordTable(void *unused);
void STA_SLOT_Noop(int buffer, int size, int kind);
/* END mkheaders: generated region */

#endif
