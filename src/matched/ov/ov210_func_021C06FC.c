/*
 * function: ZKNSEARCH_RESULT_MoveRow4
 * address:  0x021C06FC
 * packet:   pkt_021C06FC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_MoveScrollActors  0x021BFCE4  thumb  ov210
 *   ZKNSEARCH_MAIN_UpdateCursorActors  0x021BF728  thumb  ov210
 */

extern void ZKNSEARCH_MAIN_MoveScrollActors(char *p, int dx);
typedef unsigned char  u8;
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *p, int a);

void ZKNSEARCH_RESULT_MoveRow4(int a, int b)
{
    ZKNSEARCH_MAIN_MoveScrollActors((char *)a, (signed char)(-b));
    ZKNSEARCH_MAIN_UpdateCursorActors((u8 *)a, 1);
}
