/*
 * function: RESEARCH_LIST_InitFields
 * address: 0x021BC774
 * packet: pkt_ov217_021BC774
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BC816.
 * symbols:
 *   RESEARCH_LIST_ClearCommandQueue 0x021BC94C thumb ov217
 *   RESEARCH_LIST_ClearMessages 0x021BC910 thumb ov217
 *   RESEARCH_LIST_ClearFont 0x021BC8D0 thumb ov217
 *   RESEARCH_LIST_ClearLabels 0x021BCD6C thumb ov217
 *   RESEARCH_LIST_ClearUnits 0x021BCF4C thumb ov217
 *   RESEARCH_LIST_ClearActors 0x021BCFB4 thumb ov217
 *   RESEARCH_LIST_ClearResources 0x021BCDDC thumb ov217
 *   RESEARCH_LIST_ClearPalAnm 0x021BD474 thumb ov217
 *   RESEARCH_LIST_ClearBmps 0x021BD078 thumb ov217
 *   RESEARCH_LIST_ClearPaletteAnime 0x021BD50C thumb ov217
 */
#include "../include/Obj00850.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern void RESEARCH_LIST_ClearCommandQueue(void *);
extern void RESEARCH_LIST_ClearMessages(void *);
extern void RESEARCH_LIST_ClearFont(void *);
extern void RESEARCH_LIST_ClearLabels(void *);
extern void RESEARCH_LIST_ClearUnits(void *);
extern void RESEARCH_LIST_ClearActors(void *);
extern void RESEARCH_LIST_ClearResources(void *);
extern void RESEARCH_LIST_ClearPalAnm(void *);
extern void RESEARCH_LIST_ClearBmps(void *);
extern void RESEARCH_LIST_ClearPaletteAnime(void *);
void RESEARCH_LIST_InitFields(u8 *p)
{
    ((struct Obj00850 *)p)->f4 = 0;
    ((struct Obj00850 *)p)->f1C = 0;
    ((struct Obj00850 *)p)->f24 = 0;
    ((struct Obj00850 *)p)->f158 = 0;
    ((struct Obj00850 *)p)->f28 = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    ((struct Obj00850 *)p)->f2C = 0;
    p[0x31] = 255;
    ((struct Obj00850 *)p)->f150 = func_020056BC();
    ((struct Obj00850 *)p)->f34 = 0;
    ((struct Obj00850 *)p)->f38 = 0;
    ((struct Obj00850 *)p)->f3C = 0;
    ((struct Obj00850 *)p)->f40 = 0;
    ((struct Obj00850 *)p)->f44 = 0;
    ((struct Obj00850 *)p)->f48 = 0;
    ((struct Obj00850 *)p)->f15C = 0;
    ((struct Obj00850 *)p)->f160 = 0;
    ((struct Obj00850 *)p)->f168 = 0;
    ((struct Obj00850 *)p)->f164 = 0;
    ((struct Obj00850 *)p)->f154 = 0;
    RESEARCH_LIST_ClearCommandQueue(p);
    RESEARCH_LIST_ClearMessages(p);
    RESEARCH_LIST_ClearFont(p);
    RESEARCH_LIST_ClearLabels(p);
    RESEARCH_LIST_ClearUnits(p);
    RESEARCH_LIST_ClearActors(p);
    RESEARCH_LIST_ClearResources(p);
    RESEARCH_LIST_ClearPalAnm(p);
    RESEARCH_LIST_ClearBmps(p);
    RESEARCH_LIST_ClearPaletteAnime(p);
}
