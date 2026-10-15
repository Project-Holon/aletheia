/*
 * function: RESEARCH_LIST_ComputeReturnScroll
 * address: 0x021BBB60
 * packet: pkt_ov217_021BBB60
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BC40C receives original visible r0=context even though its body uses only globals; preserve that input.
 * symbols:
 *   RESEARCH_LIST_GetScrollRangeMax 0x021BC41C thumb ov217
 *   RESEARCH_LIST_GetScrollRange 0x021BC40C thumb ov217
 *   RESEARCH_LIST_GetScrollMin 0x021BC3D4 thumb ov217
 *   RESEARCH_LIST_GetScrollMax 0x021BC3E0 thumb ov217
 *   RESEARCH_LIST_StartScrollAnim 0x021BC2CC thumb ov217
 */
#include "../include/Obj01084.h"
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_GetScrollRangeMax(void *);
extern int RESEARCH_LIST_GetScrollRange(void *p);
extern unsigned RESEARCH_LIST_GetScrollMin(void);
extern unsigned RESEARCH_LIST_GetScrollMax(void);
extern void RESEARCH_LIST_StartScrollAnim(void *, unsigned, unsigned, unsigned);
void RESEARCH_LIST_ComputeReturnScroll(u8 *p)
{
    int start, end, step, low, high, low2, high2;
    start = ((struct Obj01084 *)p)->f34;
    end = start;
    if ((int)RESEARCH_LIST_GetScrollRangeMax(p) < start) end = RESEARCH_LIST_GetScrollRange(p) + 24;
    else if (start < 0) end = 144;
    low = RESEARCH_LIST_GetScrollMin();
    high = RESEARCH_LIST_GetScrollMax();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 3;
    low2 = RESEARCH_LIST_GetScrollMin();
    high2 = RESEARCH_LIST_GetScrollMax();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 1;
    RESEARCH_LIST_StartScrollAnim(p, start, end, step);
}
