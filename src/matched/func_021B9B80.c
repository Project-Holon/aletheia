/*
 * function: func_021B9B80
 * address:  0x021B9B80
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag test: nonzero u32 at +0x88 as 1/0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021B9B80(void *p)
{
    if (*(u32 *)((char *)p + 0x88) != 0) {
        return 1;
    }
    return 0;
}
