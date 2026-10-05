/*
 * function: func_021B6B74
 * address:  0x021B6B74
 * packet:   pkt_ov098_021B6B74
 * region:   ov098
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    test and clear flag byte at +0x3a, returns 1 if it was set. Witness for the call in ov098 func_021B6578 (2026-10-05, lane W-B).
 */

int func_021B6B74(unsigned char *p)
{
    if (p[0x3a]) {
        p[0x3a] = 0;
        return 1;
    }
    return 0;
}
