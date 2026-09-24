/*
 * function: func_021C1B60
 * address:  0x021C1B60
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pack the bytes at +0xe, +0xf and +0x10 into one u16, 5 and 10 bits apart.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C1B60(void *p)
{
    return (u16)(*(u8 *)((char *)p + 0xe) | (*(u8 *)((char *)p + 0xf) << 5) | (*(u8 *)((char *)p + 0x10) << 10));
}
