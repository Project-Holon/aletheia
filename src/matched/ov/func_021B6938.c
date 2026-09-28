/*
 * function: func_021B6938
 * address:  0x021B6938
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Width of the u16 pair at +0x34/+0x36, zero extended.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 func_021B6938(void *p)
{
    return (u16)(*(u16 *)((char *)p + 0x36) - *(u16 *)((char *)p + 0x34));
}
