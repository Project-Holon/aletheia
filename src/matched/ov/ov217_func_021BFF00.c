/*
 * function: RESEARCH_GRAPH_CreatePercentages
 * address: 0x021BFF00
 * packet: pkt_ov217_021BFF00
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 * symbols:
 *   RESEARCH_GRAPH_GetClactUnit 0x021BF9F0 thumb ov217
 *   RESEARCH_GRAPH_GetSharedHandle 0x021BF9FC thumb ov217
 *   PERCENTAGE_Create 0x021C26E8 thumb ov217
 *   PERCENTAGE_SetVisible 0x021C2740 thumb ov217
 */
#include "../include/Obj25957.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Params { u32 handles[3]; u16 a, b, c; };
extern u32 RESEARCH_GRAPH_GetClactUnit(void *, u32);
extern u32 RESEARCH_GRAPH_GetSharedHandle(void *, u32);
extern u32 PERCENTAGE_Create(u32, u32, u32);
extern void PERCENTAGE_SetVisible(u32, u32);
void RESEARCH_GRAPH_CreatePercentages(char *p)
{
    struct Params args;
    int i;
    args.handles[0] = RESEARCH_GRAPH_GetClactUnit(p, 0);
    args.handles[1] = RESEARCH_GRAPH_GetClactUnit(p, 1);
    args.handles[2] = RESEARCH_GRAPH_GetClactUnit(p, 2);
    args.a = 0;
    args.b = 12;
    args.c = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(p + i * 4 + 0x2d4) = PERCENTAGE_Create(((struct Obj25957 *)p)->f4, (u32)&args, RESEARCH_GRAPH_GetSharedHandle(p, 3));
        PERCENTAGE_SetVisible(*(u32 *)(p + i * 4 + 0x2d4), 0);
    }
}
