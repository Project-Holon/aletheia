/*
 * function: PSEL_UpdateBgAD68
 * address:  0x021BAD68
 * packet:   pkt_021BAD68
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
extern void BG_SYS_ClearLayerEx(int channel, u16 val);

void PSEL_UpdateBgAD68(char *a0)
{
    BG_SYS_ClearLayerEx(2, 0xd000);
    BG_SYS_ClearLayerEx(6, 0);
}
