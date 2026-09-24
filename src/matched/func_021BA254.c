/*
 * function: func_021BA254
 * address:  0x021BA254
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Truncated product of the shifted u16 at +0x18 and 0x10e times +0x1c.
 *
 * symbols:
 *   func_0209C2B0  0x0209C2B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_0209C2B0(u32 a, u32 b);

u16 func_021BA254(void *p)
{
    return (u16)func_0209C2B0(*(u32 *)((char *)p + 0x18) << 15,
                              *(u32 *)((char *)p + 0x1c) * 0x10e);
}
