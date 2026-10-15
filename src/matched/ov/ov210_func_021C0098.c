/*
 * function: ZKNSEARCH_MAIN_DeselectCursor
 * address:  0x021C0098
 * packet:   pkt_ov210_021C0098
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetCursorTile 0x021BFF30 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_SetCursorTile(int p, unsigned a, unsigned b);

void ZKNSEARCH_MAIN_DeselectCursor(int p, unsigned a, unsigned b)
{
    ZKNSEARCH_MAIN_SetCursorTile(p, b, 1);
    ZKNSEARCH_MAIN_SetCursorTile(p, a, 1);
}
