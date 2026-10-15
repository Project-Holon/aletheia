/*
 * function: VIEWER_MAIN_BlitRect
 * address:  0x021C5CF4
 * packet:   pkt_ov111_021C5CF4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 4x4 tile blit into an 8x8-tile layout, 24 tiles per row.
 * The `b skip` stubs are `n++; continue;` repeated in each rejection arm
 * (tail merging leaves a lone branch per arm). xx and yy declared at the top,
 * before j, k, n, give the image colours (xx r2, k r3, n r4).
 */
typedef unsigned char u8;
void VIEWER_MAIN_BlitRect(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel)
{
    int xx, yy;
    int j, k, n = 0;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            xx = x + k;
            yy = y + j;
            if (xx < 0 || yy < 0) {
                n++;
                continue;
            }
            if (xx >= w || yy >= h) {
                n++;
                continue;
            }
            if (mode == 1 && ((sel == 0 && xx >= 0x60) || (sel == 1 && xx <= 0x5f))) {
                n++;
                continue;
            }
            {
                int idx = xx % 8 + ((yy % 8) * 8 + ((yy / 8) * 24 + xx / 8) * 64);
                int c = src[n];
                if (c == 1) dst[idx] = 7;
                else if (c == 2) dst[idx] = 0;
            }
            n++;
        }
    }
}
