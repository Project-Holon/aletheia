/*
 * function: func_021BB1F4
 * address:  0x021BB1F4
 * packet:   pkt_ov021_021BB1F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021B7884  0x021B7884  thumb  ov021
 *   func_0219EF44  0x0219EF44  thumb  ov021
 *   func_021BB088  0x021BB088  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_021B7884(u16, int, u32);
extern u32 func_0219EF44(u32);
extern u32 func_021BB088(u32);
extern int d_021DE2D0;

u32 *func_021BB1F4(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_02030734((u16)a, 0x18, 1, (const char *)&d_021DE2D0, 0x47);

    p[0] = func_021B7884(a, 0x30, b);
    p[1] = func_0219EF44(a);
    p[3] = c;
    p[4] = d;
    p[2] = func_021BB088(a);
    return p;
}
