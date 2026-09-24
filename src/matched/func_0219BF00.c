/*
 * function: func_0219BF00
 * address:  0x0219BF00
 * packet:   pkt_0219BF00
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
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0219BEB4  0x0219BEB4  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D568(u32, u32);
extern u32 func_0216DB24(u32);
extern u32 func_0219BEB4(u32, u32);
extern u32 func_0219BF3C(u32, u32);
extern u32 func_0219BF48(u32, u32, u32, u32);

int func_0219BF00(u32 a, u32 b, u32 c, u32 d)
{
if (*(u8 *)((u8 *)(b) + 2) == 0) {
    if (func_0219BF48(a, *(u8 *)((u8 *)(b) + 2), c, d) == 0) {
        if (func_0216DB24(a) == 1) {
            func_0219BF3C(a, func_0219BEB4(a, *(u8 *)((u8 *)(b) + 1)));
        }
    }
    func_0216D568(a, (2 << 14));
}
return 0;
}

