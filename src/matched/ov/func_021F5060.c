/*
 * function: WORLDTRADE_ClearBlendRegs
 * address:  0x021F5060
 * packet:   pkt_021F5060
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Clear the two display control registers.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void WORLDTRADE_ClearBlendRegs(void)
{
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
}
