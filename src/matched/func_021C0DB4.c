/*
 * function: func_021C0DB4
 * address:  0x021C0DB4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed u32 read: element i of the table at +0x14.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C0DB4(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x14);
}
