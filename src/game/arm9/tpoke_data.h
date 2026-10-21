#ifndef GAME_ARM9_TPOKE_DATA_H
#define GAME_ARM9_TPOKE_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of tpoke_data.c, prototypes copied from their definitions. */

struct Container;

#include "../arm9/tpoke_data_types.h"
#include "../types.h"

Tpoke *TPOKE_DATA_Create(u16 heap);
void TPOKE_Delete(Tpoke *tpoke);
u32 TPOKE_DATA_GetRecordIndex(struct Container *c, u32 key, u32 type, u32 subtype);
int TPOKE_DATA_IsRecordKindTwo(u32 unused, struct Container *c, u32 type, u32 subtype, u16 e);
u32 TPOKE_DATA_FindEntryIndex(const struct Container *c, u32 key, u32 type, u32 subtype);
u32 TPOKE_DATA_GetEntryIndex(u8 *p, u32 key, u32 type, u32 subtype);
int TPOKE_DATA_GetRecordPtr(struct Container *c, int recordIndex);
u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);
u32 TPOKE_DATA_FindRecord(u32 key, u32 want, u16 heap);
void TPOKE_DATA_ReadRecordString(int key, int want, void *dest, u16 heap);
void TPOKE_DATA_ReadRecord(u32 memberIdx, void *dest);
void TPOKE_DATA_ReadParty(u32 memberIdx, void *dest);
u8 TPOKE_DATA_GetGenderValue(u32 idx);
u8 TPOKE_DATA_FindTrainerType(u32 key);
u8 TPOKE_DATA_GetTrainerKind(u32 key);
u32 TPOKE_DATA_GetTrainerGroup(u32 key);
/* END mkheaders: generated region */

#endif
