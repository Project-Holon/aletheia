/*
 * function: RESEARCH_GRAPH_CheckQuestionnaireUpdated
 * address:  0x021BF6D4
 * packet:   pkt_ov217_021BF6D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_BEACON_PopQuestionnaireUpdated 0x020270E0 thumb
 *   RESEARCH_GRAPH_GetGroupTotalA 0x021BF834 thumb ov217
 *   RESEARCH_GRAPH_GetSaveBits 0x021BF9CC thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25931.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);
extern u32 RESEARCH_GRAPH_GetGroupTotalA(void *p);
extern u16 RESEARCH_GRAPH_GetSaveBits(u32 a0);
void RESEARCH_GRAPH_CheckQuestionnaireUpdated(char *p)
{
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
        u16 a = RESEARCH_GRAPH_GetGroupTotalA(p);
        if (a != (u16)(u32)RESEARCH_GRAPH_GetSaveBits((u32)p)) {
            ((struct Obj25931 *)p)->f3D8 = 1;
        }
    }
}
