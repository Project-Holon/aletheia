/*
 * function: func_0217F2A8
 * address:  0x0217F2A8
 * packet:   pkt_ov019_0217F2A8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C54(u32 a);
extern u32 func_02190A28(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02190988(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void func_0217F2A8(char *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h = func_02188C54(a1);

    if (*(u32 *)(p + 0x2810) == 0) {
        u32 x = func_02190A28(a2, a3, *(u32 *)(p + 0x2808), 0x41);
        *(u32 *)(p + 0x2810) = func_02190988(h, a4, x, 0, 0, 0, 0, 1);
    }
}
