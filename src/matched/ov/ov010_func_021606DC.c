/*
 * function: func_021606DC
 * address:  0x021606DC
 * packet:   pkt_ov010_021606DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_02158768(void *p, u32 msg, u32 a, u32 b);
extern void *func_021589D0(void *h);
extern void func_02159058(void *p, u32 a, u32 b, u32 c, u32 d);

void *func_021606DC(void *p, u32 a)
{
    void *h;

    h = func_02158768(p, 0x7D6, 0, 0x15);
    func_02159058(func_021589D0(h), a, 0, 0, 0);
    return h;
}
