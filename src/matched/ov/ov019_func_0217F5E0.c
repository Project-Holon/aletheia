/*
 * function: func_0217F5E0
 * address:  0x0217F5E0
 * packet:   pkt_ov019_0217F5E0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_0219161C  0x0219161C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C54(u32 a);
extern u32 func_02191558(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0219161C(u32 a, u32 b, u32 c, u32 d);

void func_0217F5E0(char *p, u32 a1)
{
    if (*(u32 *)(p + 0x2818) == 0) {
        u32 x = func_02191558(func_02188C54(a1), *(u32 *)(p + 0x2808), 0, 1, 1, 0x1e, 2);
        *(u32 *)(p + 0x2818) = x;
        func_0219161C(x, 0, 0, 0x103);
    }
}
