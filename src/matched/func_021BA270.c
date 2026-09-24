/*
 * function: func_021BA270
 * address:  0x021BA270
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test the byte at +0x10 against 0xb4, unsigned.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021BA270(void *p)
{
    if (*(u8 *)((char *)p + 0x10) >= 0xb4) {
        return 1;
    }
    return 0;
}
