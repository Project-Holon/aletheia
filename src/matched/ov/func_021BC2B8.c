/*
 * function: func_021BC2B8
 * address:  0x021BC2B8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sign of +0x4c into +0x50: 1 when negative, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC2B8(void *p)
{
    if (*(s32 *)((char *)p + 0x4c) < 0) {
        *(u32 *)((char *)p + 0x50) = 1;
    } else {
        *(u32 *)((char *)p + 0x50) = -1;
    }
}
