/*
 * function: func_021DCFDC
 * address:  0x021DCFDC
 * packet:   pkt_021DCFDC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Maps 0, 1, 2 to themselves and everything else to 0.
 */

typedef unsigned long u32;

u32 func_021DCFDC(u32 v)
{
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}
