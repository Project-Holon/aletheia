/*
 * function: func_02190E74
 * address:  0x02190E74
 * packet:   pkt_ov021_02190E74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190D2C  0x02190D2C  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02190D48(u32);
extern u32 func_02190D2C(u32, u32, u32, u32, u32, u32);
extern u32 func_02193210(u32);
extern void func_02045CAC(u32, u32, u32);

void func_02190E74(u32 *p, u32 b, u32 c, u32 d)
{
    if (p[1] != 0) {
        func_02190D48(p[1]);
    }
    func_02045CAC(p[3], d, p[4]);
    p[1] = func_02190D2C(p[5], p[4], p[0], b, c, func_02193210(p[5] + 0x160));
}
