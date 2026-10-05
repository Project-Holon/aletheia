/*
 * function: func_021DEC64
 * address:  0x021DEC64
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DEB40  0x021DEB40  thumb  ov170
 *   func_021DEB70  0x021DEB70  thumb  ov170
 *   func_021DEB90  0x021DEB90  thumb  ov170
 *
 * Fan the 5 arguments out to the 0x74/0x26, shifted and 6-argument
 *   stages, then release the 3-handle.
 */


extern void func_021DEB40(int, int, int);
extern void func_021DEB70(int, int, int);
extern void func_021DEB90(int, int, int, int, int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021DEC64(int a, int b, int c, int d, int e)
{
    func_021DEB40(a, b, d);
    func_021DEB70(a, b, e);
    func_021DEB90(a, b, c, d, e);
    func_02041B6C(3);
}
