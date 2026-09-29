/*
 * function: func_0215A6C4
 * address:  0x0215A6C4
 * packet:   pkt_ov010_0215A6C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: reads the word at +0x10C of the record held at +0x20.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0215A6C4(void *p)
{
    return *(u32 *)(*(char **)((char *)p + 0x20) + 0x10c);
}
