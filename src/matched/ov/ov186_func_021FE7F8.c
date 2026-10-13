/*
 * function: func_021FE7F8
 * address: 0x021FE7F8
 * packet: pkt_ov186_021FE7F8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_RequestFullTransfer 0x02021F08 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
#include "../include/Obj05507.h"
extern void PALANM_BlendChannelMask(unsigned, unsigned, unsigned short, unsigned, unsigned);
struct Obj02021F08;
struct S02021D50;
extern void PALANM_RequestFullTransfer(struct Obj02021F08 *o, int v);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
void func_021FE7F8(char *p, int mask)
{
    if (mask & 1)
        PALANM_BlendChannelMask(*(unsigned *)&((struct Obj05507 *)p)->f20, 0, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    if (mask & 2)
        PALANM_BlendChannelMask(*(unsigned *)&((struct Obj05507 *)p)->f20, 1, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    PALANM_RequestFullTransfer(((struct Obj05507 *)p)->f20, 1);
    PALANM_TransferPalettes(((struct Obj05507 *)p)->f20);
}
