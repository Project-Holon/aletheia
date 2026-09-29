/*
 * function: func_02192FA4
 * address:  0x02192FA4
 * packet:   pkt_ov021_02192FA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_021929E8  0x021929E8  thumb  ov021
 */

extern void func_02049B40(int, int, int, int, int, int);
extern void func_0201F5BC(int, int, int, int, int);
extern void func_021929E8(int);

void func_02192FA4(int a, int b)
{
    func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
    func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    func_0201F5BC(a & 0xff, 1, 0xd, 0, b);
    func_021929E8(b);
}
