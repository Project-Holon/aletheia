/*
 * function: func_021B7C14
 * address:  0x021B7C14
 * packet:   pkt_ov102_021B7C14
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed u32 accessor: base + index*4 + 0x10.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u32 func_021B7C14(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0x10);
}
