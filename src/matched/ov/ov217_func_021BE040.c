/*
 * function: RESEARCH_GRAPH_StepAnimation
 * address: 0x021BE040
 * packet: pkt_ov217_021BE040
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_GRAPH_GetSubState 0x021BE4DC thumb ov217
 *   RESEARCH_GRAPH_UpdatePercentages 0x021BEF30 thumb ov217
 *   RESEARCH_GRAPH_IncSubState 0x021BE4E0 thumb ov217
 *   RESEARCH_GRAPH_ShowPercent 0x021BEFC0 thumb ov217
 *   RESEARCH_GRAPH_SetStateChanged 0x021BE448 thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj06712.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 RESEARCH_GRAPH_GetSubState(void *);
extern void RESEARCH_GRAPH_UpdatePercentages(char *);
extern void RESEARCH_GRAPH_IncSubState(void *);
extern void RESEARCH_GRAPH_ShowPercent(u8 *, u32);
extern void RESEARCH_GRAPH_SetStateChanged(void *);
void RESEARCH_GRAPH_StepAnimation(u8 *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        RESEARCH_GRAPH_UpdatePercentages((char *)p);
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (((struct Obj06712 *)p)->f28 % 10u == 0) {
            u8 index = p[765];
            p[765] = index + 1;
            RESEARCH_GRAPH_ShowPercent(p, index);
        }
        if (p[764] <= p[765]) RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}
