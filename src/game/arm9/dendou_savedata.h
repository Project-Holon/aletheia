#ifndef GAME_ARM9_DENDOU_SAVEDATA_H
#define GAME_ARM9_DENDOU_SAVEDATA_H

/* Public functions of dendou_savedata.c, prototypes copied from their definitions. */

struct DendouRec;
struct Date;
struct PartyRingSave;
struct DendouEntry;
struct RecordTarget;
struct RecordDate;

#include "../types.h"

u32 DENDOU_SAVEDATA_GetSize(void);
u32 DENDOU_SAVEDATA_GetRecordSize(void);
void DENDOU_SAVEDATA_Clear(void *block);
void DENDOU_SAVEDATA_InitRecord(void *block);
void DENDOU_SAVEDATA_SetRecord(struct DendouRec *rec, void *party, struct Date *date, u32 heap);
void DENDOU_SAVEDATA_AppendRecord(struct PartyRingSave *obj, void *party, void *date, u32 heap);
int DENDOU_SAVEDATA_GetMemberCount(char *records);
void DENDOU_SAVEDATA_ExportMember(const struct DendouEntry *records, int index, struct RecordTarget *dst);
void DENDOU_SAVEDATA_GetRecordDate(const u8 *record, struct RecordDate *out);
u32 DENDOU_SAVEDATA_GetRecordCount(char *ring);
u32 DENDOU_SAVEDATA_GetHallNumber(char *ring, u32 count);
int DENDOU_SAVEDATA_GetRingMemberCount(char *o, int idx);
void DENDOU_SAVEDATA_ExportRingMember(void *ring, u32 index, void *recordIndex, void *target);
void DENDOU_SAVEDATA_GetRingRecordDate(u8 *ring, int index, void *out);

#endif
