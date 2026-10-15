/*
 * function: RESEARCH_LIST_HideEntryPalette
 * address: 0x021BC50C
 * packet: pkt_ov217_021BC50C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   PALANM_RequestFade  0x0202173C  thumb  arm9
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct PalAnmObj PalAnmObj;
extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
void RESEARCH_LIST_HideEntryPalette(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj00025 *)p)->f98, 1, 0xBBFF, 2, 10, 0, 0, ((struct Obj00025 *)p)->f150);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj00025 *)p)->f98, 4, 0xCF, 2, 10, 0, 0, ((struct Obj00025 *)p)->f150);
    ((struct Obj00025 *)p)->f15C = 0;
}
