/*
 * function: func_021B9510
 * address:  0x021B9510
 * packet:   pkt_021B9510
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B94C0  0x021B94C0  thumb
 *   func_021B87FC  0x021B87FC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B94C0(u16 *p, u16 v);
u8 *func_021B87FC(u8 *p, u32 idx);

u8 *func_021B9510(u16 *p, u8 *q, u32 v)
{
    if (func_021B94C0(p, (u16)v) == 0)
        return func_021B87FC(q, v);
    return 0;
}
