/*
 * function: func_021FD15C
 * address:  0x021FD15C
 * packet:   pkt_ov186_021FD15C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FC734  0x021FC734  thumb  ov186
 *   func_021FBDA4  0x021FBDA4  thumb  ov186
 */

typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int a, unsigned mode);

void func_021FD15C(void *p, int a1)
{
    func_021FC734(p);
    func_021FBDA4(a1, 2);
}
