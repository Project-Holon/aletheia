/*
 * function: func_0219CBD4
 * address:  0x0219CBD4
 * packet:   pkt_0219CBD4
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
 *   func_0219CA98  0x0219CA98  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);

int func_0219CBD4(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA98((u32 *)(a + 20), b, (u16 *)c, (u16 *)d);
}

