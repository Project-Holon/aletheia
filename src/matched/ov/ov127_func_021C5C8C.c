/*
 * function: WF2DMAP_SCRDRAW_DrawTilesWrapped
 * address: 0x021C5C8C
 * packet: pkt_ov127_021C5C8C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD4 lane03: EXACT. Keys: width/height are int params (word prologue copy, raw in call 1);
 *   BG_SYS_DrawTileEx declared (u8 x5, void *, u8, u8, u32, u32) in this unit, so out[] (s16) is cast (u8) in call 2;
 *   mode is unsigned (int mode coalesced with the call temp and took the lowest slot); ox/oy are int;
 *   sy/y advance by (u8)n (the listing truncates n before both adds); u8 params for tx/ty in WF2DMAP_SCRDRAW_GetTileSource.
 * symbols:
 *   WF2DMAP_SCRDRAW_GetMode 0x021C5E14 thumb ov127
 *   WF2DMAP_SCRDRAW_GetTileSource 0x021C5E2C thumb ov127
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WF2DMAP_SCRDRAW_GetMode(unsigned, unsigned);
extern char *WF2DMAP_SCRDRAW_GetTileSource(char *p, u8 x, u8 y, unsigned mode, int w, int h, u16 *out);
extern void BG_SYS_DrawTileEx(u8, u8, u8, u8, u8, void *, u8, u8, u32, u32);
void WF2DMAP_SCRDRAW_DrawTilesWrapped(void *p, u8 layer, u8 x, u8 y, u8 w, u8 h, void *q, u8 sx, u8 sy, int width, int height)
{
    s16 out[2];
    int ox, oy;
    s8 hh, n;
    unsigned mode;
    s8 ccx, ww, cs, cx, m, tx, ty, cw, ccs;
    mode = WF2DMAP_SCRDRAW_GetMode(width, height);
    if (mode == 0) {
        BG_SYS_DrawTileEx(layer, x, y, w, h, q, sx, sy, width, height);
        return;
    }
    hh = h;
    if (hh <= 0) return;
    ww = w;
    cs = sx;
    cx = x;
    do {
        oy = sy % 32;
        if (oy + hh <= 32) {
            n = hh;
            hh = 0;
        } else {
            n = 32 - oy;
            hh = hh - n;
        }
        ty = sy / 32;
        cw = ww;
        ccs = cs;
        ccx = cx;
        while (cw > 0) {
            ox = ccs % 32;
            if (ox + cw <= 32) {
                m = cw;
                cw = 0;
            } else {
                m = 32 - ox;
                cw = cw - m;
            }
            tx = ccs / 32;
            BG_SYS_DrawTileEx(layer, ccx, y, m, n,
                WF2DMAP_SCRDRAW_GetTileSource(q, tx, ty, mode, width, height, (u16 *)out),
                ox, oy, (u8)out[0], (u8)out[1]);
            ccs = ccs + m;
            ccx = ccx + m;
        }
        sy = sy + (u8)n;
        y = y + (u8)n;
    } while (hh > 0);
}
