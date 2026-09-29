/*
 * function: func_021A3C54
 * address:  0x021A3C54
 * packet:   pkt_ov021_021A3C54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): maps a key mask to a direction, 9 for none.
 * Filed as a blocker of ov021 func_021A3BB4.
 */

typedef unsigned int u32;

int func_021A3C54(u32 keys)
{
    if (keys & 0x40) {
        return 0;
    }
    if (keys & 0x80) {
        return 1;
    }
    return 9;
}
