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

 *
 * Tail call into func_02035C08 with the overlay's own state object.
 */

extern void func_02035C08(void *p);
extern char g_022038EC[];

void func_0220052C(void)
{
    func_02035C08(g_022038EC);
}
