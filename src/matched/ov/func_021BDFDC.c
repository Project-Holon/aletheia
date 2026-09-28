/*
 * function: func_021BDFDC
 * address:  0x021BDFDC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x1e0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BDFDC(void *p)
{
    return *(u32 *)((char *)p + 0x1e0);
}
