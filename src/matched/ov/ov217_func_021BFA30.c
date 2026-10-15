/*
 * function: RESEARCH_GRAPH_InitFields
 * address:  0x021BFA30
 * packet:   pkt_ov217_021BFA30
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   RESEARCH_GRAPH_ClearGraphTable 0x021BFC50 thumb ov217
 *   RESEARCH_GRAPH_ClearCommandQueue 0x021BFB0C thumb ov217
 *   RESEARCH_GRAPH_ClearCircles 0x021BFBDC thumb ov217
 *   RESEARCH_GRAPH_ClearArrow 0x021BFE80 thumb ov217
 *   RESEARCH_GRAPH_ClearPercentages 0x021BFEE4 thumb ov217
 *   RESEARCH_GRAPH_ClearMessages 0x021BFB60 thumb ov217
 *   RESEARCH_GRAPH_ClearWordSet 0x021BFBB8 thumb ov217
 *   RESEARCH_GRAPH_ClearFont 0x021BFB30 thumb ov217
 *   RESEARCH_GRAPH_ClearLabels 0x021C019C thumb ov217
 *   RESEARCH_GRAPH_ClearUnits 0x021C0384 thumb ov217
 *   RESEARCH_GRAPH_ClearActors 0x021C03EC thumb ov217
 *   RESEARCH_GRAPH_ClearBmps 0x021C04B0 thumb ov217
 *   RESEARCH_GRAPH_ClearPalAnm 0x021C07B0 thumb ov217
 *   RESEARCH_GRAPH_ClearPaletteAnime 0x021C0820 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00926.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_020056BC(void);
extern void RESEARCH_GRAPH_ClearGraphTable(u8 *a0);
extern void RESEARCH_GRAPH_ClearCommandQueue(void *p);
extern void RESEARCH_GRAPH_ClearCircles(void *p);
extern void RESEARCH_GRAPH_ClearArrow(void *p);
extern void RESEARCH_GRAPH_ClearPercentages(void *p);
extern void RESEARCH_GRAPH_ClearMessages(void *p);
extern void RESEARCH_GRAPH_ClearWordSet(void *p);
extern void RESEARCH_GRAPH_ClearFont(void *p);
extern void RESEARCH_GRAPH_ClearLabels(void *p);
extern void RESEARCH_GRAPH_ClearUnits(void *p);
extern void RESEARCH_GRAPH_ClearActors(void *p);
extern void RESEARCH_GRAPH_ClearBmps(void *p);
extern void RESEARCH_GRAPH_ClearPalAnm(void *p);
extern void RESEARCH_GRAPH_ClearPaletteAnime(void *p);
void RESEARCH_GRAPH_InitFields(char *p)
{
    int i;
    ((struct Obj00926 *)p)->f20 = 0;
    ((struct Obj00926 *)p)->f24 = 0;
    ((struct Obj00926 *)p)->f3DC = 0;
    ((struct Obj00926 *)p)->f2C = 0xf;
    ((struct Obj00926 *)p)->f28 = 0;
    ((struct Obj00926 *)p)->f30 = 0;
    ((struct Obj00926 *)p)->f34 = 0;
    ((struct Obj00926 *)p)->f3C4 = 0;
    ((struct Obj00926 *)p)->f3C8 = 0;
    ((struct Obj00926 *)p)->f3CC = 0;
    ((struct Obj00926 *)p)->f3D0 = 0;
    ((struct Obj00926 *)p)->f3D4 = 0;
    ((struct Obj00926 *)p)->f3D8 = 0;
    ((struct Obj00926 *)p)->f2B8 = 0;
    ((struct Obj00926 *)p)->f2B9 = 0;
    ((struct Obj00926 *)p)->f2CC = 0;
    ((struct Obj00926 *)p)->f3BC = func_020056BC();
    ((struct Obj00926 *)p)->f2FC = 0;
    ((struct Obj00926 *)p)->f2FD = 0;
    ((struct Obj00926 *)p)->f3E4 = 0;
    ((struct Obj00926 *)p)->f3E0 = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(p + i * 4 + 0x368) = 0;
    }
    RESEARCH_GRAPH_ClearGraphTable((u8 *)p);
    RESEARCH_GRAPH_ClearCommandQueue(p);
    RESEARCH_GRAPH_ClearCircles(p);
    RESEARCH_GRAPH_ClearArrow(p);
    RESEARCH_GRAPH_ClearPercentages(p);
    RESEARCH_GRAPH_ClearMessages(p);
    RESEARCH_GRAPH_ClearWordSet(p);
    RESEARCH_GRAPH_ClearFont(p);
    RESEARCH_GRAPH_ClearLabels(p);
    RESEARCH_GRAPH_ClearUnits(p);
    RESEARCH_GRAPH_ClearActors(p);
    RESEARCH_GRAPH_ClearBmps(p);
    RESEARCH_GRAPH_ClearPalAnm(p);
    RESEARCH_GRAPH_ClearPaletteAnime(p);
}
