/*
 * function: ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind
 * address:  0x021BE300
 * packet:   pkt_021BE300
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Returns 6, 5, 4 or 3 for the four known kinds and 9 for anything else.
 */


int ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind(int kind)
{
    switch (kind) {
    case 0:
        return 6;
    case 1:
        return 5;
    case 2:
        return 4;
    case 3:
        return 3;
    }
    return 9;
}

