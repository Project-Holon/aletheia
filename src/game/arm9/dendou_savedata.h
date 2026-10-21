#ifndef GAME_ARM9_DENDOU_SAVEDATA_H
#define GAME_ARM9_DENDOU_SAVEDATA_H

#include "../types.h"

/* An exported party record: two string buffers and the copied fields. */
struct RecordTarget {
    void *nicknameStr;  /* +0x00 */
    void *otNameStr;    /* +0x04 */
    u32   pid;          /* +0x08 */
    u32   experience;   /* +0x0c */
    u16   species;      /* +0x10 */
    u8    level;        /* +0x12 */
    u8    form : 6;     /* +0x13 */
    u8    gender : 2;
    u16   traits[4];    /* +0x14 */
};

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
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
/* END mkheaders: generated region */

#endif
