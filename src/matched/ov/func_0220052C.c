/*
 * function: func_0220052C
 * address:  0x0220052C
 * packet:   pkt_0220052C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_022038EC  0x022038EC  data  ov135
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9

 *
 * Tail call into TOUCHPANEL_HitTrg with the overlay's own state object.
 */

extern int TOUCHPANEL_HitTrg(const void *key);
extern char g_022038EC[];

int func_0220052C(void)
{
    return TOUCHPANEL_HitTrg(g_022038EC);
}
