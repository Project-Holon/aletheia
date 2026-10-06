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


extern void func_021DEB40(unsigned int a, int b, void *c);
extern void func_021DEB70(int, int, int);
extern void func_021DEB90(void *unused, void *unused2, int x, unsigned int base, unsigned int pal);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021DEC64(void *a, void *b, int c, void *d, int e)
{
    func_021DEB40((int)a, (int)b, d);
    func_021DEB70((int)a, (int)b, e);
    func_021DEB90(a, b, c, (unsigned int)d, e);
    func_02041B6C(3);
}
