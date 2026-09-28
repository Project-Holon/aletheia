/*
 * function: func_021B8614
 * address:  0x021B8614
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the block behind the third argument, limit byte 0xff.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B8614(int unused, int unused2, void *p)
{
    *(u32 *)((char *)p + 0xc) = 0;
    *(u32 *)p = 0;
    *(u32 *)((char *)p + 4) = 0;
    *(u32 *)((char *)p + 8) = 0;
    *(u32 *)((char *)p + 0x10) = 0;
    *(u8 *)((char *)p + 0x14) = 0xff;
    *(u32 *)((char *)p + 0x18) = 0;
}
