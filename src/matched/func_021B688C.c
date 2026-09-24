/*
 * function: func_021B688C
 * address:  0x021B688C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 1 when the byte at +0x44 is 6 or 0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021B688C(void *p)
{
    u8 v = *(u8 *)((char *)p + 0x44);
    return v == 6 || v == 0;
}
