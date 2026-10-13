/*
 * function: OEKAKI_DrawLine
 * address:  0x02185C38
 * packet:   pkt_ov023_02185C38
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   OEKAKI_BlitBrush  0x02185BBC  thumb  ov023
 */

extern void OEKAKI_BlitBrush(int a0, int a1, int x, int y, int w, int h, int dx, int dy,
                          int mx, int my);

void OEKAKI_DrawLine(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d)
{
    int sx;
    int sy;
    int ex;
    int dx;
    int ey;
    int dy;
    int err;
    int step;

    sx = *px;
    sy = *py;
    ex = x1;
    ey = y1;
    if (c == 0 && d == 0) {
        *px = x1;
        *py = y1;
        return;
    }
    dx = x1 - sx;
    if (dx < 0)
        dx = -dx;
    dy = y1 - sy;
    if (dy < 0)
        dy = -dy;
    if (dx > dy) {
        if (sx > x1) {
            step = (sy > y1) ? 1 : -1;
            ex = sx;
            sx = x1;
            sy = y1;
        } else {
            step = (sy < y1) ? 1 : -1;
        }
        OEKAKI_BlitBrush(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        err = dx >> 1;
        for (sx++; sx <= ex; sx++) {
            err -= dy;
            if (err < 0) {
                err += dx;
                sy += step;
            }
            OEKAKI_BlitBrush(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        }
    } else {
        if (sy > y1) {
            step = (sx > x1) ? 1 : -1;
            ey = sy;
            sy = y1;
            sx = x1;
        } else {
            step = (sx < x1) ? 1 : -1;
        }
        OEKAKI_BlitBrush(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        err = dy >> 1;
        for (sy++; sy <= ey; sy++) {
            err -= dx;
            if (err < 0) {
                err += dy;
                sx += step;
            }
            OEKAKI_BlitBrush(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        }
    }
    *px = x1;
    *py = y1;
}
