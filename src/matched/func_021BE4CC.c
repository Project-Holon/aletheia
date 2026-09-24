/*
 * function: func_021BE4CC
 * address:  0x021BE4CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BE4CC(void *p, u32 v)
{
    *(u32 *)((char *)p + 0x20) = v;
    *(u32 *)((char *)p + 0x24) = 0;
    *(u32 *)((char *)p + 0x28) = 0;
    *(u32 *)((char *)p + 0x3dc) = 0;
}
