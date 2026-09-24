/*
 * function: func_021BE9F8
 * address:  0x021BE9F8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Arms a drain: clears +0xc8/+0xdc and stores the b/c pair at +0xc0.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;

int func_021BE9F8(u8 *p, int a, int b)
{
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xc8) = 0;
    *(u32 *)(p + 0xdc) = 0;
    *(u32 *)(p + 0xc0) = a;
    *(u32 *)(p + 0xc4) = b;
    return 0;
}
