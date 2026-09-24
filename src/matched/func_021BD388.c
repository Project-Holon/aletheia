/*
 * function: func_021BD388
 * address:  0x021BD388
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD43C 0x021BD43C  thumb  ov208
 *   func_021BD808 0x021BD808  thumb  ov208

 * Calls func_021BD43C then func_021BD808.
 */


extern void func_021BD43C(void);
extern void func_021BD808(void);

void func_021BD388(void)
{
    func_021BD43C();
    func_021BD808();
}

