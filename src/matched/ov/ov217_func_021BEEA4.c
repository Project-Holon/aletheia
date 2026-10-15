/*
 * function: RESEARCH_GRAPH_LayoutArrow
 * address: 0x021BEEA4
 * packet: pkt_ov217_021BEEA4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * C11DC forwards r0/r1 through C1AC0; caller's narrowed index remains in its prototype.
 * C20CC overwrites incoming r1 with 1 before forwarding to C218C; legacy unused trailing parameter omitted.
 * symbols:
 *   ARROW_Reset 0x021C20D8 thumb ov217
 *   RESEARCH_GRAPH_GetGroupValue 0x021BF810 thumb ov217
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   RESEARCH_GRAPH_GetEntryKey 0x021BF7F4 thumb ov217
 *   CircleGraph_GetPercentByKey 0x021C11DC thumb ov217
 *   CircleGraph_GetLabelPositionByKey 0x021C11FC thumb ov217
 *   ARROW_Layout 0x021C20B4 thumb ov217
 *   ARROW_Start 0x021C20CC thumb ov217
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef signed int s32;
extern unsigned ARROW_Reset(unsigned);
typedef unsigned int u32;
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern unsigned RESEARCH_GRAPH_GetEntryKey(void *);
extern u8 CircleGraph_GetPercentByKey(u8 *p, u8 key);
extern void CircleGraph_GetLabelPositionByKey(u8 *h, u8 key, s32 *px, s32 *py);
extern void ARROW_Layout(int a0, int a1, int a2, int a3, int a4);
extern void ARROW_Start(unsigned);
void RESEARCH_GRAPH_LayoutArrow(char *p)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    ARROW_Reset(*(unsigned *)&((struct Obj00021 *)p)->f2D0);
    if (((struct Obj00021 *)p)->f3D0==1) return;
    if (((struct Obj00021 *)p)->f3C8==0) return;
    if (RESEARCH_GRAPH_GetGroupValue(p)==0) return;
    object=RESEARCH_GRAPH_GetLeftCircle(p);
    index=RESEARCH_GRAPH_GetEntryKey(p);
    if (CircleGraph_GetPercentByKey(object,index)==0) return;
    if (((struct Obj00021 *)p)->f3C8!=0) {
        object=RESEARCH_GRAPH_GetLeftCircle(p);
        index=RESEARCH_GRAPH_GetEntryKey(p);
        CircleGraph_GetLabelPositionByKey(object,index,&x,&y);

        ARROW_Layout(*(unsigned *)&((struct Obj00021 *)p)->f2D0,104,34,x,y);
        ARROW_Start(*(unsigned *)&((struct Obj00021 *)p)->f2D0);
    }
}
