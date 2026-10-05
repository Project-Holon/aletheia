/*
 * function: func_02166618
 * address:  0x02166618
 * packet:   pkt_ov010_02166618
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: true when the argument plus one, truncated to a byte,
 * is 1.
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_02166618(int a0)
{
    if ((u8)(a0 + 1) == 1)
        return 1;
    return 0;
}
