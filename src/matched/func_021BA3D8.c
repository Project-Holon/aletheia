/*
 * function: func_021BA3D8
 * address:  0x021BA3D8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BA3D8(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x74);
}
