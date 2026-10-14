/*
 * function: WORLDTRADE_ENTER_RestartNetTimeout
 * address:  0x021F9254
 * packet:   pkt_021F9254
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *

 *
 * Tail call into GFL_NET_RestartWithDefaultTimeout with the fixed 0/0x48 pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void WORLDTRADE_ENTER_RestartNetTimeout(u8 *a0)
{
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}
