/*
 * function: ZKNSEARCH_RESULT_MoveRow3
 * address:  0x021C06AC
 * packet:   pkt_ov210_021C06AC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_MoveColumnActors 0x021BFBF8 thumb ov210
 *   ZKNSEARCH_MAIN_UpdateCursorActors 0x021BF728 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_MoveColumnActors(int p, int v);
typedef unsigned char  u8;
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *p, int a);

void ZKNSEARCH_RESULT_MoveRow3(int p, int v)
{
    ZKNSEARCH_MAIN_MoveColumnActors(p, (signed char)(-v));
    ZKNSEARCH_MAIN_UpdateCursorActors((u8 *)p, 1);
}
