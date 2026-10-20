#ifndef GAME_ARM9_TR_TOOL_H
#define GAME_ARM9_TR_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of tr_tool.c, prototypes copied from their definitions. */

#include "../types.h"

void TR_TOOL_BuildParty(u32 trid, void *party, u16 heap);
void TR_TOOL_AdjustPersonality(u32 species, u32 form, int adjustFlags, u32 *personalityLow, u16 heapId);
void TR_TOOL_FinalizePartyMember(u32 trainerId, void *mon, u32 form, u32 abilityFlags);
/* END mkheaders: generated region */

#endif
