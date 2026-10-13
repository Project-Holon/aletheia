/*
 * function: func_021FE254
 * address:  0x021FE254
 * packet:   pkt_021FE254
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_022037D4  0x022037D4  data  ov135
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9

 *
 * Tail call into TOUCHPANEL_HitTrg with the overlay's own state object.
 */

extern int TOUCHPANEL_HitTrg(const void *p);
extern char g_022037D4[];

int func_021FE254(void)
{
    return TOUCHPANEL_HitTrg(g_022037D4);
}
