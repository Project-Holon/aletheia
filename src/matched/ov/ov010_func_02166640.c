/*
 * function: func_02166640
 * address:  0x02166640
 * packet:   pkt_ov010_02166640
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (sole blocker of ov018 func_0217C37C): true when the
 * argument plus one, truncated to a byte, is 2, 3 or 4. Twin of
 * func_02166618.
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_02166640(int a0)
{
    u8 t = a0 + 1;

    if ((u8)(t + 0xFE) <= 2)
        return 1;
    return 0;
}
