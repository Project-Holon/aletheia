/*
 * function: CircleGraph_GetSlice
 * address:  0x021C1AB4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Record pointer: base + 0x1c + n * 0x14.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void *CircleGraph_GetSlice(void *p, u32 n)
{
    return (char *)p + 0x1c + n * 0x14;
}
