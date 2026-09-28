/*
 * function: func_021DCA84
 * address:  0x021DCA84
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Send a two-descriptor request with the timer base 0xc6000.
 *
 * symbols:
 *   func_021DC854  0x021DC854  thumb  ov119
 *   func_021DC894  0x021DC894  thumb  ov119
 */

extern int func_021DC854(void *a, int t);
extern void func_021DC894(void *a, int b, int c, int d, int e);

void func_021DCA84(void *a, int b, int c)
{
    int r = func_021DC854(a, 0xc6000);

    func_021DC894(a, b, c, r, 2);
}

