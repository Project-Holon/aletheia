/*
 * function: DENDOU_VIEW_ApplyPaletteFade
 * address: 0x021DCBA4
 * packet: pkt_ov171_021DCBA4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 */
#include "../include/Obj10658.h"
typedef unsigned short u16;
extern void PALANM_BlendChannelMask(unsigned, unsigned, u16, unsigned, unsigned);
struct Obj02021EE4;
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
void DENDOU_VIEW_ApplyPaletteFade(char *p)
{
    unsigned i;
    for (i=0; i<6; i++)
        PALANM_BlendChannelMask(((struct Obj10658 *)p)->fB30, 2, (1<<i)|(1<<(i+6)), (unsigned char)p[0xb3a+i], 0);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)(((struct Obj10658 *)p)->fB30), 1);
}
