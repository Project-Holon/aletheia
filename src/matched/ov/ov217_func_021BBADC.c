/*
 * function: RESEARCH_LIST_ComputeOpenScroll
 * address: 0x021BBADC
 * packet: pkt_ov217_021BBADC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BBB5E..021BBB60 is two zero bytes of alignment padding.
 * arity: BC400 forwards entry r0 to BC3F8 despite its legacy void parameter list; retain the visible byte argument.
 * symbols:
 *   RESEARCH_LIST_EntryIndexToYBottom 0x021BC400 thumb ov217
 *   RESEARCH_LIST_EntryIndexToY 0x021BC3F8 thumb ov217
 *   RESEARCH_LIST_GetScrollMin 0x021BC3D4 thumb ov217
 *   RESEARCH_LIST_GetScrollMax 0x021BC3E0 thumb ov217
 *   RESEARCH_LIST_StartScrollAnim 0x021BC2CC thumb ov217
 */
#include "../include/Obj01084.h"
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_EntryIndexToYBottom(unsigned);
extern unsigned RESEARCH_LIST_EntryIndexToY(unsigned);
extern unsigned RESEARCH_LIST_GetScrollMin(void);
extern unsigned RESEARCH_LIST_GetScrollMax(void);
extern void RESEARCH_LIST_StartScrollAnim(void *, unsigned, unsigned, unsigned);
void RESEARCH_LIST_ComputeOpenScroll(u8 *p)
{
    int start, end, low, high, step, low2, high2;
    start = ((struct Obj01084 *)p)->f34;
    if (p[0x32] < p[0x33]) end = RESEARCH_LIST_EntryIndexToYBottom(p[0x33]) + 1;
    else end = RESEARCH_LIST_EntryIndexToY(p[0x33]);
    low = RESEARCH_LIST_GetScrollMin();
    high = RESEARCH_LIST_GetScrollMax();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 4;
    low2 = RESEARCH_LIST_GetScrollMin();
    high2 = RESEARCH_LIST_GetScrollMax();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 0;
    RESEARCH_LIST_StartScrollAnim(p, start, end, step);
}
