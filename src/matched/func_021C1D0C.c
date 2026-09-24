/*
 * function: func_021C1D0C
 * address:  0x021C1D0C
 * packet:   pkt_021C1D0C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1FC4 0x021C1FC4  thumb  ov208
 *   func_021C2238 0x021C2238  thumb  ov208

 * Calls func_021C1FC4 then func_021C2238 on the same three arguments.
 */


extern void func_021C1FC4(int, int, int);
extern void func_021C2238(int, int, int);

void func_021C1D0C(int a, int b, int c)
{
    func_021C1FC4(a, b, c);
    func_021C2238(a, b, c);
}

