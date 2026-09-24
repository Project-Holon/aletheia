/*
 * function: func_021BAC98
 * address:  0x021BAC98
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BAC98(void *p)
{
    return *(u32 *)((char *)p + 0x168);
}
