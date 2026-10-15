/*
 * function: ZKNSEARCH_MAIN_SelectCursor
 * address:  0x021C00B4
 * packet:   pkt_ov210_021C00B4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetCursorTile 0x021BFF30 thumb ov210
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_SetCursorTile(int p, unsigned a, unsigned b);
struct CodeIn;
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);

void ZKNSEARCH_MAIN_SelectCursor(int p, unsigned a, unsigned b)
{
    ZKNSEARCH_MAIN_SetCursorTile(p, b, 1);
    ZKNSEARCH_MAIN_SetCursorTile(p, a, 3);
    BLINK_PALANM_ResetPhase((struct CodeIn *)(((int *)p)[0xad]));
}
