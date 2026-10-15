/*
 * function: BOX2_UI_GetPartySlotPoint
 * address:  0x021EF180
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
 *   g_021F0DCC  0x021F0DCC  data  ov170
 *
 * Fixed table and count, caller's two values.
 */



extern int BOX2_UI_HitTablePoint(const char *p, unsigned n, int a, int b);
int BOX2_UI_GetPartySlotPoint(int a, int b)
{
    return BOX2_UI_HitTablePoint((char *)0x021F0DCC, 0x1e, a, b);
}
