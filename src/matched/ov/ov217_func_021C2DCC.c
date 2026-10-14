/*
 * function: PALETTE_ANIME_Clear
 * address:  0x021C2DCC
 * packet:   pkt_021C2DCC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14768.h"

typedef unsigned short u16;

extern void MI_CpuFill8(void *, int, int);

void PALETTE_ANIME_Clear(char *p)
{
    u16 t = ((struct Obj14768 *)p)->f0;
    MI_CpuFill8(p, 0, 0x20);
    ((struct Obj14768 *)p)->f0 = t;
}
