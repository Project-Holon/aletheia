/*
 * function: func_021C0968
 * address:  0x021C0968
 * packet:   pkt_021C0968
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0980 0x021C0980  thumb  ov208
 *   func_021C0A88 0x021C0A88  thumb  ov208

 */

extern void func_021C0980(int a, unsigned char *p, int a2);
extern void func_021C0A88(int, int, int);

void func_021C0968(int a, int b, int c)
{
    func_021C0980(a, (unsigned char *)b, c);
    func_021C0A88(a, b, c);
}

