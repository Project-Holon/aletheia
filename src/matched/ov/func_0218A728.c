/*
 * function: func_0218A728
 * address:  0x0218A728
 * packet:   pkt_0218A728
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Sub02008C20Obj;
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02012F2C(u32, u32, u32, u32);

int func_0218A728(u32 a, u32 b, u32 c, u32 d)
{
return func_02008DF0((struct Sub02008C20Obj *)func_02012F2C(a, b, c, d), 0);
}

