/*
 * function: ZKNSEARCH_MAIN_SetCursorTile
 * address:  0x021BFF30
 * packet:   pkt_ov210_021BFF30
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     CURSOR_MOVE_GetEntry takes (record, a); passing a as the second argument keeps r1 live,
 *           so the 0x2B0 offset lands in r2.
 *
 * symbols:
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb  arm9
 *   BG_SYS_FillTileMap  0x020413B0  arm  arm9
 */

typedef unsigned char u8;

extern void *CURSOR_MOVE_GetEntry(void **obj, unsigned int idx);
typedef unsigned int   u32;
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);

void ZKNSEARCH_MAIN_SetCursorTile(int p, unsigned int a, unsigned int b)
{
    u8 *t;
    int *q = (int *)p;

    if (a > 6)
        return;
    t = (u8 *)CURSOR_MOVE_GetEntry((void **)q[0xac], a);
    BG_SYS_FillTileMap(0, t[0], t[1], t[2], t[3], (u8)b);
    func_02041B6C(0);
}
