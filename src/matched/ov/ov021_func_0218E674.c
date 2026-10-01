/*
 * function: func_0218E674
 * address:  0x0218E674
 * packet:   pkt_ov021_0218E674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218E610  0x0218E610  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0218E610(u32 b, u16 *x, u16 *y, u32 *z);

void func_0218E674(u8 *a, u32 b)
{
    struct { u16 y, x; u32 z; } t;
    func_0218E610(b, &t.x, &t.y, &t.z);
    *(u16 *)(a + 0x78) = t.x;
    *(u16 *)(a + 0x7a) = t.y;
    *(u32 *)(a + 0x7c) = t.z;
}
