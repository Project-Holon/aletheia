/*
 * function: func_021C1B4C
 * address:  0x021C1B4C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pack the bytes at +0xb, +0xc and +0xd into one u16, 5 and 10 bits apart.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C1B4C(void *p)
{
    return (u16)(*(u8 *)((char *)p + 0xb) | (*(u8 *)((char *)p + 0xc) << 5) | (*(u8 *)((char *)p + 0xd) << 10));
}
