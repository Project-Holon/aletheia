/*
 * function: RESEARCH_TOP_CheckQuestionnaire
 * address:  0x021BA1D4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_PopQuestionnaireUpdated  0x020270E0  thumb
 *   RESEARCH_TOP_ShowEntryActor  0x021BA328  thumb  ov217
 *
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);
extern u32 RESEARCH_TOP_ShowEntryActor(u32 a0);
void RESEARCH_TOP_CheckQuestionnaire(u32 a0)
{
    if (((struct Obj00511 *)((u8*)a0))->f84 == 0) {
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
    ((struct Obj00511 *)((u8*)a0))->f84 = 1;
    RESEARCH_TOP_ShowEntryActor(a0);
    }
    }
}
