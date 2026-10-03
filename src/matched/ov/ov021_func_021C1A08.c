/*
 * function: func_021C1A08
 * address:  0x021C1A08
 * packet:   pkt_ov021_021C1A08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021DE3C8     0x021DE3C8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02050B80(u32);
extern u8 d_021DE3C8;

u32 *func_021C1A08(u32 a)
{
    u32 *r;

    r = func_02030734(a, 0x10, 1, (const char *)&d_021DE3C8, 0x2e);
    *(u16 *)((u8 *)r + 4) = a;
    func_02050B80(a);
    r[2] = (u32)func_02030734(a, 0x4800, 1, (const char *)&d_021DE3C8, 0x34);
    return r;
}
