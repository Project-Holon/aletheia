/*
 * function: RESEARCH_GRAPH_AdvanceWhileActive
 * address:  0x021BE36C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *   RESEARCH_GRAPH_GetCount  0x021BE468  thumb  ov217
 *
 * Calls RESEARCH_GRAPH_SetStateChanged() while RESEARCH_GRAPH_GetCount() is below the record's +0x28
 * count.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25897.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_GRAPH_SetStateChanged(void *p);
extern u32 RESEARCH_GRAPH_GetCount(void *p);
void RESEARCH_GRAPH_AdvanceWhileActive(u32 a0)
{
    if (RESEARCH_GRAPH_GetCount((void *)a0) < ((struct Obj25897 *)(((u8*)a0)))->f28) {
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
}
