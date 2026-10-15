/*
 * function: RESEARCH_GRAPH_CreateArrow
 * address: 0x021BFE8C
 * packet: pkt_ov217_021BFE8C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_GRAPH_GetClactUnit 0x021BF9F0 thumb ov217
 *   ARROW_Create 0x021C2070 thumb ov217
 */
#include "../include/Obj14747.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Params { u32 handles[3]; u16 a, b, c, d, e; };
extern u32 RESEARCH_GRAPH_GetClactUnit(void *, u32);
extern u32 ARROW_Create(u32, u32);
void RESEARCH_GRAPH_CreateArrow(char *p)
{
    struct Params args;
    args.handles[0] = RESEARCH_GRAPH_GetClactUnit(p, 0);
    args.handles[1] = RESEARCH_GRAPH_GetClactUnit(p, 1);
    args.handles[2] = RESEARCH_GRAPH_GetClactUnit(p, 2);
    args.a = 0;
    args.b = 0;
    args.c = 1;
    args.d = 2;
    args.e = 3;
    ((struct Obj14747 *)p)->f2D0 = ARROW_Create(((struct Obj14747 *)p)->f4, (u32)&args);
}
