/*
 * function: func_02159058
 * address:  0x02159058
 * packet:   pkt_ov010_02159058
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159030  0x02159030  thumb  ov010
 */

typedef unsigned short u16;

extern int func_02159030(int a0, int a1, int a2);

int func_02159058(int a, int b, int c, int d, u16 e)
{
    func_02159030(a, 0x8000, b);
    func_02159030(a, 0x8001, c);
    func_02159030(a, 0x8002, d);
    return func_02159030(a, 0x8003, e);
}
