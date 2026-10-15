/*
 * function: BOX2_UI_GetGridSlotPoint
 * address:  0x021EF224
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_HitTablePoint  0x021EF108  thumb  ov170
 *
 * Query the 0x021F1174 table with index 4; -1 becomes 0xff,
 *   otherwise the answer plus 0x24.  The -1 arm must be the branch target.
 */


extern int BOX2_UI_HitTablePoint(const char *p, unsigned n, int a, int b);
int BOX2_UI_GetGridSlotPoint(int a, int b)
{
    int v = BOX2_UI_HitTablePoint((char *)0x021F1174, 4, a, b);
    if (v != -1)
        return v + 0x24;
    return 0xff;
}
