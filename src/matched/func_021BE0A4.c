/*
 * function: func_021BE0A4
 * address:  0x021BE0A4
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 func_021BE0A4(void *p)
{
    return *(u8 *)((char *)p + 0x19);
}
