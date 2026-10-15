/*
 * function: RESEARCH_GRAPH_UpdateIntro
 * address:  0x021BD868
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_SetStateChanged 0x021BE448 thumb ov217
 *   RESEARCH_GRAPH_GetSubState 0x021BE4DC thumb ov217
 *   RESEARCH_GRAPH_IncSubState 0x021BE4E0 thumb ov217
 *   RESEARCH_GRAPH_OpenComm 0x021C0918 thumb ov217
 *   RESEARCH_GRAPH_GetCommKindOrStart 0x021C093C thumb ov217
 */

typedef unsigned int u32;

#pragma thumb on
typedef unsigned char  u8;
extern void RESEARCH_GRAPH_SetStateChanged(void *p);
extern u32 RESEARCH_GRAPH_GetSubState(void *p);
extern void RESEARCH_GRAPH_IncSubState(void *p);
extern void RESEARCH_GRAPH_OpenComm(u8 *a0);
extern int RESEARCH_GRAPH_GetCommKindOrStart(u8 *a0);

void RESEARCH_GRAPH_UpdateIntro(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
        RESEARCH_GRAPH_OpenComm((u8 *)a0);
        RESEARCH_GRAPH_IncSubState((void *)a0);
        break;
    case 1:
        if (RESEARCH_GRAPH_GetCommKindOrStart((u8 *)a0) != 0) {
            RESEARCH_GRAPH_SetStateChanged((void *)a0);
        }
        break;
    }
}
