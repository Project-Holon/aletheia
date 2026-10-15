/*
 * function: RESEARCH_LIST_ScrollSelectionIntoView
 * address: 0x021BBA30
 * packet: pkt_ov217_021BBA30
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BC400 forwards entry r0 into BC3F8, so retain supplied argument despite legacy void. BC3EC overwrites r1 with 24 and tail-calls signed division; legacy trailing a1 neither read nor forwarded.
 * symbols:
 *   RESEARCH_LIST_GetScrollMin 0x021BC3D4 thumb ov217
 *   RESEARCH_LIST_GetScrollMax 0x021BC3E0 thumb ov217
 *   RESEARCH_LIST_EntryIndexToY 0x021BC3F8 thumb ov217
 *   RESEARCH_LIST_EntryIndexToYBottom 0x021BC400 thumb ov217
 *   RESEARCH_LIST_DivideByEntryHeight 0x021BC3EC thumb ov217
 *   RESEARCH_LIST_SelectEntry 0x021BBAA4 thumb ov217
 *   RESEARCH_LIST_SetCursorSlot 0x021BBD38 thumb ov217
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
extern unsigned int RESEARCH_LIST_GetScrollMin(void);
extern unsigned RESEARCH_LIST_GetScrollMax(void);
extern unsigned RESEARCH_LIST_EntryIndexToY(unsigned);
extern unsigned RESEARCH_LIST_EntryIndexToYBottom(unsigned);
extern int RESEARCH_LIST_DivideByEntryHeight(unsigned);
typedef unsigned int   u32;
extern u32 RESEARCH_LIST_SelectEntry(u32 a0, u8 a1);
extern void RESEARCH_LIST_SetCursorSlot(void *, u8);
void RESEARCH_LIST_ScrollSelectionIntoView(u8 *p)
{
    int low, high, left, right;
    u8 index;
    low = RESEARCH_LIST_GetScrollMin();
    high = RESEARCH_LIST_GetScrollMax();
    left = RESEARCH_LIST_EntryIndexToY(p[0x32]);
    right = RESEARCH_LIST_EntryIndexToYBottom(p[0x32]);
    if (right <= low) {
        index = RESEARCH_LIST_DivideByEntryHeight(right + 1);
        if (((struct Obj00025 *)p)->f160) RESEARCH_LIST_SelectEntry((unsigned)p, index);
        else RESEARCH_LIST_SetCursorSlot(p, index);
    }
    if (high <= left) {
        index = RESEARCH_LIST_DivideByEntryHeight(left - 1);
        if (((struct Obj00025 *)p)->f160) RESEARCH_LIST_SelectEntry((unsigned)p, index);
        else RESEARCH_LIST_SetCursorSlot(p, index);
    }
}
