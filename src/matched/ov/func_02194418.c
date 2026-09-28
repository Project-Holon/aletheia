/*
 * function: func_02194418
 * address:  0x02194418
 * packet:   pkt_02194418
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
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02082BCC(u32, u32, u32);
extern u32 func_0216CF2C(u32, u32, u32, u32);

int func_02194418(u32 a, u32 b, u32 c, u32 d)
{
if (*(u16 *)((u8 *)(a) + 4) == 0) {
    func_0216CF2C(*(u32 *)((u8 *)(a) + 8), b, c, d);
}
return func_02082BCC(a, 0, 12);
}

