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

 *
 * Tail call into func_02035C08 with the overlay's own state object.
 */

extern void func_02035C08(const void *p);
extern char g_022037D4[];

void func_021FE254(void)
{
    func_02035C08(g_022037D4);
}
