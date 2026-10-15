/*
 * function: ZKNSEARCH_MAIN_MoveCursor
 * address:  0x021C003C
 * packet:   pkt_ov210_021C003C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   ZKNSEARCH_MAIN_SetCursorTile 0x021BFF30 thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void ZKNSEARCH_MAIN_SetCursorTile(int p, unsigned a, unsigned b);

void ZKNSEARCH_MAIN_MoveCursor(int p, unsigned b)
{
    int *q = (int *)p;

    ZKNSEARCH_MAIN_SetCursorTile(p, CURSOR_MOVE_GetCurrent((struct Sound *)q[0xac]), 1);
    ZKNSEARCH_MAIN_SetCursorTile(p, b, 3);
    CURSOR_MOVE_SetCurrent((struct Sound *)q[0xac], (unsigned char)b);
}
