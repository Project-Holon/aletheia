/*
 * function: RESEARCH_GRAPH_EnterFadeOut
 * address:  0x021BE0D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *   RESEARCH_GRAPH_GetSubState  0x021BE4DC  thumb  ov217
 *   RESEARCH_GRAPH_IncSubState  0x021BE4E0  thumb  ov217
 *   RESEARCH_GRAPH_SyncArrow  0x021BEAF8  thumb  ov217
 *   RESEARCH_GRAPH_RequestFadeOut  0x021BF658  thumb  ov217
 *   RESEARCH_GRAPH_IsFadeDone  0x021BF6A4  thumb  ov217
 *
 * Sub-state entry for mode 0 and mode 1, picked by RESEARCH_GRAPH_GetSubState().
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_GRAPH_SetStateChanged(void *p);
extern u32 RESEARCH_GRAPH_GetSubState(void *p);
extern void RESEARCH_GRAPH_IncSubState(void *p);
extern void RESEARCH_GRAPH_SyncArrow(u8 *p);
extern void RESEARCH_GRAPH_RequestFadeOut(char *p);
extern u32 RESEARCH_GRAPH_IsFadeDone(u8 *a0);
void RESEARCH_GRAPH_EnterFadeOut(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
    RESEARCH_GRAPH_RequestFadeOut((char *)a0);
    RESEARCH_GRAPH_IncSubState((void *)a0);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone((u8 *)a0) != 0) {
    RESEARCH_GRAPH_SyncArrow((u8 *)a0);
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
    break;
    }
}
