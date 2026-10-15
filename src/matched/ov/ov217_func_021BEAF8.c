/*
 * function: RESEARCH_GRAPH_SyncArrow
 * address: 0x021BEAF8
 * packet: pkt_ov217_021BEAF8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing: two alignment bytes at 021BEB3E.
 * Prototype: caller reads r0 from RESEARCH_GRAPH_IsSlotPaletteAnimeRunning despite legacy void declaration.
 * symbols:
 *   RESEARCH_GRAPH_GetGroupValue 0x021BF810 thumb ov217
 *   RESEARCH_GRAPH_IsSlotPaletteAnimeRunning 0x021BF5D0 thumb ov217
 *   RESEARCH_GRAPH_SetNormalB 0x021BEBE4 thumb ov217
 *   RESEARCH_GRAPH_SetNormalA 0x021BEBC0 thumb ov217
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(u8 *, u32);
extern u32 RESEARCH_GRAPH_SetNormalB(u32);
extern u32 RESEARCH_GRAPH_SetNormalA(u32);
void RESEARCH_GRAPH_SyncArrow(u8 *p)
{
    if (((struct Obj00021 *)p)->f3C8 == 1 || ((struct Obj00021 *)p)->f3D0 == 1 || RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(p, 5) == 0) RESEARCH_GRAPH_SetNormalB((u32)p);
    } else {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(p, 5) == 1) RESEARCH_GRAPH_SetNormalA((u32)p);
    }
}
