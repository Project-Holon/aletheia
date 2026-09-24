/*
 * function: func_021B985C
 * address:  0x021B985C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reset the object: marker u16 at +0, value at +4, six u32 fields zeroed.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B985C(void *p, u32 value)
{
    *(u16 *)p = 1;
    *(u32 *)((char *)p + 4) = value;
    *(u32 *)((char *)p + 8) = 0;
    *(u32 *)((char *)p + 0xc) = 0;
    *(u32 *)((char *)p + 0x10) = 0;
    *(u32 *)((char *)p + 0x14) = 0;
    *(u32 *)((char *)p + 0x18) = 0;
    *(u32 *)((char *)p + 0x1c) = 0;
}
