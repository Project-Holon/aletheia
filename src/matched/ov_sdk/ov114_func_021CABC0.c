/*
 * function: func_021CABC0
 * address:  0x021CABC0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CABDC  0x021CABDC  arm  ov114
 *   func_021CAE94  0x021CAE94  arm  ov114
 *
 *
 * Null-guarded flush: seals the pending batch, then drains `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021CAE94(void);
extern void func_021CABDC(u8 *p);

void func_021CABC0(int a)
{
    if (a == 0)
        return;
    func_021CAE94();
    func_021CABDC((u8 *)a);
}
