/*
 * function: func_021BD308
 * address:  0x021BD308
 * packet:   pkt_021BD308
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced blob: field getter at +8.
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021BD308(u8 *p)
{
    return *(u32 *)(p + 8);
}
