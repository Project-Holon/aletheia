/*
 * function: func_021BA180
 * address:  0x021BA180
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BA180(void *p, u32 v)
{
    *(u32 *)((char *)p + 0x18) = v;
    *(u32 *)((char *)p + 0x1c) = 0;
    *(u32 *)((char *)p + 0x20) = 0;
    *(u32 *)((char *)p + 0x80) = 0;
}
