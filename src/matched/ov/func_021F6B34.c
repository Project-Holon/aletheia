/*
 * function: WORLDTRADE_BOX_ClampSlot
 * address:  0x021F6B34
 * packet:   pkt_021F6B34
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
 * True only for the 0xff sentinel.
 */

int WORLDTRADE_BOX_ClampSlot(int v)
{
    if (v == 0xff) {
        return 1;
    }
    return 0;
}
