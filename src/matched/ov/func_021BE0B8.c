/*
 * function: func_021BE0B8
 * address:  0x021BE0B8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Invert the flag at +0x24.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BE0B8(void *p)
{
    u32 v = *(u32 *)((char *)p + 0x24);
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    *(u32 *)((char *)p + 0x24) = v;
}
