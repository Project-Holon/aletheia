#ifndef GAME_ARM9_TR_TOOL_H
#define GAME_ARM9_TR_TOOL_H

#include "../types.h"

typedef struct TrTrainerInfo {
    u32 trainerId;    /* +0x00 the trainer id this record was loaded for */
    u32 genderClass;  /* +0x04 copied from the record's genderClass byte */
    u32 data0C;       /* +0x08 copied from the record's data0C word */
    u32 data04[2];    /* +0x0C the record's 8 data04 bytes, copied verbatim */
    u32 name;         /* +0x14 destination buffer for the trainer name string */
    u32 sentence[2];  /* +0x18 PmsData easy-chat sentence (2 words) */
    u32 sentence2[2]; /* +0x20 PmsData easy-chat sentence (2 words) */
} TrTrainerInfo;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of tr_tool.c, prototypes copied from their definitions. */

#include "../types.h"

void TR_TOOL_LoadTrainerInfo(u32 id, TrTrainerInfo *out, u16 heap);
void TR_TOOL_BuildParty(u32 trid, void *party, u16 heap);
void TR_TOOL_AdjustPersonality(u32 species, u32 form, int adjustFlags, u32 *personalityLow, u16 heapId);
void TR_TOOL_FinalizePartyMember(u32 trainerId, void *mon, u32 form, u32 abilityFlags);
/* END mkheaders: generated region */

#endif
