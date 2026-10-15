/*
 * function: ZKNSEARCH_MAIN_UpdateCursor
 * address:  0x021C00D8
 * packet:   pkt_ov210_021C00D8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetCursorTile 0x021BFF30 thumb ov210
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_SetCursorTile(int p, unsigned a, unsigned b);
typedef unsigned char  u8;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);

void ZKNSEARCH_MAIN_UpdateCursor(int p, unsigned a, unsigned b)
{
    ZKNSEARCH_MAIN_SetCursorTile(p, b, 1);
    if (a == 7)
        CURSOR_MOVE_SetCurrent((struct Sound *)(((int *)p)[0xac]), (unsigned char)b);
}
