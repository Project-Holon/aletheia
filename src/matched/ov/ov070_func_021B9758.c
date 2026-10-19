/*
 * function: ITEMMENU_ApplyBgPalettes
 * address:  0x021B9758
 * packet:   pkt_ov070_021B9758
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_FreeTileRun  0x0203FB44  arm
 */
#include "../include/Obj06175.h"

typedef unsigned int   u32;
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);

void ITEMMENU_ApplyBgPalettes(char *p)
{
    unsigned v;
    v = ((struct Obj06175 *)p)->f7FC;
    BG_SYS_FreeTileRun((int)4, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f800;
    BG_SYS_FreeTileRun((int)5, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f808;
    BG_SYS_FreeTileRun((int)3, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f7F8;
    BG_SYS_FreeTileRun((int)0, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f804;
    BG_SYS_FreeTileRun((int)1, (unsigned short)v, (unsigned short)(v >> 16));
}
