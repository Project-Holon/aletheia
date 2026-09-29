/*
 * function: func_0217D624
 * address:  0x0217D624
 * packet:   pkt_ov018_0217D624
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02025538  0x02025538  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 */

extern int func_0204B100();
extern int func_0204B034();
extern void func_0204B258();
extern int func_02025538();
extern int func_0203101C();
extern int func_0201D7EC();
extern int func_0201EC64();
extern int func_0201C440();
extern int func_02045B38();
extern int func_020457B0();
extern char d_021836B4[];

void func_0217D624(int *o)
{
    int t;

    o[0x54 / 4] = func_0204B100(0x29, 5, 0x70);
    t = func_0204B034(d_021836B4, 1, 0x70);
    o[0x58 / 4] = t;
    func_0204B258(o[0x54 / 4], t);
    o[0xB0 / 4] = func_02025538(0x70, o[0x54 / 4]);
    o[0x20 / 4] = func_0203101C(0x70, 0x70, 4, 0x20);
    o[0x1C / 4] = func_0201D7EC(0x17, 0, 0, 0, 0x70);
    o[0x24 / 4] = func_0201EC64(0x70);
    o[0x28 / 4] = func_0201C440(0x70);
    o[0x2C / 4] = func_02045B38(0, 2, 0x2D, 0x70);
    o[0x30 / 4] = func_02045B38(0, 2, 0x42, 0x70);
    o[0x38 / 4] = func_020457B0(0x80, 0x70);
    o[0x3C / 4] = func_020457B0(0x80, 0x70);
    o[0x40 / 4] = func_020457B0(0x80, 0x70);
}
