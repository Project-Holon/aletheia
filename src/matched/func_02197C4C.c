/*
 * function: func_02197C4C
 * address:  0x02197C4C
 * packet:   pkt_02197C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C5D0  0x0219C5D0  thumb  ov021
 *   func_0216D528  0x0216D528  thumb
 *   func_0219D488  0x0219D488  thumb  ov021
 *   func_0216D95C  0x0216D95C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D520(u32, u32, u32, u32);
extern u32 func_0216D528(u32);
extern u32 func_0216D95C(u32, u32);
extern u32 func_0219C5D0(u32);
extern u32 func_0219D488(u32);

int func_02197C4C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D520(a, b, c, d) != 0) {
    func_0219C5D0(a);
}
if (func_0216D528(a) != 0) {
    func_0219D488(a);
}
return func_0216D95C(a, 0);
}

